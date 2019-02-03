//============================================================================
// Name        : glMotorJuegosBase.cpp
// Author      : Francico Dominguez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <string>
#include <GL/glut.h>
#include "renderizable.h"
#include "cubo.h"
#include "escena.h"
#include "esfera.h"
#include "solido.h"
#include "planoY.h"
#include "planoX.h"
#include "planoZ.h"
#include "triangulo.h"
#include "modelo.h"
#include "juego.h"

using namespace std;

GLint ancho=400;

GLint alto=400;
int hazPerspectiva = 1;
GLfloat angle = 0.0;
GLfloat yaw = 0.0;
GLfloat roll = 0.0;
GLfloat pitch = 0.0;
void partida();

float posz, posx;
float distancia = 1;
float vel;
int puntos;
string Nombre;

Vector3D rojo(1, 0, 0), amarillo(1, 1, 0), verde(0, 1, 0), azul(0, 0, 1);

Escena e;
Solido *p;

Juego juego;
Nivel n;

void displayMe(void)
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

	posz = juego.getPosJugador().getZ();
	posx = juego.getPosJugador().getX();
	if (juego.getcamara()) {
		
		gluLookAt(2, 2, -2, 2, 0, 0.0, 0.0, 1.0, 0.0);
		glTranslatef(0, 0.0, -posz);
	}
	else {
		gluLookAt(0.0, 1, -1, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		glTranslatef(-posx, 0.0, -posz);
	}
	
    glRotatef(yaw  ,0.0,1.0,0.0);
    glRotatef(pitch,1.0,0.0,0.0);
    glRotatef(roll ,0.0,0.0,1.0);
    GLfloat lightpos[] = {5.0, 15., 5., 0.};
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    e.render();

    glutSwapBuffers();
    angle++;
}

void init (void) {
    glEnable (GL_DEPTH_TEST);
    glEnable (GL_LIGHTING);
    glEnable (GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor (0.0,0.0,0.0,0.0);
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0f, (GLfloat)width/(GLfloat)height, 1.0f, 200.0f);

    glMatrixMode(GL_MODELVIEW);
    ancho = width;
    alto = height;
}
float dt=0.01;
void idle()
{
    displayMe();
    e.update(dt);
	partida();
}

void keyPressed (unsigned char key, int x, int y) {
	x++;
	y++;
	
    switch(key)
    {
    case 'p':
    case 'P':
      yaw++;
      break;
	case 'a':
	case 'A':
		if (juego.getPosJugador().getX() < juego.getLimiteIzq()){
			
			juego.setPosJugador(juego.getPosJugador() + Vector3D(0.5, 0, 0));
			p->setP(p->getP() + Vector3D(0.25, 0, 0));
		}
		break;
	case 'd':
	case 'D':
		
		if (juego.getPosJugador().getX()>juego.getLimiteDer()){
			
			juego.setPosJugador(juego.getPosJugador() - Vector3D(0.5, 0, 0));
			p->setP(p->getP() - Vector3D(0.25, 0, 0));
		}
		break;
    case 'o':
    case 'O':
      yaw--;
      break;
    case 'i':
    case 'I':
      pitch++;
      break;
	case 't':
	case 'T':
		juego.setcamara(!juego.getcamara());
		break;
    case 'k':
    case 'K':
      pitch--;
      break;
    case 'u':
    case 'U':
      roll++;
      break;

    case 'j':
    case 'J':
      roll--;
      break;

    case 27:   // escape
      exit(0);
      break;
    }
}
int main(int argc, char** argv)
{
	//Menú
	vel = 0.4;
	juego = Juego();
	cout << "Bienvenido al Rolling Ultimate edition" << endl << endl;
	cout << "Utilice a y d para moverse de izquierda a derecha"<<endl;
	cout << "Para elegir la posición de la camara presione la tecla t"<<endl<<endl;

	cout << "Introduzca el nombre del jugador: "; getline(cin, Nombre);
	juego.IntroducirNombre(Nombre);
	cout << endl << endl;

	cout << "La velocidad depende de si ampliamos la pantalla o no, y del ordenador. " << endl;
	cout << "Aconsejamos la velocidad en 10 para pantalla pequeña y 70 para pantalla maximizada" << endl;
	cout << "Introduzca la dificultad del juego (valor entre 1 y 100): ";
	cin >> vel;
	cout << endl << endl;
	if (vel <= 100 && vel >= 1) {
		juego.setVelEsfera(vel/100);
	}

	

	
	juego.setInicioRender(0);

	//Creación esfera del jugador
	p = new Esfera(juego.getJugador().getPosJugador(), juego.getJugador().getSizeEsfera());
	p->setColor(azul);
	p->setV(Vector3D(0, 0, juego.getVelEsfera()));
	e.add(p);
	
	
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Teacup");
    init();
    glutDisplayFunc(displayMe);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses
    glutMainLoop();
    return 0;
}

float getRand(float max, float min = 0) {
	float n = max - min;
	int ir = rand() % 1000;
	return min + n*(float)ir / 1000;
}

void partida() {

	bool perder = e.resuelveColisiones();
	juego.setPerdidoJuego(perder);
	juego.setPosJugador(p->getP());

	if (juego.reiniciarNivel()) {
		p->setP(juego.getPosJugador());
		cout << endl << endl;
		cout << "Has perdido"<<endl;
		cout << "Puntuación actual: " <<distancia<< endl << endl;
		cout << "Lista de puntuaciones: " << endl;
		juego.IntroducirPuntuacion(to_string(distancia));
		juego.EscribirFichero();
		distancia = 0;
		juego.ImprimirPuntuaciones();
	}

	//Generar cubos en función de la distancia 
	if (juego.getPosJugador().getZ() > distancia) {
		distancia++;
		e.eliminaescena();
		


		//Genera el plano
		Solido *c;
		c = new PlanoY(-2);
		e.addLimite(c);

		//Modifica la posición inicial donde se generan cubos
		juego.setInicioRender(distancia-1);
		int contador = juego.getInicioRender() * 5;

		//Generar esfera
		if (vel <= 100 && vel >= 1) {
			juego.setVelEsfera(vel / 100);
		}
		p = new Esfera(juego.getJugador().getPosJugador(), juego.getJugador().getSizeEsfera());
		p->setColor(azul);
		p->setV(Vector3D(0, 0, juego.getVelEsfera()));
		e.add(p);

		//Generar cubos a partir de la posición inicial
	
		for (int j = juego.getInicioRender(); j < juego.getInicioRender() + 20; j++) {
			//Genera la pared izquierda
			Solido *m = new Cubo(Vector3D(0, 0, 1), 0.5);
			m->setColor(rojo);
			m->setP(Vector3D(5.5, 0, j));
			e.addSolido(m);

			//Genera cubos obstáculo
			for (int i = 0; i < 5; i++) {
				if (contador < juego.getVectorNivelSize()&&juego.getNivelPos(contador) == 1 ) {
					Solido *m = new Cubo(Vector3D(0, 0, 1), 0.5);
					m->setColor(Vector3D(getRand(1), getRand(1), getRand(1)));
					m->setP(Vector3D(i, 0, j));
					m->setV(Vector3D(0, 0, 0));
					e.addFijo(m);
					//cout << contador<<" ";
				}
				contador++;
			}
			if (distancia == 100) {
				cout << endl << endl;
				cout << "Has ganado"<<endl<<endl;
				juego.resetNivel();
				p->setP(juego.getPosJugador());
				cout << "Puntuación actual: 100" << endl << endl;
				cout << "Lista de puntuaciones: " << endl;

				juego.IntroducirPuntuacion(to_string(100));
				juego.EscribirFichero();
				juego.ImprimirPuntuaciones();
				distancia = 0;
			}
			//Genera la pared derecha
			Solido *r = new Cubo(Vector3D(0, 0, 1), 0.5);
			r->setP(Vector3D(-1, 0, j));
			r->setColor(rojo);
			e.addSolido(r);
		}
		
	}
}


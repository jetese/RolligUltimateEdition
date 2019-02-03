#pragma once


#ifndef JUEGO_H_
#define JUEGO_H_
#include <vector>
#include "vector3d.h"
#include "nivel.h"
#include "jugador.h"
#include "puntuacion.h"


class Juego {

	Nivel niv;
	Jugador jug;
	bool camara;
	Puntuacion	punt;

	public:
		Juego(){
			niv = Nivel();
			jug = Jugador();
			camara = true;
			punt = Puntuacion();
		}

		//NIVEL
		inline Nivel getNivel() { return niv; }
		
		inline void setNivel(int k[], int size){
			niv.setNivel(k, size);
		}

		inline int getNivelPos(int pos) {
			return niv.getNivel(pos);
		}

		inline vector<int> getVectorNivel() {
			return niv.getVectorNivel();
		}

		inline int getVectorNivelSize() {
			return niv.size();
		}

		inline bool getPerdidoJuego() {
			return niv.getPerdido();
		}

		inline void setPerdidoJuego(bool perder) {
			niv.setPerdido(perder);
		}

		inline Vector3D getDistCubos() { return niv.getDistCubos(); }
		inline void setDistCubos(Vector3D dist) {
			niv.setDistCubos(dist);
		}

		inline float getSizeCubo() { return niv.getSizeCubo(); }
		inline void setSizeCubo(float size) {
			niv.setSizeCubo(size);
		}

		inline void setLimites(float limIzq, float limDer) {
			niv.setLimites(limIzq, limDer);
		}

		inline float getLimiteIzq() { return niv.getLimiteIzq(); }
		inline float getLimiteDer() { return niv.getLimiteDer(); }

		inline int getContadorCubos() { return niv.getContadorCubos(); }
		inline void setContadorCubos(int valor) { 
			niv.setContadorCubos(valor); 
		}

		inline int getInicioRender() { return niv.getInicioRender(); }
		inline void setInicioRender(int valor) { 
			niv.setInicioRender(valor); 
		}

		//JUGADOR 

		inline Jugador getJugador() { return jug; }

		inline void setPosJugador(Vector3D pos){
			jug.setPosJugador(pos);
		}

		inline Vector3D getPosJugador() { return jug.getPosJugador();}

		inline float getSizeEsfera() { return jug.getSizeEsfera(); }
		inline void setSizeEsfera(float tamanio) {
			jug.setSizeEsfera(tamanio);
		}

		inline float getVelEsfera() { return jug.getVelEsfera(); }
		inline void setVelEsfera(float vel) {
			jug.setVelEsfera(vel);
		}

		bool reiniciarNivel() {
			if (niv.getPerdido()){
				jug = Jugador();
				return true;
			}
			return false;
		}
		void resetNivel() {
			jug = Jugador();
		}

		//Camara
		inline void setcamara(bool a) {
			camara = a;
		}
		inline bool getcamara() {
			return camara;
		}

		//Puntuación
		inline void IntroducirNombre(string a) {
			punt.IntroducirNombre(a);
		}
		inline string LeerNombre() {
			return punt.LeerNombre();
		}
		inline void IntroducirPuntuacion(string a) {
			punt.IntroducirPuntuacion(a);
		}
		inline string LeerPuntuacion() {
			return punt.LeerPuntuacion();
		}


		inline void EscribirFichero() {
			punt.EscribirFichero();
		}
		inline void ImprimirPuntuaciones() {
			punt.ImprimirPuntuaciones();
		}
	

};
#endif /* CUBO_H_ */

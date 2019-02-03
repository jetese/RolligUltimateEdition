#pragma once


#ifndef NIVEL_H_
#define NIVEL_H_
#include <vector>
#include "vector3d.h"
#include "planoX.h"
#include "planoY.h"
using namespace std;

class Nivel {
	bool hasperdido;
	vector<int> a;
	Vector3D distCubos;
	float sizeCubo;
	float limiteIzq, limiteDer;
	int inicioRender;
	int contadorCubos;
	
public:
	Nivel() {

		hasperdido = false;
		distCubos = Vector3D(1.01, 0, 1.01);
		sizeCubo = 0.5;
		limiteIzq = 4.5;
		limiteDer = -0.5;

		int k[] = {
			1,1,0,1,1,
			1,0,0,0,1,
			1,0,0,0,1,
			1,0,0,0,1,
			1,0,0,1,1,
			0,0,0,1,1,
			0,0,1,1,1,
			0,0,0,1,1,
			1,0,0,0,1,
			1,0,0,0,1,
			1,1,0,0,1,
			1,1,0,0,0,
			1,1,1,0,0,
			1,1,0,0,0,
			0,0,0,0,1,
			0,0,0,0,1,
			0,0,0,1,1,
			1,0,0,0,1,
			1,0,0,0,1,
			1,0,0,0,1,
			1,1,0,1,1,
			1,1,0,1,1,
			1,1,0,1,1,
			0,0,0,0,0,
			0,0,0,0,0,
			0,0,0,0,0,
			1,1,0,1,1,
			1,1,0,1,1,
			1,1,0,1,1,
			1,0,0,0,0,
			1,0,0,0,0,
			1,0,1,1,1,
			0,0,0,0,0,
			0,0,0,0,1,
			0,0,0,0,1,
			1,1,1,0,1,
			1,1,1,0,1,
			1,1,1,0,1,
			1,0,1,0,1,
			1,0,0,0,1,
			1,0,0,0,1,
			1,0,0,0,1,
			1,1,1,0,0,
			1,1,1,0,0,
			1,1,1,0,0,
			0,0,0,0,1,
			0,0,0,1,1,
			0,0,1,1,1,
			0,1,1,1,1,
			0,0,1,1,1,
			0,0,0,1,1,
			1,0,0,0,1,
			1,1,0,0,0,
			1,1,1,0,0,
			1,1,1,1,0,
			1,1,1,1,0,
			1,1,1,1,0,
			1,1,1,1,0,
			0,0,0,0,0,
			0,0,0,0,0,
			0,0,0,0,0,
			0,1,1,1,1,
			0,1,1,1,1,
			0,0,1,1,1,
			0,0,1,1,1,
			1,0,0,1,1,
			1,1,0,0,1,
			1,1,0,0,1,
			1,0,0,1,1,
			1,0,0,0,1,
			1,0,1,0,1,
			1,0,1,0,1,
			1,0,1,0,0,
			0,0,1,0,0,
			0,1,0,1,0,
			1,1,1,1,0,
			1,1,1,1,0,
			1,1,1,0,0,
			1,1,0,0,0,
			1,0,0,0,1,
			1,0,0,0,1,
			0,0,1,1,1,
			0,0,0,1,1,
			1,0,0,0,1,
			1,1,0,0,0,
			1,1,1,0,0,
			1,1,1,1,0,
			1,1,1,1,0,
			1,1,1,1,0,
			1,1,1,1,0,
			0,0,0,0,0,
			0,0,0,0,1,
			0,0,0,1,1,
			0,0,1,1,1,
			0,1,1,1,1,
			0,0,1,1,1,
			0,0,0,1,1,
			1,0,1,0,1,
			1,0,1,0,1,
			1,0,1,0,1,
			


			
		};
		for (int i = 0; i < 500; i++) {
			a.push_back(k[i]);
		}

	}

	inline void setPerdido(bool loose) {
		hasperdido = loose;
	}
	inline bool getPerdido() { return hasperdido; }

	inline void setNivel(int k[],int size) {
		for (int i = 0; i < size; i++) {
			a.push_back(k[i]);
		}
	}
	inline int getNivel(int pos) {
		return a[pos];
	}

	inline int size() {
		return a.size();
	}
	
	inline Vector3D getDistCubos() { return distCubos; }
	inline void setDistCubos(Vector3D dist){
		distCubos = dist;
	}

	inline float getSizeCubo() { return sizeCubo; }
	inline void setSizeCubo(float size) {
		sizeCubo = size;
	}

	inline void setLimites(float limIzq, float limDer) {
		limiteDer = limDer;
		limiteIzq = limIzq;
	}

	inline float getLimiteIzq(){ return limiteIzq; }
	inline float getLimiteDer() { return limiteDer; }

	inline vector<int> getVectorNivel() {
		return a;
	}

	inline int getContadorCubos() { return contadorCubos; }
	inline void setContadorCubos(int valor) { contadorCubos = valor;}

	inline int getInicioRender() { return inicioRender; }
	inline void setInicioRender(int valor) { inicioRender = valor; }

};

#endif /* CUBO_H_ */

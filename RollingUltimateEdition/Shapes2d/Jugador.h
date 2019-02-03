#pragma once

#ifndef JUGADOR_H_
#define JUGADOR_H_
#include <vector>
#include "vector3d.h"

class Jugador{
	Vector3D posJugador;
	float sizeEsfera;
	float velocidadEsfera;

	public:
		Jugador(){
			posJugador = Vector3D(2, 0, 0);
			sizeEsfera = 0.25;
			velocidadEsfera = 0.4;
		}
		inline Vector3D getPosJugador() { return posJugador; }
		inline void setPosJugador(Vector3D a) {
			posJugador = a;
		}
		inline float getSizeEsfera() { return sizeEsfera; }
		inline void setSizeEsfera(float tamanio){
			sizeEsfera = tamanio;
		}

		inline float getVelEsfera() { return velocidadEsfera; }
		inline void setVelEsfera(float vel) {
			velocidadEsfera = vel;
		}
};

#endif

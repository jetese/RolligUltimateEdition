#pragma once

#ifndef PUNTUACION_H_
#define PUNTUACION_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Puntuacion
{
	string Nombre;
	string Puntua;

public:
	inline void IntroducirNombre(string a) {
		Nombre = a;
	}
	inline string LeerNombre() {
		return Nombre;
	}
	inline void IntroducirPuntuacion(string a) {
		Puntua = a;
	}
	inline string LeerPuntuacion() {
		return Puntua;
	}
	

	inline void EscribirFichero() {
		string linea;
		ofstream myfile("puntuaciones.txt", ofstream::app);
		if (myfile.is_open()) {
			
			myfile << Nombre;
			myfile << ": ";
			myfile << Puntua;
			myfile << "\n";
			myfile.close();

		}
		else {
			cout << "Unable to open file";
		}
	}
	inline void ImprimirPuntuacionActual() {
		cout << Nombre << ": " << Puntua << endl;
	}
	inline void ImprimirPuntuaciones() {
		string line;
		ifstream myfile("puntuaciones.txt");
		if (myfile.is_open()) {
			while (getline(myfile, line))
				cout << line << "\n";
			myfile.close();

		}
		else {
			cout << "Unable to open file";
		}
	}


};

#endif


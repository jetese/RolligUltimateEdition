#pragma once
#ifndef MAPA_H_
#define MAPA_H_
#include <vector>
#include "solido.h"

class Mapa {
	vector<Solido*> solidos;
public:
	Mapa();
	void add(Solido *s) {
		solidos.push_back(s);
	}
	// only render
	void addSolido(Solido *s) {
		solidos.push_back(s);
	}
};

#endif /* MAPA_H_ */
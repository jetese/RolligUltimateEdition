/*
 * Escena.h
 *
 *  Created on: Oct 5, 2015
 *      Author: francisco
 */

#ifndef ESCENA_H_
#define ESCENA_H_
#include <vector>
#include "solido.h"

class Escena: public Solido {
	vector<Solido*> solidos;
	vector<Solido*> moviles;
	vector<Solido*> colisionables;
	vector<Solido*> limites;
public:
	Escena();
	virtual ~Escena();
	void add(Solido *s){
		solidos.push_back(s);
		moviles.push_back(s);
		colisionables.push_back(s);
	}
	// only render
	void addSolido(Solido *s){
		solidos.push_back(s);
	}
	// render and collision not move
	void addFijo(Solido *s){
		solidos.push_back(s);
		colisionables.push_back(s);
	}
	void addLimite(Solido *s){
		solidos.push_back(s);
		limites.push_back(s);
	}
	inline void render(){
		for(Solido *r:solidos)
			r->render();
	}
	inline void update(float dt){
		for(Solido *s:moviles)
			s->update(dt);
	}
	inline void eliminaescena() {
		solidos.clear();
		colisionables.clear();
		moviles.clear();
		
	}
	inline bool resuelveColisiones(){
		/*for(Solido *l:limites){
			for(Solido *s:moviles){
				if(l->colision(s)){
					return true;
					
				}
			}
		}*/
		for(Solido *m:moviles){
			for(Solido *c:colisionables){
				if(c!=m){
					if(m->colision(c)){
						return true;
					}
				}
			}
		}
		return false;
	}
};

#endif /* ESCENA_H_ */

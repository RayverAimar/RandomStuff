#include "Personaje.h"

Personaje::Personaje() {
	avatar = 0;
	posicion = nullptr;
	posicion = new int[2];
	posicion[0] = 8;
	posicion[1] = 0;
}

Personaje::~Personaje(){
	//if(posicion != nullptr)
	delete[] posicion;
	//posicion = nullptr
}
//
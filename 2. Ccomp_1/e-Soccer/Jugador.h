#pragma once
#include "Personaje.h"

class Jugador : public Personaje {
public:
	int id;
	//Punto2D posicion;
	int* items, goles, tiempo_poder;
	bool* estado_activo;
	//char avatar;
	//int goles;
	Jugador();
	~Jugador();
	void ingresar_item();
	
};
#pragma once
#include "Personaje.h"

class Pelota :public Personaje{
public:
	int direccion_x, direccion_y, mover;
	Pelota();
	void movimiento();
};

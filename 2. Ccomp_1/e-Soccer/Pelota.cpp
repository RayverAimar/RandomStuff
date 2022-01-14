#include "Pelota.h"

Pelota::Pelota() {
	avatar = 0;
	posicion[1] = 5;
	posicion[0] = 5;
	direccion_x = 1;
	direccion_y = 0;
	mover = 0;
}
void Pelota::movimiento() {
	posicion[1] += direccion_x;
	posicion[0] += direccion_y;
}
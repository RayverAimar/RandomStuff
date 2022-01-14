#pragma once
#include <iostream>
#include "Pista.h"
#include <ctime>
void bienvenida();
void menu(Pista& pista, clock_t tiempo_actual, clock_t tiempo_anterior, int tiempo_corriendo, int dt, int tiempo_prorroga, bool prorroga);

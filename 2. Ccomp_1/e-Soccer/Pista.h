#pragma once
#include "Pelota.h"
#include "Jugador.h"
void ocultarCursor();
class Pista {
private:
	char **matriz;
public:
	Jugador player_1, player_2;
	Pelota balon;
	int ancho, largo;
	bool game_over;
	bool empate;
	char tecla;
	
	Pista();
	
	void actualizar();
	void gestor_items(int dt, int &tiempo_corriendo);
	void congelar_porteria(Jugador &player, int dt);
	void invertir_movimiento(Jugador &player, int dt);
	void tiempo_extra(Jugador &player, int &tiempo_corriendo);
	void tiro_rapido(Jugador &player);
	void balon_invisible(Jugador &player);
	void invertir_balon(Jugador &player);
	void congelar_rival(Jugador &player, int dt);
	void limites(Jugador &player);
	void rebote_lateral();
	void redireccion();
	void mov_balon();
	void dibujar(int &tiempo_corriendo, int &tiempo_prorroga);
	void gol();
	void aftergame();
	bool empate_goles();
	void prorroga(int &tiempo_corriendo);
	~Pista();
};
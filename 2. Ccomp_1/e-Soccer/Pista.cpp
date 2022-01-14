#include "Pista.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctime>
#include <conio.h>
#include <Windows.h>



using namespace std;

constexpr auto UP = 72;
constexpr auto DOWN = 80;
constexpr auto RIGHT = 77;
constexpr auto LEFT = 75;
constexpr auto ESC = 27;

void ocultarCursor() {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 50;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hcon, &cci);
}
Pista::Pista() {
    player_1.avatar = '@';
    player_2.avatar = '#';
    balon.avatar = 'O';
    player_1.id = 1;
    player_2.id = 2;
    player_1.ingresar_item();
    player_2.ingresar_item();
    player_2.posicion[1] = 44;
    player_1.posicion[1] = 1;
    ancho = 15;
    largo = 45;
    matriz = nullptr;
    matriz = new char*[ancho];
    for (int i = 0; i < ancho; i++) {
        matriz[i] = new char[largo];
    }
    game_over = false;
    empate = false;
    tecla = NULL;
}

Pista::~Pista() {
    for (int i = 0; i < ancho; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void Pista::congelar_porteria(Jugador& player, int dt) {
    player.tiempo_poder += dt;
    if (player.tiempo_poder < 5000) {
        if (player.id == 1) {
            if (balon.posicion[1] == 0) {
                balon.direccion_x *= -1;
                balon.direccion_y *= -1;
            }
        }
        else if (player.id == 2) {
            if (balon.posicion[1] == largo-1) {
                balon.direccion_x *= -1;
                balon.direccion_y *= -1;
            }
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            if (player.items[i] == 7) {
                player.estado_activo[i] = false;
                player.items[i] = 8;
            }
        }
        player.tiempo_poder = 0;
    }
}
void Pista::invertir_movimiento(Jugador& player, int dt) {//FUNCIONA CORRECTAMENTE
    player.tiempo_poder += dt;
    if (player.tiempo_poder < 5000) {
        if (player.id == 1) {
            if (tecla == 'i') {
                player_2.posicion[0] += 2;
                tecla = ' ';
            }
            if (tecla == 'k') {
                player_2.posicion[0] -= 2;
                tecla = ' ';    
            }
            cout << "Movimento del jugador invertido" << endl;
        }
        else if (player.id == 2) {
            if (tecla == 'w') {
                player_1.posicion[0] += 2;
                tecla = ' ';
            }
            if (tecla == 's') {
                player_1.posicion[0] -= 2;
                tecla = ' ';
            }
            cout << "Movimento del jugador invertido" << endl;

        }
    }
    else{
        for (int i = 0; i < 3; i++) {
            if (player.items[i] == 2) {
                player.estado_activo[i] = false;
                player.items[i] = 8;
            }
        }
        player.tiempo_poder = 0;
    }
}
void Pista::tiempo_extra(Jugador& player, int &tiempo_corriendo) { //FUNCIONA CORRECTAMENTE
    //Aumenta el partido en 15 segundos
    tiempo_corriendo -= 15000;
    for (int i = 0; i < 3; i++) {
        if (player.items[i] == 3) {
            player.estado_activo[i] = false;
            player.items[i] = 8;
        }
    }
}
void Pista::tiro_rapido(Jugador& player) { //FUNCIONA CORRECTAMENTE
    bool endif = false;
    if (!endif) {
        if (player.id == 1) {
            if (balon.posicion[1] < largo-2) {
                balon.posicion[1] += 2;
            }
            else {
                endif = true;
                for (int i = 0; i < 3; i++) {
                    if (player_1.items[i] == 4) {
                        player_1.estado_activo[i] = false;
                        player_1.items[i] = 8;
                    }
                }
            }
        }
        else if (player.id == 2) {
            if (balon.posicion[1] > 2) {
                balon.posicion[1] -= 2;
            }
            else {
                endif = true;
                for (int i = 0; i < 3; i++) {
                    if (player_2.items[i] == 4) {
                        player_2.estado_activo[i] = false;
                        player_2.items[i] = 8;
                    }
                }
            }
        }
    }
}
void Pista::balon_invisible(Jugador &player) { //FUNCIONA CORRECTAMENTE
    bool endif = false;
    if (!endif) {
        if (player.id == 1) {
            if (balon.posicion[1] < largo-2) {
                balon.avatar = ' ';
            }
            else {
                endif = true;
                balon.avatar = 'O';
                for (int i = 0; i < 3; i++) {
                    if (player_1.items[i] == 5) {
                        player_1.estado_activo[i] = false;
                        player_1.items[i] = 8;
                    }
                }
            }
        }
        else if (player.id == 2) {
            if (balon.posicion[1] > 2) {
                balon.avatar = ' '; 
            }
            else {
                endif = true;
                balon.avatar = 'O';
                for (int i = 0; i < 3; i++) {
                    if (player_2.items[i] == 5) {
                        player_2.estado_activo[i] = false;
                        player_2.items[i] = 8;
                    }
                }
            }
        }
    }
}
void Pista::invertir_balon(Jugador &player) { //FUNCIONA CORRECTAMENTE
    balon.direccion_x *= -1;
    for (int i = 0; i < 3; i++) {
        if (player.items[i] == 6) {
            player.estado_activo[i] = false;
            player.items[i] = 8;
        }
    }
}
void Pista::congelar_rival(Jugador& player, int dt) { //FUNCIONA CORRECTAMENTE
    player.tiempo_poder += dt;
    if (player.tiempo_poder < 5000) {
        if (player.id == 1) {
            if (tecla == 'i') {
                player_2.posicion[0] += 1;
                tecla = ' ';
            }
            if (tecla == 'k') {
                player_2.posicion[0] -= 1;
                tecla = ' ';
            }
        }
        else if (player.id == 2) {
            if (tecla == 'w') {
                player_1.posicion[0] += 1;
                tecla = ' ';
            }
            if (tecla == 's') {
                player_1.posicion[0] -= 1;
                tecla = ' ';
            }
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            if (player.items[i] == 1) {
                player.estado_activo[i] = false;
                player.items[i] = 8;
            }
        }
        player.tiempo_poder = 0;
    }
}
void Pista::rebote_lateral() { //FUNCIONA CORRECTAMENTE
    if (balon.posicion[0] == 0) {
        balon.direccion_y *= -1;
    }
    if (balon.posicion[0] == 14) {
        balon.direccion_y *= -1;
    }
}
void Pista::actualizar() {
    if (_kbhit()) {
        tecla = _getch(); //movimiento de jugador

        if (tecla == 'w') {
            player_1.posicion[0] -= 1;
        }
        if (tecla == 's') {
            player_1.posicion[0] += 1;
        }
        if (tecla == 'i') {
            player_2.posicion[0] -= 1;
        }
        if (tecla == 'k') {
            player_2.posicion[0] += 1;
        }
        if (tecla == 'x') { //Comandos para el player 1
            player_1.estado_activo[0] = true;
        }
        if (tecla == 'c') {
            player_1.estado_activo[1] = true;
        }
        if (tecla == 'v') {
            player_1.estado_activo[2] = true;
        }
        if (tecla == 'b') { //Comandos para el player 2
            player_2.estado_activo[0] = true;
        }
        if (tecla == 'n') {
            player_2.estado_activo[1] = true;
        }
        if (tecla == 'm') {
            player_2.estado_activo[2] = true;
        }
        if (tecla == ESC) {
            game_over = true;
        }
    }
}

void Pista::gestor_items(int dt, int &tiempo_corriendo) {
    for (int i = 0; i < 3; i++) { 
        if (player_1.estado_activo[i]) {
            if (player_1.items[i] == 1) {
                congelar_rival(player_1, dt);
            }
            else if (player_1.items[i] == 2) {
                invertir_movimiento(player_1, dt);
            }
            else if (player_1.items[i] == 3) {
                tiempo_extra(player_1, tiempo_corriendo);
            }
            else if (player_1.items[i] == 4) {
                tiro_rapido(player_1);
            }
            else if (player_1.items[i] == 5) {
                balon_invisible(player_1);
            }
            else if (player_1.items[i] == 6) {
                invertir_balon(player_1);
            }
            else if (player_1.items[i] == 7) {
                congelar_porteria(player_1, dt);
            }
        }
        if (player_2.estado_activo[i]) {
            if (player_2.items[i] == 1) {
                congelar_rival(player_2, dt);
            }
            else if (player_2.items[i] == 2) {
                invertir_movimiento(player_2, dt);
                }
            else if (player_2.items[i] == 3) {
                tiempo_extra(player_2, tiempo_corriendo); //tiempo_corriendo
            }
            else if (player_2.items[i] == 4) {
                tiro_rapido(player_2);
            }
            else if (player_2.items[i] == 5) {
                balon_invisible(player_2);
            }
            else if (player_2.items[i] == 6) {
                invertir_balon(player_2);
            }
            else if (player_2.items[i] == 7) {
                congelar_porteria(player_2, dt);
            }
        }
    }
}
void Pista::limites(Jugador &player) {
    if (player.id == 1) {
        if (player_1.posicion[0] < 0) {
            player_1.posicion[0] += 1;
        }

        if (player_1.posicion[0] > ancho-1) {
            player_1.posicion[0] -= 1;
        }
    }
    else {
        if (player_2.posicion[0] < 0) {
            player_2.posicion[0] += 1;
        }

        if (player_2.posicion[0] > ancho-1) {
            player_2.posicion[0] -= 1;
        }
    }
}

void Pista::gol() {
    if (balon.posicion[1] == -1) {
        balon.posicion[1] = largo/2;
        balon.posicion[0] = ancho/2;
        balon.direccion_x = -1;
        balon.direccion_y = 0;
        player_2.goles += 1;
        //cout << "El jugador 2 acaba de meter un gol! Tiene: " << player2.goles << " goles" << endl;
    }
    if (balon.posicion[1] == largo) {
        balon.posicion[1] = largo/2;
        balon.posicion[0] = ancho/2;
        balon.direccion_x = 1;
        balon.direccion_y = 0;
        player_1.goles += 1;
        //cout << "El jugador 1 acaba de meter un gol! Tiene: " << player1.goles << " goles" << endl;
    }
}
void Pista::redireccion() { //funcion para cambiar la posicion del balon una vez alcanzada la mitad de la cancha
    srand((unsigned int)time(NULL));
    if (balon.posicion[1] == (largo/2)) {
        balon.posicion[0] = rand() % ancho;
    }
}
void Pista::mov_balon() { // Cambio de dirección del balón cada que colisiona con algun jugador
    if (balon.posicion[1] == player_1.posicion[1] + 1  || balon.posicion[1] == player_1.posicion[1]) {
        if (balon.posicion[0] == player_1.posicion[0]) {
            balon.direccion_x = 1;
            srand((unsigned int)time(NULL));
            balon.direccion_y = rand() % 2; // valor entre 0 y 1
            //cout << "balon.direccion_y : " << balon.direccion_y << endl;
            balon.mover = rand() % 2 + 1; // valor entre  1 y 2
            balon.direccion_y *= int(pow(-1,balon.mover));
            //cout << "balon.mover : " << balon.mover << endl;
            //cout << "balon.direccion_y : "<<balon.direccion_y << endl;
            
        }
    }
    if (balon.posicion[1] == player_2.posicion[1] - 1 || balon.posicion[1] == player_2.posicion[1]) {
        if (balon.posicion[0] == player_2.posicion[0]) {
            balon.direccion_x = -1;
            srand((unsigned int)time(NULL));
            balon.direccion_y = rand() % 2; // valor entre 0 y 1
            //cout << "balon.direccion_y : " << balon.direccion_y << endl;
            balon.mover = rand() % 2 + 1; // valor entre  1 y 2
            balon.direccion_y *=  (int(pow(-1, balon.mover)));
            //cout << "balon.mover : " << balon.mover << endl;
            //cout << "balon.direccion_y : " << balon.direccion_y << endl;
        }
    }
}
bool Pista::empate_goles() {
    if (player_1.goles == player_2.goles) {
        empate = true;
        return empate;
    }
    else {
        empate = false;
        return empate;
    }
}
void Pista::prorroga(int &tiempo_corriendo) {
    tiempo_corriendo -= 30000;
}
void Pista::aftergame() {
    if (player_1.goles < player_2.goles) {
        cout << "Gano el jugador 2!" << endl;
    }
    else if (player_2.goles < player_1.goles) {
        cout << "Gano el jugador 1!" << endl;
    }
    else {
        cout << "Hubo un empate!" << endl;
    }
    cout << "Resultado: " << endl;
    cout << "Jugador 1 --> " << player_1.goles << " : ";
    cout <<player_2.goles<<" <--Jugador 2" << endl;
}
void Pista::dibujar(int &tiempo_corriendo, int &tiempo_prorroga) { 
    ocultarCursor();
    limites(player_1);
    limites(player_2);
    redireccion();
    mov_balon(); //Error
    rebote_lateral();
    balon.movimiento();
    gol();
    cout << "\n                     " << float(tiempo_corriendo)/1000 + float(tiempo_prorroga) /1000<< endl;
    cout << "\n       Jugador 1 --> " << player_1.goles << " : ";
    cout << player_2.goles << " <--Jugador 2" << endl;
    cout << " _____________________________________________" << endl;
    for (int i = 0; i < ancho; i++) {
        for (int j = 0; j < largo; j++) {
            matriz[i][j] = ' ';
            if (i == ancho-1) {
                matriz[i][j] = '_';
            }
            if (j == (largo/2)) {
                matriz[i][j] = '|';
            }
            if (player_1.posicion[0] == i) {
                if (player_1.posicion[1] == j) {
                    matriz[i][j] = player_1.avatar;
                }
            }
            if (player_2.posicion[0] == i) {
                if (player_2.posicion[1] == j) {
                    matriz[i][j] = player_2.avatar;
                }
            }
            if (balon.posicion[0] == i) {
                if (balon.posicion[1] == j) {
                    matriz[i][j] = balon.avatar;
                }
            }
            if (j == 0) {
                cout << "|" << matriz[i][j];
            }
            else if (j == largo-1) {
                cout << matriz[i][j] << "|";
            }
            else {
                cout << matriz[i][j];
            }
        }
        cout << endl;
    }
    
}
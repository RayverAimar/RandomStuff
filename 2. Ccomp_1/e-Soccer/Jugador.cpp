#include <iostream>
#include "Jugador.h"

using namespace std;

Jugador::Jugador() {
    id = 0;
    tiempo_poder = 0;
    avatar = NULL;
    items = nullptr;
    estado_activo = nullptr;
    items = new int[3];
    estado_activo = new bool[3];
    for (int i = 0; i < 3; i++) {
        estado_activo[i] = false;
    }
    goles = 0;
}

void Jugador::ingresar_item() {
    int identificador, contador = 0;
    while (contador < 3) {
        cout <<"Jugador "<< id <<" que item desea adquirir? " << endl;
        cout << "\n1. Congelar rival \n2. Invertir movimiento rival \n3. Tiempo extra\n4. Tiro Rapido \n5. Balon invisible\n6. Invertir balon\n7. Congelar porteria" << endl;
        cin >> identificador;
        items[contador] = identificador;
        contador++;
        system("cls");
        cout << "Item ingresado: " << identificador << endl;
    }
    system("cls");
}

Jugador::~Jugador() {
    delete[] items;
    delete[] estado_activo;
}

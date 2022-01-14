#include "Menu.h"
#include <iostream>
using namespace std;
void bienvenida() {
    cout << "\n                             BIENVENIDO A:   \n" << endl;
    cout << "EEEEEEEEEE  FFFFFFFFFFF       OOOOO0            OOOOO0       TTTTTTTTTTTTTTT" << endl;
    cout << "EEE         FFF             O0      0O        O0      0O     TT    TTT    TT" << endl;
    cout << "EEE         FFF            O0        0O      O0        0O          TTT" << endl;
    cout << "EEE         FFF           O0          0O    O0          0O         TTT" << endl;
    cout << "EEEEEEEEEE  FFFFFFFFFFF   O0          0O    O0          0O         TTT" << endl;
    cout << "EEE         FFF            O0        0O      O0        0O          TTT" << endl;
    cout << "EEE         FFF             O0      0O        O0      0O           TTT" << endl;
    cout << "EEEEEEEEEE  FFF               OOOOO0            OOOOO0             TTT\n"<<endl;
    system("pause");
}
void menu(Pista& pista, clock_t tiempo_actual, clock_t tiempo_anterior, int tiempo_corriendo, int dt, int tiempo_prorroga, bool prorroga) {
    while (!pista.game_over) {
        tiempo_actual = clock();
        dt = tiempo_actual - tiempo_anterior;
        tiempo_anterior = tiempo_actual;
        tiempo_corriendo += dt;
        if (prorroga) {
            tiempo_prorroga = 30000;
        }
        if (tiempo_corriendo > 90000) {
            if (!prorroga) {
                if (pista.empate_goles()) {
                    pista.prorroga(tiempo_corriendo);
                    prorroga = true;
                }
                else {
                    pista.game_over = true;
                }
            }
            else {
                    pista.game_over = true;
                }
        }
        pista.actualizar();
        pista.gestor_items(dt, tiempo_corriendo);
        system("cls");
        pista.dibujar(tiempo_corriendo, tiempo_prorroga);
    }
}
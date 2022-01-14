#include "Menu.h"

int main(){
    Pista pista;
    bienvenida();
    menu(pista, 0, clock(), 0, 0, 0, 0);
    pista.aftergame();
    return 0;
}
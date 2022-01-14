#include "Item.h"

Item::Item() {
    ID = 0;
    estado_activo = false;
}
Item::Item(int identificador) {
    ID = identificador;
    estado_activo = false;
}
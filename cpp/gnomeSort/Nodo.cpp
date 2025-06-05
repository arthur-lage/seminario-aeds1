#include "Nodo.hpp"

void Nodo::trocarRegistros(Nodo* a, Nodo* b) {
    Registro temp = a->registro;
    a->registro = b->registro;
    b->registro = temp;
}
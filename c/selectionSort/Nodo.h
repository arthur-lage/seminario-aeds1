#ifndef NODO_H
#define NODO_H

#include "Registro.h"

typedef struct Nodo Nodo;

struct Nodo {
    Registro registro;
    Nodo* prox;
};

void trocarRegistros(Nodo *a, Nodo *b) {
    Registro temp = a->registro;
    a->registro = b->registro;
    b->registro = temp;
}

#endif
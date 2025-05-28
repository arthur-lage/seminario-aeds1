#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "Lista.h"
#include "Fila.h"
#include "Pilha.h"
#include "Registro.h"
#include "Nodo.h"

#include <stdio.h>

void selectionSort(Lista* l) {
    if (l == NULL || l->inicio == NULL || l->inicio->prox == NULL) return;

    Nodo *i, *j, *min;

    for (i = l->inicio; i->prox != NULL; i = i->prox) {
        min = i;
        
        for (j = i->prox; j != NULL; j = j->prox) {
            if (j->registro.timestamp < min->registro.timestamp) {
                min = j;
            }
        }

        if (min != i) trocarRegistros(i, min);
    }
}

void selectionSortFila(Fila* f) {
    if (f == NULL || f->frente == NULL || f->frente->prox == NULL) return; 

    Nodo *i, *j, *min;

    for (i = f->frente; i->prox != NULL; i = i->prox) {
        min = i;
        
        for (j = i->prox; j != NULL; j = j->prox) {
            if (j->registro.timestamp < min->registro.timestamp) {
                min = j;
            }
        }

        if (min != i) trocarRegistros(i, min);
    }
}

void selectionSortPilha(Pilha *p) {
    if (p == NULL || p->topo == NULL || p->topo->prox == NULL) return;

    Nodo *i, *j, *min;

    for (i = p->topo; i->prox != NULL; i = i->prox) {
        min = i;
        
        for (j = i->prox; j != NULL; j = j->prox) {
            if (j->registro.timestamp < min->registro.timestamp) {
                min = j;
            }
        }

        if (min != i) trocarRegistros(i, min);
    }
}

#endif
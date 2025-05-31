#ifndef GNOME_SORT_H
#define GNOME_SORT_H

#include "Lista.h"
#include "Fila.h"
#include "Pilha.h"
#include "ListaVetor.h"
#include "Registro.h"
#include "Nodo.h"

#include <stdio.h>

void gnomeSortLista(Lista *l) {
    if (l == NULL || l->inicio == NULL || l->inicio->prox == NULL) return;

    Nodo* i = l->inicio;

    while (i != NULL && i->prox != NULL) {
        if (i->registro.timestamp <= i->prox->registro.timestamp) {
            i = i->prox;
        } else {
            trocarRegistros(i, i->prox);
            if (i != l->inicio) {
                i = i->ant;
            }
        }
    }
}
void gnomeSortFila(Fila* f) {
    if (f == NULL || f->frente == NULL || f->frente->prox == NULL) return;

    Nodo* i = f->frente;

    while (i != NULL && i->prox != NULL) {
        if (i->registro.timestamp <= i->prox->registro.timestamp) {
            i = i->prox;
        } else {
            trocarRegistros(i, i->prox);
            if (i != f->frente) {
                i = i->ant;
            }
        }
    }
}

void gnomeSortPilha(Pilha *p) {
    if (p == NULL || p->topo == NULL || p->topo->prox == NULL) return;

    Nodo* i = p->topo;

    while (i != NULL && i->prox != NULL) {
        if (i->registro.timestamp <= i->prox->registro.timestamp) {
            i = i->prox;
        } else {
            trocarRegistros(i, i->prox);
            if (i != p->topo) {
                i = i->ant;
            }
        }
    }
}
void gnomeSortListaVetor(ListaVetor *L) {
    if (listaVaziaVetor(L) || L->ultimo == 1) return;

    int pos = 0;
    
    while (pos < L->ultimo - 1) {
        if (L->lista[pos].timestamp <= L->lista[pos + 1].timestamp) {
            pos++;
        } else {
            Registro temp = L->lista[pos];
            L->lista[pos] = L->lista[pos + 1];
            L->lista[pos + 1] = temp;
            
            if (pos > 0) {
                pos--;
            }
        }
    }
}
#endif
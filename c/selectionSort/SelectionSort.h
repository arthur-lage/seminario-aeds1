#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "Lista.h"
#include "Fila.h"
#include "Pilha.h"
#include "ListaVetor.h"
#include "PilhaVetor.h"
#include "FilaVetor.h"
#include "Registro.h"
#include "Nodo.h"

#include <stdio.h>

// Selection Sort para Lista (lista encadeada)
void selectionSortLista(Lista *l) {
    if (l == NULL || l->inicio == NULL) return;
    
    Nodo *i = l->inicio;
    while (i != NULL) {
        Nodo *min = i;
        Nodo *j = i->prox;
        
        while (j != NULL) {
            if (j->registro.timestamp < min->registro.timestamp)
                min = j;
            j = j->prox;
        }
        
        // Troca os registros
        Registro temp = i->registro;
        i->registro = min->registro;
        min->registro = temp;
        
        i = i->prox;
    }
}

// Selection Sort para Fila (lista encadeada)
void selectionSortFila(Fila *f) {
    if (f == NULL || f->frente == NULL) return;
    
    Nodo *i = f->frente;
    while (i != NULL) {
        Nodo *min = i;
        Nodo *j = i->prox;
        
        while (j != NULL) {
            if (j->registro.timestamp < min->registro.timestamp)
                min = j;
            j = j->prox;
        }
        
        // Troca os registros
        Registro temp = i->registro;
        i->registro = min->registro;
        min->registro = temp;
        
        i = i->prox;
    }
}

// Selection Sort para Pilha (lista encadeada)
void selectionSortPilha(Pilha *p) {
    if (p == NULL || p->topo == NULL) return;
    
    Nodo *i = p->topo;
    while (i != NULL) {
        Nodo *min = i;
        Nodo *j = i->prox;
        
        while (j != NULL) {
            if (j->registro.timestamp < min->registro.timestamp)
                min = j;
            j = j->prox;
        }
        
        // Troca os registros
        Registro temp = i->registro;
        i->registro = min->registro;
        min->registro = temp;
        
        i = i->prox;
    }
}

// Selection Sort para ListaVetor (array)
void selectionSortListaVetor(ListaVetor *L) {
    if (L == NULL || listaVaziaVetor(L)) return;
    
    for (int i = L->primeiro; i < L->ultimo; i++) {
        int min = i;
        for (int j = i + 1; j < L->ultimo; j++) {
            if (L->lista[j].timestamp < L->lista[min].timestamp)
                min = j;
        }
        
        // Troca os registros
        Registro temp = L->lista[i];
        L->lista[i] = L->lista[min];
        L->lista[min] = temp;
    }
}

// Selection Sort para PilhaVetor (array)
void selectionSortPilhaVetor(PilhaVetor *P) {
    if (P == NULL || pilhaVaziaVetor(P)) return;
    
    for (int i = 0; i <= P->topo; i++) {
        int min = i;
        for (int j = i + 1; j <= P->topo; j++) {
            if (P->stack[j].timestamp < P->stack[min].timestamp)
                min = j;
        }
        
        // Troca os registros
        Registro temp = P->stack[i];
        P->stack[i] = P->stack[min];
        P->stack[min] = temp;
    }
}

// Selection Sort para FilaVetor (array circular)
void selectionSortFilaVetor(FilaVetor *Q) {
    if (Q == NULL || filaVaziaVetor(Q)) return;
    
    int tamanho = (Q->fundo - Q->frente + MAXTAM) % MAXTAM;
    for (int i = 0; i < tamanho - 1; i++) {
        int min = i;
        for (int j = i + 1; j < tamanho; j++) {
            int idx_j = (Q->frente + j) % MAXTAM;
            int idx_min = (Q->frente + min) % MAXTAM;
            if (Q->queue[idx_j].timestamp < Q->queue[idx_min].timestamp)
                min = j;
        }
        
        // Troca os registros
        int idx_i = (Q->frente + i) % MAXTAM;
        int idx_min = (Q->frente + min) % MAXTAM;
        Registro temp = Q->queue[idx_i];
        Q->queue[idx_i] = Q->queue[idx_min];
        Q->queue[idx_min] = temp;
    }
}

#endif
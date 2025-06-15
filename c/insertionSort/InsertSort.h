#ifndef INSERT_SORT_H
#define INSERT_SORT_H

#include "Lista.h"
#include "Fila.h"
#include "Pilha.h"
#include "ListaVetor.h"
#include "PilhaVetor.h"
#include "FilaVetor.h"
#include "Registro.h"
#include "Nodo.h"

#include <stdio.h>

// Insertion Sort para Lista (lista encadeada)
void insertionSortLista(Lista *l) {
    if (l == NULL || l->inicio == NULL || l->inicio->prox == NULL) return;
    
    Nodo *i = l->inicio->prox;
    
    while (i != NULL) {
        Nodo *j = i;
        Registro chave = i->registro;
        
        while (j != l->inicio && j->ant->registro.timestamp > chave.timestamp) {
            j->registro = j->ant->registro;
            j = j->ant;
        }
        j->registro = chave;
        i = i->prox;
    }
}

// Insertion Sort para Fila (lista encadeada)
void insertionSortFila(Fila* f) {
    if (f == NULL || f->frente == NULL || f->frente->prox == NULL) return;
    
    Nodo *i = f->frente->prox;
    
    while (i != NULL) {
        Nodo *j = i;
        Registro chave = i->registro;
        
        while (j != f->frente && j->ant->registro.timestamp > chave.timestamp) {
            j->registro = j->ant->registro;
            j = j->ant;
        }
        j->registro = chave;
        i = i->prox;
    }
}

// Insertion Sort para Pilha (lista encadeada)
void insertionSortPilha(Pilha *p) {
    if (p == NULL || p->topo == NULL || p->topo->prox == NULL) return;
    
    Nodo *i = p->topo->prox;
    
    while (i != NULL) {
        Nodo *j = i;
        Registro chave = i->registro;
        
        while (j != p->topo && j->ant->registro.timestamp > chave.timestamp) {
            j->registro = j->ant->registro;
            j = j->ant;
        }
        j->registro = chave;
        i = i->prox;
    }
}

// Insertion Sort para ListaVetor (array)
void insertionSortListaVetor(ListaVetor *L) {
    if (listaVaziaVetor(L) || L->ultimo <= 1) return;
    
    for (int i = 1; i < L->ultimo; i++) {
        Registro chave = L->lista[i];
        int j = i - 1;
        
        while (j >= 0 && L->lista[j].timestamp > chave.timestamp) {
            L->lista[j + 1] = L->lista[j];
            j--;
        }
        L->lista[j + 1] = chave;
    }
}

// Insertion Sort para PilhaVetor (array)
void insertionSortPilhaVetor(PilhaVetor *P) {
    if (pilhaVaziaVetor(P) || P->topo < 1) return;
    
    for (int i = 1; i <= P->topo; i++) {
        Registro chave = P->stack[i];
        int j = i - 1;
        
        while (j >= 0 && P->stack[j].timestamp > chave.timestamp) {
            P->stack[j + 1] = P->stack[j];
            j--;
        }
        P->stack[j + 1] = chave;
    }
}

// Insertion Sort para FilaVetor (array circular)
void insertionSortFilaVetor(FilaVetor *Q) {
    if (filaVaziaVetor(Q) || Q->fundo == Q->frente) return;
    
    int tamanho = (Q->fundo - Q->frente + MAXTAM) % MAXTAM;
    int frente = Q->frente;
    
    for (int i = 1; i < tamanho; i++) {
        int atual = (frente + i) % MAXTAM;
        Registro chave = Q->queue[atual];
        int j = i - 1;
        
        while (j >= 0) {
            int anterior = (frente + j) % MAXTAM;
            if (Q->queue[anterior].timestamp > chave.timestamp) {
                Q->queue[(frente + j + 1) % MAXTAM] = Q->queue[anterior];
                j--;
            } else {
                break;
            }
        }
        Q->queue[(frente + j + 1) % MAXTAM] = chave;
    }
}

#endif
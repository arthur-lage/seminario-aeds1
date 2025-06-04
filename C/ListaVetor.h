#ifndef LISTAVETOR_H
#define LISTAVETOR_H

#include <stdio.h>

#include "Registro.h"
#define MAXTAM 1000

typedef struct {
    Registro lista[MAXTAM];
    int primeiro;
    int ultimo;
} ListaVetor;

void inicializarListaVetor(ListaVetor *L) {
    L->primeiro = 0;
    L->ultimo = 0;
}

int listaVaziaVetor(ListaVetor *L) {
    return L->primeiro == L->ultimo;
}

int listaCheiaVetor(ListaVetor *L) {
    return L->ultimo >= MAXTAM;
}

void inserirNoFinalVetor(ListaVetor *L, Registro reg) {
    if (listaCheiaVetor(L)) {
        printf("Lista esta cheia\n");
        return;
    }
    L->lista[L->ultimo] = reg;
    L->ultimo++;
}

void removerDaPosicaoVetor(ListaVetor *L, int posicao, Registro *reg) {
    if (listaVaziaVetor(L) || posicao >= L->ultimo) {
        printf("Posição não existe\n");
        return;
    }
    
    *reg = L->lista[posicao];
    L->ultimo--;
    
    for (int i = posicao; i < L->ultimo; i++) {
        L->lista[i] = L->lista[i + 1];
    }
}

void imprimirListaVetor(ListaVetor *L) {
    for (int i = L->primeiro; i < L->ultimo; i++) {
        printf("%d,%d,%.1f,%ld\n", 
               L->lista[i].usuario, 
               L->lista[i].filme,
               L->lista[i].avaliacao,
               L->lista[i].timestamp);
    }
}


#endif
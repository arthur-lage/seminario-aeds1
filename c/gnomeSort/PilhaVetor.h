#ifndef PILHAVETOR_H
#define PILHAVETOR_H

#include <stdio.h>
#include "Registro.h"

#define MAXTAM 100000

typedef struct {
    Registro stack[MAXTAM];
    int topo;
} PilhaVetor;

void inicializarPilhaVetor(PilhaVetor *P) {
    P->topo = -1;
}

int pilhaVaziaVetor(PilhaVetor *P) {
    return P->topo == -1;
}

int pilhaCheiaVetor(PilhaVetor *P) {
    return P->topo == MAXTAM - 1;
}

void empilharVetor(PilhaVetor *P, Registro reg) {
    if (pilhaCheiaVetor(P)) {
        printf("Pilha esta cheia\n");
        return;
    }
    P->topo++;
    P->stack[P->topo] = reg;
}

Registro desempilharVetor(PilhaVetor *P) {
    if (pilhaVaziaVetor(P)) {
        printf("Pilha esta vazia\n");
        exit(1);
    }
    Registro reg = P->stack[P->topo];
    P->topo--;
    return reg;
}

void imprimirPilhaVetor(PilhaVetor *P) {
    for (int i = P->topo; i >= 0; i--) {
        printf("%d,%d,%.1f,%ld\n", 
               P->stack[i].usuario, 
               P->stack[i].filme,
               P->stack[i].avaliacao,
               P->stack[i].timestamp);
    }
}


#endif
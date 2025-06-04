#ifndef FILAVETOR_H
#define FILAVETOR_H
#include <stdio.h>
#include "Registro.h"

#define MAXTAM 1000

typedef struct {
    Registro queue[MAXTAM];
    int frente;
    int fundo;
} FilaVetor;

void inicializarFilaVetor(FilaVetor *Q) {
    Q->frente = 1;
    Q->fundo = 1;
}

int filaVaziaVetor(FilaVetor *Q) {
    return Q->frente == Q->fundo;
}

int filaCheiaVetor(FilaVetor *Q) {
    return Q->fundo % MAXTAM + 1 == Q->frente;
}

void enfileirarVetor(FilaVetor *Q, Registro reg) {
    if (filaCheiaVetor(Q)) {
        printf("Fila esta cheia\n");
        return;
    }
    Q->queue[Q->fundo] = reg;
    Q->fundo = Q->fundo % MAXTAM + 1;
}

Registro desenfileirarVetor(FilaVetor *Q) {
    if (filaVaziaVetor(Q)) {
        printf("Fila esta vazia\n");
        exit(1);
    }
    Registro reg = Q->queue[Q->frente];
    Q->frente = Q->frente % MAXTAM + 1;
    return reg;
}

void imprimirFilaVetor(FilaVetor *Q) {
    int i = Q->frente;
    while (i != Q->fundo) {
        printf("%d,%d,%.1f,%ld\n", 
               Q->queue[i].usuario, 
               Q->queue[i].filme,
               Q->queue[i].avaliacao,
               Q->queue[i].timestamp);
        i = i % MAXTAM + 1;
    }
}


#endif
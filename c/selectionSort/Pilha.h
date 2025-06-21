#ifndef PILHA_H
#define PILHA_H

#include "Registro.h"
#include "Nodo.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Nodo *topo;
} Pilha;


void inicializarPilha(Pilha *p) {
    p->topo = NULL;
}

void empilhar(Pilha *p, Registro reg) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    
    novo->registro = reg;
    novo->prox = p->topo;
    p->topo = novo;
}

int pilhaVazia(Pilha *p) {
    return p->topo == NULL;
}

void imprimirPilha(Pilha *p) {
    Nodo *atual = p->topo;
    while (atual != NULL) {
        printf("%d,%d,%.1f,%ld\n", 
               atual->registro.usuario, 
               atual->registro.filme,
               atual->registro.avaliacao,
               atual->registro.timestamp);
        atual = atual->prox;
    }
}

#endif
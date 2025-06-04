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
    novo->ant = NULL;
    
    if (p->topo != NULL) {
        p->topo->ant = novo;
    }
    
    p->topo = novo;
}

int pilhaVazia(Pilha *p) {
    return p->topo == NULL;
}

Registro desempilhar(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    
    Nodo *temp = p->topo;
    Registro reg = temp->registro;
    
    p->topo = p->topo->prox;
    if (p->topo != NULL) {
        p->topo->ant = NULL;
    }
    
    free(temp);
    return reg;
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

void imprimirPilhaReverso(Pilha *p) {
    Nodo *atual = p->topo;
    while (atual != NULL && atual->prox != NULL) {
        atual = atual->prox;
    }
    
    while (atual != NULL) {
        printf("%d,%d,%.1f,%ld\n", 
               atual->registro.usuario, 
               atual->registro.filme,
               atual->registro.avaliacao,
               atual->registro.timestamp);
        atual = atual->ant;
    }
}

#endif
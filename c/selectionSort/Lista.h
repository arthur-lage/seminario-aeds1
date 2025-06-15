#ifndef LISTA_H
#define LISTA_H

#include "Registro.h"
#include "Nodo.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    Nodo *inicio;
    Nodo *fim;
} Lista;

void inicializarLista(Lista *l) {
    l->inicio = NULL;
    l->fim = NULL;
}

void inserirNoFinal(Lista *l, Registro reg) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    
    novo->registro = reg;
    novo->prox = NULL;
    
    if (l->inicio == NULL) {
        l->inicio = novo;
        l->fim = novo;
    } else {
        l->fim->prox = novo;
        l->fim = novo;
    }
}

void imprimirLista(Lista *l) {
    Nodo *atual = l->inicio;
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
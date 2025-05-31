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
    novo->ant = l->fim;
    
    if (l->inicio == NULL) {
        l->inicio = novo;
        l->fim = novo;
    } else {
        l->fim->prox = novo;
        l->fim = novo;
    }
}

void inserirNoInicio(Lista *l, Registro reg) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    
    novo->registro = reg;
    novo->ant = NULL;
    novo->prox = l->inicio;
    
    if (l->inicio == NULL) {
        l->fim = novo;
    } else {
        l->inicio->ant = novo;
    }
    l->inicio = novo;
}

void removerDoInicio(Lista *l) {
    if (l->inicio == NULL) return;
    
    Nodo *temp = l->inicio;
    l->inicio = l->inicio->prox;
    
    if (l->inicio != NULL) {
        l->inicio->ant = NULL;
    } else {
        l->fim = NULL;
    }
    
    free(temp);
}

void removerDoFinal(Lista *l) {
    if (l->fim == NULL) return;
    
    Nodo *temp = l->fim;
    l->fim = l->fim->ant;
    
    if (l->fim != NULL) {
        l->fim->prox = NULL;
    } else {
        l->inicio = NULL;
    }
    
    free(temp);
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

void imprimirListaReverso(Lista *l) {
    Nodo *atual = l->fim;
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
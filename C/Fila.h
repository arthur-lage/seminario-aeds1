#ifndef FILA_H
#define FILA_H

#include "Registro.h"
#include "Nodo.h"

typedef struct {
    Nodo *frente;
    Nodo *tras;
} Fila;

int filaVazia(Fila *f) {
    return f->frente == NULL;
}

void inicializarFila(Fila *f) {
    f->frente = NULL;
    f->tras = NULL;
}

void enfileirar(Fila *f, Registro reg) {
    Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) {
        printf("Erro de alocação de memória\n");
        exit(1);
    }
    
    novo->registro = reg;
    novo->prox = NULL;
    novo->ant = f->tras;  
    
    if (filaVazia(f)) {
        f->frente = novo;
    } else {
        f->tras->prox = novo;
    }
    f->tras = novo;
}

void desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    
    Nodo *temp = f->frente;
    f->frente = f->frente->prox;
    
    if (f->frente != NULL) {
        f->frente->ant = NULL;  
    } else {
        f->tras = NULL;  
    }
    
    free(temp);
}

void imprimirFila(Fila *f) {
    Nodo *atual = f->frente;
    while (atual != NULL) {
        printf("Usuário: %d, Filme: %d, Avaliação: %.1f, Timestamp: %ld\n",
              atual->registro.usuario,
              atual->registro.filme,
              atual->registro.avaliacao,
              atual->registro.timestamp);
        atual = atual->prox;
    }
}


#endif
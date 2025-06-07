#include "Lista.hpp"

Lista::Lista() : inicio(nullptr), fim(nullptr) {}

void Lista::inserirNoFinal(Registro reg) {
    Nodo* novo = new Nodo;
    novo->registro = reg;
    novo->prox = nullptr;
    novo->ant = this->fim;

    if (this->fim != nullptr) {
        this->fim->prox = novo;
    } else {
        this->inicio = novo;
    }
    this->fim = novo;
}

void Lista::inserirNoInicio(Registro reg) {
    Nodo* novo = new Nodo;
    novo->registro = reg;
    novo->ant = nullptr;
    novo->prox = this->inicio;

    if (this->inicio != nullptr) {
        this->inicio->ant = novo;
    } else {
        this->fim = novo;
    }
    this->inicio = novo;
}

void Lista::removerDoInicio() {
    if (this->inicio == nullptr) return;

    Nodo* temp = this->inicio;
    this->inicio = this->inicio->prox;
    
    if (this->inicio != nullptr) {
        this->inicio->ant = nullptr;
    } else {
        this->fim = nullptr;
    }
    delete temp;
}

void Lista::removerDoFinal() {
    if (this->fim == nullptr) return;

    Nodo* temp = this->fim;
    this->fim = this->fim->ant;
    
    if (this->fim != nullptr) {
        this->fim->prox = nullptr;
    } else {
        this->inicio = nullptr;
    }
    delete temp;
}

void Lista::imprimirLista() {
    for (Nodo* atual = this->inicio; atual != nullptr; atual = atual->prox) {
        printf("Usuário: %d, Filme: %d, Avaliação: %.1f\n",
               atual->registro.usuario,
               atual->registro.filme,
               atual->registro.avaliacao);
    }
}

void Lista::imprimirListaReverso() {
    for (Nodo* atual = this->fim; atual != nullptr; atual = atual->ant) {
        printf("Usuário: %d, Filme: %d, Avaliação: %.1f\n",
               atual->registro.usuario,
               atual->registro.filme,
               atual->registro.avaliacao);
    }
}
#include "Fila.hpp"
#include <cstdlib>
#include <iostream>

Fila::Fila() : frente(nullptr), tras(nullptr) {}

bool Fila::vazia() const {
    return frente == nullptr;
}

void Fila::enfileirar(const Registro& reg) {
    Nodo* novo = new Nodo;
    novo->registro = reg;
    novo->prox = nullptr;
    novo->ant = tras;

    if (vazia()) {
        frente = novo;
    } else {
        tras->prox = novo;
    }
    tras = novo;
}

void Fila::desenfileirar() {
    if (vazia()) {
        std::cerr << "Fila vazia!" << std::endl;
        return;
    }

    Nodo* temp = frente;
    frente = frente->prox;

    if (frente != nullptr) {
        frente->ant = nullptr;
    } else {
        tras = nullptr;
    }

    delete temp;
}

void Fila::imprimir() const {
    for (Nodo* atual = frente; atual != nullptr; atual = atual->prox) {
        std::cout << "Usuário: " << atual->registro.usuario
                  << ", Filme: " << atual->registro.filme
                  << ", Avaliação: " << atual->registro.avaliacao
                  << ", Timestamp: " << atual->registro.timestamp << std::endl;
    }
}

#include "Pilha.hpp"
#include <stdexcept>

Pilha::Pilha() : topo(nullptr) {}

Pilha::~Pilha() {
    while (!vazia()) {
        desempilhar();
    }
}

bool Pilha::vazia() const {
    return topo == nullptr;
}

void Pilha::empilhar(const Registro& reg) {
    Nodo* novo = new Nodo;
    novo->registro = reg;
    novo->prox = topo;
    novo->ant = nullptr;

    if (topo != nullptr) {
        topo->ant = novo;
    }
    topo = novo;
}

Registro Pilha::desempilhar() {
    if (vazia()) {
        throw std::runtime_error("Pilha vazia!");
    }

    Nodo* temp = topo;
    Registro reg = temp->registro;
    topo = topo->prox;

    if (topo != nullptr) {
        topo->ant = nullptr;
    }

    delete temp;
    return reg;
}

void Pilha::imprimir() const {
    for (Nodo* atual = topo; atual != nullptr; atual = atual->prox) {
        std::cout << atual->registro.usuario << ","
                  << atual->registro.filme << ","
                  << atual->registro.avaliacao << ","
                  << atual->registro.timestamp << std::endl;
    }
}

void Pilha::imprimirReverso() const {
    if (vazia()) return;

    Nodo* atual = topo;
    while (atual->prox != nullptr) {
        atual = atual->prox;
    }

    while (atual != nullptr) {
        std::cout << atual->registro.usuario << ","
                  << atual->registro.filme << ","
                  << atual->registro.avaliacao << ","
                  << atual->registro.timestamp << std::endl;
        atual = atual->ant;
    }
}
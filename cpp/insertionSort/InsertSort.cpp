#include "InsertSort.hpp"
#include "Lista.hpp"
#include "Pilha.hpp"
#include "Fila.hpp"
#include "Nodo.hpp"

void InsertionSort::insertionSortLista(Lista *lista) {
    if (!lista || !lista->getInicio() || !lista->getInicio()->prox) return;

    Nodo* atual = lista->getInicio()->prox;
    while (atual != nullptr) {
        Registro temp = atual->registro;
        Nodo* j = atual->ant;

        while (j != nullptr && j->registro.timestamp > temp.timestamp) {
            j->prox->registro = j->registro;
            j = j->ant;
        }

        if (j == nullptr) {
            lista->getInicio()->registro = temp;
        } else {
            j->prox->registro = temp;
        }

        atual = atual->prox;
    }
}

void InsertionSort::insertionSortFila(Fila* f) {
    if (!f || f->vazia() || f->getFrente()->getProx() == nullptr) return;

    Nodo* atual = f->getFrente()->getProx();
    while (atual != nullptr) {
        Registro temp = atual->getRegistro();
        Nodo* j = atual->getAnt();

        while (j != nullptr && j->getRegistro().timestamp > temp.timestamp) {
            j->getProx()->setRegistro(j->getRegistro());
            j = j->getAnt();
        }

        if (j == nullptr) {
            f->getFrente()->setRegistro(temp);
        } else {
            j->getProx()->setRegistro(temp);
        }

        atual = atual->getProx();
    }
}

void InsertionSort::insertionSortPilha(Pilha *p) {
    if (!p || p->vazia() || p->getTopo()->getProx() == nullptr) return;

    Nodo* atual = p->getTopo()->getProx();
    while (atual != nullptr) {
        Registro temp = atual->getRegistro();
        Nodo* j = atual->getAnt();

        while (j != nullptr && j->getRegistro().timestamp > temp.timestamp) {
            j->getProx()->setRegistro(j->getRegistro());
            j = j->getAnt();
        }

        if (j == nullptr) {
            p->getTopo()->setRegistro(temp);
        } else {
            j->getProx()->setRegistro(temp);
        }

        atual = atual->getProx();
    }
}

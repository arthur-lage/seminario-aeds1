#include "InsertSort.hpp"
#include "Lista.hpp"
#include "Pilha.hpp"
#include "Fila.hpp"
#include "Nodo.hpp"
#include <sys/resource.h>
#include <iostream>

long getMemoryUsageKB() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss; // Retorna KB em sistemas Linux
}
void InsertionSort::insertionSortLista(Lista *lista) {
    long memBefore = getMemoryUsageKB();

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
    long memAfter = getMemoryUsageKB();
    std::cout << "[Lista] Memória utilizada: " << (memAfter - memBefore) << " KB\n";
}

void InsertionSort::insertionSortFila(Fila* f) {
    long memBefore = getMemoryUsageKB();

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

    long memAfter = getMemoryUsageKB();
    std::cout << "[Fila] Memória utilizada: " << (memAfter - memBefore) << " KB\n";
}

void InsertionSort::insertionSortPilha(Pilha *p) {
    long memBefore = getMemoryUsageKB();

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

    long memAfter = getMemoryUsageKB();
    std::cout << "[Pilha] Memória utilizada: " << (memAfter - memBefore) << " KB\n";
}

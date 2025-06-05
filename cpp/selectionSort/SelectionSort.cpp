#include "SelectionSort.hpp"
#include "Lista.hpp"
#include "Pilha.hpp"
#include "Fila.hpp"
#include "Nodo.hpp"

void SelectionSort::selectionSortLista(Lista *lista) {
    if (!lista || !lista->getInicio() || !lista->getInicio()->prox) return;

    Nodo* atual = lista->getInicio();
    
    while (atual) {
        Nodo* min = atual;
        Nodo* proximo = atual->prox;
        
        while (proximo) {
            if (proximo->registro.timestamp < min->registro.timestamp) {
                min = proximo;
            }
            proximo = proximo->prox;
        }
        
        if (min != atual) {
            Registro temp = atual->registro;
            atual->registro = min->registro;
            min->registro = temp;
        }
        
        atual = atual->prox;
    }
}

void SelectionSort::selectionSortFila(Fila* f) {
    if (f->vazia() || f->getFrente()->getProx() == nullptr) return;

    Nodo* atual = f->getFrente();
    
    while (atual) {
        Nodo* min = atual;
        Nodo* proximo = atual->getProx();
        
        while (proximo) {
            if (proximo->getRegistro().timestamp < min->getRegistro().timestamp) {
                min = proximo;
            }
            proximo = proximo->getProx();
        }
        
        if (min != atual) {
            Registro temp = atual->getRegistro();
            atual->setRegistro(min->getRegistro());
            min->setRegistro(temp);
        }
        
        atual = atual->getProx();
    }
}

void SelectionSort::selectionSortPilha(Pilha *p) {
    if (p->vazia() || p->getTopo()->getProx() == nullptr) return;

    Nodo* atual = p->getTopo();
    
    while (atual) {
        Nodo* min = atual;
        Nodo* proximo = atual->getProx();
        
        while (proximo) {
            if (proximo->getRegistro().timestamp < min->getRegistro().timestamp) {
                min = proximo;
            }
            proximo = proximo->getProx();
        }
        
        if (min != atual) {
            Registro temp = atual->getRegistro();
            atual->setRegistro(min->getRegistro());
            min->setRegistro(temp);
        }
        
        atual = atual->getProx();
    }
}
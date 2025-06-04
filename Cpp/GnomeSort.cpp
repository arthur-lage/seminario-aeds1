#include "GnomeSort.hpp"
#include "Lista.hpp"
#include "Pilha.hpp"
#include "Fila.hpp"
#include "Nodo.hpp"

void GnomeSort::gnomeSortLista(Lista *lista) {
    if (!lista || !lista->getInicio() || !lista->getInicio()->prox) return;

    Nodo* i = lista->getInicio();
    Nodo* prev = nullptr;

    while (i && i->prox) {
        if (i->registro.timestamp <= i->prox->registro.timestamp) {
            prev = i;
            i = i->prox;
        } else {
            // Troca os registros
            Registro temp = i->registro;
            i->registro = i->prox->registro;
            i->prox->registro = temp;
            
            // Retrocede
            if (i->ant) {
                i = i->ant;
            } else {
                i = lista->getInicio(); // Volta ao início se necessário
            }
        }
    }
}
void GnomeSort::gnomeSortFila(Fila* f) {
    if (f->vazia() || f->getFrente()->getProx() == nullptr) return;

    Nodo* i = f->getFrente();
    Nodo* prev = nullptr;

    while (i != nullptr && i->getProx() != nullptr) {
        if (i->getRegistro().timestamp <= i->getProx()->getRegistro().timestamp) {
            prev = i;
            i = i->getProx();
        } else {
            Registro temp = i->getRegistro();
            i->setRegistro(i->getProx()->getRegistro());
            i->getProx()->setRegistro(temp);
            
            // Retrocede
            if (i->getAnt()) {
                i = i->getAnt();
            } else {
                i = f->getFrente(); // Volta ao início se necessário
            }
        }
    }
}
void GnomeSort::gnomeSortPilha(Pilha *p) {
    if (p->vazia() || p->getTopo()->getProx() == nullptr) return;

    Nodo* i = p->getTopo();
    Nodo* prev = nullptr;

    while (i != nullptr && i->getProx() != nullptr) {
        if (i->getRegistro().timestamp <= i->getProx()->getRegistro().timestamp) {
            prev = i;
            i = i->getProx();
        } else {
            // Troca direta dos registros
            Registro temp = i->getRegistro();
            i->setRegistro(i->getProx()->getRegistro());
            i->getProx()->setRegistro(temp);
            
            // Retrocede
            if (i->getAnt()) {
                i = i->getAnt();
            } else {
                i = p->getTopo(); // Volta ao topo se necessário
            }
        }
    }
}
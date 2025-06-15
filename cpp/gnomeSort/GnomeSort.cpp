#include "GnomeSort.hpp"
#include "Lista.hpp"
#include "Pilha.hpp"
#include "Fila.hpp"
#include "Nodo.hpp"
#include <sys/resource.h>
#include <iostream>

// Função auxiliar para medição de memória (Linux/Unix)
long getMemoryUsageKB() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss; // Retorna KB em sistemas Linux
}

void GnomeSort::gnomeSortLista(Lista *lista) {
    long memBefore = getMemoryUsageKB();
    
    if (!lista || !lista->getInicio() || !lista->getInicio()->prox) return;

    Nodo* i = lista->getInicio();
    Nodo* prev = nullptr;

    while (i && i->prox) {
        if (i->registro.timestamp <= i->prox->registro.timestamp) {
            prev = i;
            i = i->prox;
        } else {
            Registro temp = i->registro;
            i->registro = i->prox->registro;
            i->prox->registro = temp;
            
            if (i->ant) {
                i = i->ant;
            } else {
                i = lista->getInicio(); 
            }
        }
    }
    
    long memAfter = getMemoryUsageKB();
    std::cout << "[Lista] Memória utilizada: " << (memAfter - memBefore) << " KB\n";
}

void GnomeSort::gnomeSortFila(Fila* f) {
    long memBefore = getMemoryUsageKB();
    
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
            
            if (i->getAnt()) {
                i = i->getAnt();
            } else {
                i = f->getFrente();
            }
        }
    }
    
    long memAfter = getMemoryUsageKB();
    std::cout << "[Fila] Memória utilizada: " << (memAfter - memBefore) << " KB\n";
}

void GnomeSort::gnomeSortPilha(Pilha *p) {
    long memBefore = getMemoryUsageKB();
    
    if (p->vazia() || p->getTopo()->getProx() == nullptr) return;

    Nodo* i = p->getTopo();
    Nodo* prev = nullptr;

    while (i != nullptr && i->getProx() != nullptr) {
        if (i->getRegistro().timestamp <= i->getProx()->getRegistro().timestamp) {
            prev = i;
            i = i->getProx();
        } else {
            Registro temp = i->getRegistro();
            i->setRegistro(i->getProx()->getRegistro());
            i->getProx()->setRegistro(temp);
            
            if (i->getAnt()) {
                i = i->getAnt();
            } else {
                i = p->getTopo(); 
            }
        }
    }
    
    long memAfter = getMemoryUsageKB();
    std::cout << "[Pilha] Memória utilizada: " << (memAfter - memBefore) << " KB\n";
}
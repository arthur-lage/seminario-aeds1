#ifndef PILHA_HPP
#define PILHA_HPP

#include "Registro.hpp"
#include "Nodo.hpp"
#include <iostream>

class Pilha {
private:
    Nodo* topo;

public:
    Pilha();
    ~Pilha();
    bool vazia() const;
    void empilhar(const Registro& reg);
    Registro desempilhar();
    void imprimir() const;
    void imprimirReverso() const;

    Nodo* getTopo() const { return topo; }
    void setTopo(Nodo* t) { topo = t; }
    
};

#endif
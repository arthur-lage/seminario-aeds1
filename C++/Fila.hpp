#ifndef FILA_HPP
#define FILA_HPP

#include "Registro.hpp"
#include "Nodo.hpp"
#include <iostream>

class Fila {
private:
    Nodo* frente;
    Nodo* tras;

public:
    Fila();
    bool vazia() const;
    void enfileirar(const Registro& reg);
    void desenfileirar();
    void imprimir() const;

    Nodo* getFrente() const { return frente; }
    Nodo* getTras() const { return tras; }
    void setFrente(Nodo* f) { frente = f; }
    void setTras(Nodo* t) { tras = t; }
    
};

#endif
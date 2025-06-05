#ifndef NODO_HPP
#define NODO_HPP

#include "Registro.hpp"

class Nodo {
public:
    Registro registro;
    Nodo* prox;
    Nodo* ant;
    
    static void trocarRegistros(Nodo* a, Nodo* b);
    Registro getRegistro() const { return registro; }
    Nodo* getProx() const { return prox; }
    Nodo* getAnt() const { return ant; }
    
    void setRegistro(Registro r) { registro = r; }
    void setProx(Nodo* n) { prox = n; }
    void setAnt(Nodo* n) { ant = n; }
};

#endif
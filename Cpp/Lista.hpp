#ifndef LISTA_HPP
#define LISTA_HPP

#include "Registro.hpp"
#include "Nodo.hpp"
#include <cstdio>
#include <cstdlib>

class Lista {
private:
    Nodo* inicio;
    Nodo* fim;

public:
    Lista();
    void inserirNoFinal(Registro reg);
    void inserirNoInicio(Registro reg);
    void removerDoInicio();
    void removerDoFinal();
    void imprimirLista();
    void imprimirListaReverso();
    Nodo* getInicio() const { return inicio; }
    Nodo* getFim() const { return fim; }
    void setInicio(Nodo* novoInicio) { inicio = novoInicio; }
    void setFim(Nodo* novoFim) { fim = novoFim; }
    
};

#endif
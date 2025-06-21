#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include "Lista.hpp"
#include "Fila.hpp"
#include "Pilha.hpp"

class InsertionSort {
public:
    static void insertionSortLista(Lista *lista);
    static void insertionSortFila(Fila *f);
    static void insertionSortPilha(Pilha *p);
};

#endif

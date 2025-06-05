#pragma once 
#include "Lista.hpp"
#include "Fila.hpp"
#include "Pilha.hpp"

class SelectionSort {
public:
    static void selectionSortLista(Lista *lista);
    static void selectionSortFila(Fila *f);
    static void selectionSortPilha(Pilha *p);
};
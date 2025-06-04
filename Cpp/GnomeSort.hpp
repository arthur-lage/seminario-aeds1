#ifndef GNOME_SORT_HPP
#define GNOME_SORT_HPP

#include "Lista.hpp"
#include "Fila.hpp"
#include "Pilha.hpp"

class GnomeSort {
public:
    static void gnomeSortLista(Lista *lista);
    static void gnomeSortFila(Fila *f);
    static void gnomeSortPilha(Pilha *p);
};

#endif
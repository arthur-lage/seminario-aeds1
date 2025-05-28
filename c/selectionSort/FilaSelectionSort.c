#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"
#include "SelectionSort.h"
#include "LeitorDeArquivo.h"

int main () {
    Fila fila;
    inicializarFila(&fila);
    
    carregarDadosParaFila("datasets/100.dat", &fila);
    
    printf("Dados carregados:\n");
    imprimirFila(&fila);

    selectionSortFila(&fila);
    
    printf("\n\nDados ordenados:\n");
    imprimirFila(&fila);

    return 0;
}
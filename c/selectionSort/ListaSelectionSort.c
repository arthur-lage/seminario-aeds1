#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "SelectionSort.h"
#include "LeitorDeArquivo.h"

int main () {
    Lista lista;
    inicializarLista(&lista);
    
    carregarDadosParaLista("datasets/100.dat", &lista);
    
    printf("Dados carregados:\n");
    imprimirLista(&lista);

    selectionSort(&lista);
    
    printf("\n\nDados ordenados:\n");
    imprimirLista(&lista);

    return 0;
}
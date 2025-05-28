#include <stdio.h>
#include <stdlib.h>

#include "Pilha.h"
#include "SelectionSort.h"
#include "LeitorDeArquivo.h"

int main () {
    Pilha pilha;
    inicializarPilha(&pilha);
    
    carregarDadosParaPilha("datasets/100.dat", &pilha);
    
    printf("Dados carregados:\n");
    imprimirPilha(&pilha);

    selectionSortPilha(&pilha);
    
    printf("\n\nDados ordenados:\n");
    imprimirPilha(&pilha);

    return 0;
}
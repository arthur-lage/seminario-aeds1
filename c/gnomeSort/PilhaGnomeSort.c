#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

#include "Pilha.h"
#include "GnomeSort.h"
#include "LeitorDeArquivo.h"

int main () {
    Pilha pilha;
    inicializarPilha(&pilha);
    
    carregarDadosParaPilha("../../datasets/100.dat", &pilha);
    
    clock_t start = clock();

    gnomeSortPilha(&pilha);
    
    clock_t end = clock();

    imprimirPilha(&pilha);
 
    double time_spent = (double)(end - start) * 1000 / CLOCKS_PER_SEC;        

    printf("\nTempo de ordenação: %.2f ms  \n", time_spent);

    return 0;
}
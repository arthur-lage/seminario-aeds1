#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

#include "PilhaVetor.h"
#include "InsertSort.h"
#include "LeitorDeArquivo.h"

int main () {
    PilhaVetor pilhaVetor;
    inicializarPilhaVetor(&pilhaVetor);
    
    carregarDadosParaPilhaVetor("../../datasets/100.dat", &pilhaVetor);
    
    clock_t start = clock();

    insertionSortPilhaVetor(&pilhaVetor);

    clock_t end = clock();
   
    double time_spent = (double)(end - start) * 1000 / CLOCKS_PER_SEC;  
  
    printf("\nTempo de ordenação: %.2f ms  \n", time_spent);

    return 0;
}
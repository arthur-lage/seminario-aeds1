#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

#include "PilhaVetor.h"
#include "SelectionSort.h"
#include "LeitorDeArquivo.h"

int main () {
    double media=0;

    for (int i = 0; i < 1; i++)
    {
    PilhaVetor pilhaVetor;
    inicializarPilhaVetor(&pilhaVetor);
    
    carregarDadosParaPilhaVetor("../../datasets/100.dat", &pilhaVetor);
    
    clock_t start = clock();

    selectionSortPilhaVetor(&pilhaVetor);

    clock_t end = clock();
   
    double time_spent = (double)(end - start) * 1000 / CLOCKS_PER_SEC;  
  
    printf("\nTempo de ordenação: %.2f ms  \n", time_spent);

    
    media = media + time_spent;
    }

    media = media/1;
    printf("Media total: %lf\n", media);

    return 0;
}
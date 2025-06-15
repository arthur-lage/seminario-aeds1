#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

#include "FilaVetor.h"
#include "SelectionSort.h"
#include "LeitorDeArquivo.h"

int main () {double media=0;

    for (int i = 0; i < 10; i++)
    {
    FilaVetor filaVetor;
    inicializarFilaVetor(&filaVetor);
    
    carregarDadosParaFilaVetor("../../datasets/100000.dat", &filaVetor);
    
    clock_t start = clock();

    selectionSortFilaVetor(&filaVetor);

    clock_t end = clock();
   
    double time_spent = (double)(end - start) * 1000 / CLOCKS_PER_SEC;  
   
    printf("\nTempo de ordenação: %.2f ms  \n", time_spent);
  
    media = media + time_spent;
    }

    media = media/10;
    printf("Media total: %lf\n", media);

    return 0;
}
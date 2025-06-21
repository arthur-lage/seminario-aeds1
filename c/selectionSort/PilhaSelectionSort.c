#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Pilha.h"
#include "SelectionSort.h"
#include "LeitorDeArquivo.h"

int main () {
    double media=0;

    for (int i = 0; i < 1; i++)
    {
    Pilha pilha;
    inicializarPilha(&pilha);

    clock_t start = clock();
    
    carregarDadosParaPilha("../../datasets/100.dat", &pilha);
    selectionSortPilha(&pilha);
    
    clock_t end = clock();

    double time_spent = (double)(end - start) * 1000 / CLOCKS_PER_SEC;        
    printf("\nTempo de ordenação: %.2f ms  \n", time_spent);
    media = media + time_spent;
    }

    media = media/1;
    printf("Media total: %lf\n", media);

    return 0;
}
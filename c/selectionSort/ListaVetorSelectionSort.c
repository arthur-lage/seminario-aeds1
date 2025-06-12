#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

#include "ListaVetor.h"
#include "SelectionSort.h"
#include "LeitorDeArquivo.h"

int main () {
    double media=0;

    for (int i = 0; i < 10; i++)
    {
    ListaVetor listaVetor;
    inicializarListaVetor(&listaVetor);
    
    carregarDadosParaListaVetor("../../datasets/100000.dat", &listaVetor);
    
    clock_t start = clock();

    selectionSortListaVetor(&listaVetor);

    clock_t end = clock();
    
    double time_spent = (double)(end - start) * 1000 / CLOCKS_PER_SEC;  
   
    printf("\nTempo de ordenação: %.2f ms  \n", time_spent);

    
    media = media + time_spent;
    }

    media = media/10;
    printf("Media total: %lf\n", media);

    return 0;
}
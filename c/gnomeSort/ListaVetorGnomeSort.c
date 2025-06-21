#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

#include "ListaVetor.h"
#include "GnomeSort.h"
#include "LeitorDeArquivo.h"

int main () {
    double media=0;

    for (int i = 0; i < 1; i++)
    {
    ListaVetor listaVetor;
    inicializarListaVetor(&listaVetor);
    
    carregarDadosParaListaVetor("../../datasets/10000.dat", &listaVetor);
    
    clock_t start = clock();

    gnomeSortListaVetor(&listaVetor);

    clock_t end = clock();
    
    double time_spent = (double)(end - start) * 1000 / CLOCKS_PER_SEC;  
   
    printf("\nTempo de ordenação: %.2f ms  \n", time_spent);

    media = media + time_spent;
    }

    media = media/1;
    printf("Media total: %lf\n", media);

    return 0;
}
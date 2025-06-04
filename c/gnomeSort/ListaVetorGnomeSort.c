#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

#include "ListaVetor.h"
#include "GnomeSort.h"
#include "LeitorDeArquivo.h"

int main () {
    ListaVetor listaVetor;
    inicializarListaVetor(&listaVetor);
    
    carregarDadosParaListaVetor("../../datasets/100.dat", &listaVetor);
    
    clock_t start = clock();

    gnomeSortListaVetor(&listaVetor);

    clock_t end = clock();
    
    double time_spent = (double)(end - start) * 1000 / CLOCKS_PER_SEC;  
   
    printf("\nTempo de ordenação: %.2f ms  \n", time_spent);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

#include "Lista.h"
#include "GnomeSort.h"
#include "LeitorDeArquivo.h"

int main () {
    Lista lista;
    inicializarLista(&lista);
    
    carregarDadosParaLista("/home/will/Documentos/AEDS/Seminario/GnomeSort/datasets/100.dat", &lista);
    
    clock_t start = clock();

    gnomeSortLista(&lista);

    clock_t end = clock();
    
    double time_spent = (double)(end - start) * 1000 / CLOCKS_PER_SEC;  
    
    printf("\nTempo de ordenação: %.2f ms  \n", time_spent);


    return 0;
}
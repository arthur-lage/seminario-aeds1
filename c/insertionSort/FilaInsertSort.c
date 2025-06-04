#include <stdio.h>
#include <stdlib.h>
#include <time.h>  


#include "Fila.h"
#include "InsertSort.h"
#include "LeitorDeArquivo.h"

int main () {
    Fila fila;
    inicializarFila(&fila);
    
    carregarDadosParaFila("../../datasets/100.dat", &fila);
    
    clock_t start = clock();

    insertionSortFila(&fila);
    
    clock_t end = clock();
    double time_spent = (double)(end - start) * 1000 / CLOCKS_PER_SEC;        

    printf("\nTempo de ordenação: %.2f ms  \n", time_spent);

    return 0;
}
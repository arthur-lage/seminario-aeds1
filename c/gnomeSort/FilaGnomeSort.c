#include <stdio.h>
#include <stdlib.h>
#include <time.h>  


#include "Fila.h"
#include "GnomeSort.h"
#include "LeitorDeArquivo.h"

int main () {
    double media=0;

    for (int i = 0; i < 10; i++)
    {

    Fila fila;
    inicializarFila(&fila);
    
    carregarDadosParaFila("../../datasets/100000.dat", &fila);
    
    clock_t start = clock();

    gnomeSortFila(&fila);
    
    clock_t end = clock();
    double time_spent = (double)(end - start) * 1000 / CLOCKS_PER_SEC;        

        media = media + time_spent;
    }

    media = media/10;
    printf("Media total: %lf\n", media);

    return 0;
}
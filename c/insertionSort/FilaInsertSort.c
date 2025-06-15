#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h> // Para getrusage()

#include "Fila.h"
#include "InsertSort.h"
#include "LeitorDeArquivo.h"

void printMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    printf("Memória usada: %ld KB\n", usage.ru_maxrss);
}

int main() {
    double media = 0;
    long total_memory = 0;

    for (int i = 0; i < 10; i++) {
        Fila fila;
        inicializarFila(&fila);
        
        carregarDadosParaFila("../../datasets/100000.dat", &fila);
        
        clock_t start = clock();
        insertionSortFila(&fila);
        clock_t end = clock();
        
        double time_spent = (double)(end - start) * 1000 / CLOCKS_PER_SEC;        
        media = media + time_spent;

        // Medição de memória
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        total_memory += usage.ru_maxrss;
    }

    media = media/10;
    printf("Media tempo: %lf ms\n", media);
    printf("Media memoria: %ld KB\n", total_memory/10);

    return 0;
}
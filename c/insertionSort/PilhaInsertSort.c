#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>  // Added for memory measurement

#include "Pilha.h"
#include "InsertSort.h"
#include "LeitorDeArquivo.h"

int main() {
    double media = 0;
    long total_memory = 0;
    struct rusage usage;  // For memory measurement

    for (int i = 0; i < 10; i++) {
        Pilha pilha;
        inicializarPilha(&pilha);
        
        carregarDadosParaPilha("../../datasets/100000.dat", &pilha);
        
        // Measure memory before sorting
        getrusage(RUSAGE_SELF, &usage);
        long mem_before = usage.ru_maxrss;
        
        clock_t start = clock();
        insertionSortPilha(&pilha);
        clock_t end = clock();
        
        // Measure memory after sorting
        getrusage(RUSAGE_SELF, &usage);
        long mem_after = usage.ru_maxrss;
        
        double time_spent = (double)(end - start) * 1000 / CLOCKS_PER_SEC;
        
        printf("\nTempo de ordenação: %.2f ms", time_spent);
        printf("  |  Memória usada: %ld KB\n", mem_after - mem_before);
        
        media += time_spent;
        total_memory += (mem_after - mem_before);
    }

    media = media/10;
    printf("\nMédia tempo: %.2f ms", media);
    printf("  |  Média memória: %ld KB\n", total_memory/10);

    return 0;
}
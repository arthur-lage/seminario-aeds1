#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>  // Only new include needed

#include "PilhaVetor.h"
#include "InsertSort.h"
#include "LeitorDeArquivo.h"

int main() {
    double media = 0;
    long total_memory = 0;  // Added to track memory usage
    struct rusage mem_usage;  // Added for memory measurement

    for (int i = 0; i < 10; i++) {
        PilhaVetor pilhaVetor;
        inicializarPilhaVetor(&pilhaVetor);
        
        carregarDadosParaPilhaVetor("../../datasets/100000.dat", &pilhaVetor);
        
        // Memory measurement before sorting
        getrusage(RUSAGE_SELF, &mem_usage);
        long mem_before = mem_usage.ru_maxrss;
        
        clock_t start = clock();
        insertionSortPilhaVetor(&pilhaVetor);
        clock_t end = clock();
        
        // Memory measurement after sorting
        getrusage(RUSAGE_SELF, &mem_usage);
        long mem_after = mem_usage.ru_maxrss;
        
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
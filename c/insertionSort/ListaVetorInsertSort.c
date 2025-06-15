#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>  // Adicionado para medição de memória

#include "ListaVetor.h"
#include "InsertSort.h"
#include "LeitorDeArquivo.h"

int main() {
    double media = 0;
    long total_memoria = 0;
    struct rusage usage;  // Para medição de memória

    for (int i = 0; i < 10; i++) {
        ListaVetor listaVetor;
        inicializarListaVetor(&listaVetor);
        
        carregarDadosParaListaVetor("../../datasets/100000.dat", &listaVetor);
        
        // Medição de memória antes da ordenação
        getrusage(RUSAGE_SELF, &usage);
        long mem_antes = usage.ru_maxrss;
        
        clock_t start = clock();
        insertionSortListaVetor(&listaVetor);
        clock_t end = clock();
        
        // Medição de memória depois da ordenação
        getrusage(RUSAGE_SELF, &usage);
        long mem_depois = usage.ru_maxrss;
        
        double time_spent = (double)(end - start) * 1000 / CLOCKS_PER_SEC;
        
        printf("\nTempo de ordenação: %.2f ms", time_spent);
        printf("  |  Memória usada: %ld KB\n", mem_depois - mem_antes);
        
        media += time_spent;
        total_memoria += (mem_depois - mem_antes);
    }

    media = media/10;
    printf("\nMédia tempo: %.2f ms", media);
    printf("  |  Média memória: %ld KB\n", total_memoria/10);

    return 0;
}
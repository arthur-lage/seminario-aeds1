#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>  // Adicionado para medição de memória

#include "Lista.h"
#include "GnomeSort.h"
#include "LeitorDeArquivo.h"

int main() {
    double media = 0;
    long total_memoria = 0;
    struct rusage usage;  // Adicionado para medição de memória

    for (int i = 0; i < 10; i++) {
        Lista lista;
        inicializarLista(&lista);
        
        carregarDadosParaLista("../../datasets/100000.dat", &lista);
        
        getrusage(RUSAGE_SELF, &usage);  // Medição antes da ordenação
        long mem_antes = usage.ru_maxrss;
        
        clock_t start = clock();
        gnomeSortLista(&lista);
        clock_t end = clock();
        
        getrusage(RUSAGE_SELF, &usage);  // Medição depois da ordenação
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
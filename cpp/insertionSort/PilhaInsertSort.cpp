#include <iostream>
#include <chrono>
#include "Fila.hpp"
#include "Nodo.hpp"
#include "InsertSort.hpp"
#include "LeitorDeArquivo.hpp"

int main() {
     double media=0;

    for (int i = 0; i < 10; i++)
    {
    Pilha pilha;
    
    LeitorDeArquivo::carregarDadosParaPilha(
        "../../datasets/100000.dat", 
        &pilha
    );
    
    auto start = std::chrono::high_resolution_clock::now();

    InsertionSort::insertionSortPilha(&pilha);
    
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    
    std::cout << "Tempo de execução do Insertion Sort: " << duration.count() << " milissegundos" << std::endl;
    media = media + duration.count();
    }

    media = media/10;
    std::cout << "Media total: " << media << std::endl;

    return 0;
}
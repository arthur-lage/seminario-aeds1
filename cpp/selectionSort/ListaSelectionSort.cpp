#include <iostream>
#include <chrono>
#include "Fila.hpp"
#include "Nodo.hpp"
#include "SelectionSort.hpp"
#include "LeitorDeArquivo.hpp"

int main() {
    Lista lista;
    
    LeitorDeArquivo::carregarDadosParaLista(
        "../../datasets/100.dat", 
        &lista
    );
    
    auto start = std::chrono::high_resolution_clock::now();

    SelectionSort::selectionSortLista(&lista);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;
    
    std::cout << "Tempo de execução do Selection Sort: " << duration.count() << " milissegundos" << std::endl;

    return 0;
}
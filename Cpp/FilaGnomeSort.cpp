#include <iostream>
#include <chrono>
#include "Fila.hpp"
#include "Nodo.hpp"
#include "GnomeSort.hpp"
#include "LeitorDeArquivo.hpp"

int main() {
    Fila fila;
    
    LeitorDeArquivo::carregarDadosParaFila(
        "/home/will/Documentos/AEDS/Seminario/GnomeSort/datasets/100.dat", 
        &fila
    );
    //fila.imprimir(); check aq

    auto start = std::chrono::high_resolution_clock::now();

    GnomeSort::gnomeSortFila(&fila);
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "\nTempo de ordenação: " << duration.count() << " ms" << std::endl;

    return 0;
}
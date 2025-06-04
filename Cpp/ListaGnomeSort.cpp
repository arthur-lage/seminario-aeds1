#include <iostream>
#include <chrono>
#include "Fila.hpp"
#include "Nodo.hpp"
#include "GnomeSort.hpp"
#include "LeitorDeArquivo.hpp"

int main() {
    Lista lista;
    
    LeitorDeArquivo::carregarDadosParaLista(
        "/home/will/Documentos/AEDS/Seminario/GnomeSort/datasets/100.dat", 
        &lista
    );
    
    auto start = std::chrono::high_resolution_clock::now();

    GnomeSort::gnomeSortLista(&lista);
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "\nTempo de ordenação: " << duration.count() << " ms" << std::endl;

    return 0;
}
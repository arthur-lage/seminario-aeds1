#ifndef LEITOR_DE_ARQUIVO_HPP
#define LEITOR_DE_ARQUIVO_HPP

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "Registro.hpp"
#include "Lista.hpp"
#include "Fila.hpp"
#include "Pilha.hpp"

class LeitorDeArquivo {
public:
    static void carregarDadosParaLista(const char* nomeArquivo, Lista* lista);
    static void carregarDadosParaFila(const char* nomeArquivo, Fila* fila);
    static void carregarDadosParaPilha(const char* nomeArquivo, Pilha* pilha);
    static void printRegistro(const Registro& reg);
    static void printLista(const Lista* lista);
    static void printFila(const Fila* fila);
    static void printPilha(const Pilha* pilha);
};

#endif
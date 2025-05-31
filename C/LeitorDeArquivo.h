#ifndef LEITOR_DE_ARQUIVO_H
#define LEITOR_DE_ARQUIVO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Registro.h"

#include "Lista.h"
#include "Fila.h"
#include "Pilha.h"

void carregarDadosParaLista(const char *nomeArquivo, Lista *lista) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        exit(1);
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = 0;
        
        Registro reg;
        int result = sscanf(linha, "%d,%d,%f,%ld", 
                           &reg.usuario, &reg.filme, 
                           &reg.avaliacao, &reg.timestamp);
        
        if (result == 4) {
            inserirNoFinal(lista, reg);
        } else {
            printf("Formato inválido na linha: %s\n", linha);
        }
    }

    fclose(arquivo);
}

void carregarDadosParaFila(const char *nomeArquivo, Fila *fila) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        exit(1);
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = 0;
        
        Registro reg;
        int result = sscanf(linha, "%d,%d,%f,%ld", 
                          &reg.usuario, &reg.filme, 
                          &reg.avaliacao, &reg.timestamp);
        
        if (result == 4) { 
            enfileirar(fila, reg);
        } else {
            printf("Formato inválido na linha: %s\n", linha);
        }
    }

    fclose(arquivo);
}

void carregarDadosParaPilha(const char *nomeArquivo, Pilha *p) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        exit(1);
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = 0;
        
        Registro reg;
        if (sscanf(linha, "%d,%d,%f,%ld", 
                  &reg.usuario, &reg.filme, 
                  &reg.avaliacao, &reg.timestamp) == 4) {
            empilhar(p, reg);
        }
    }
    fclose(arquivo);
}

#endif
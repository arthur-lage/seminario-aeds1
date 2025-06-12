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

void carregarDadosParaListaVetor(const char *nomeArquivo, ListaVetor *lista) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        exit(1);
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo) && !listaCheiaVetor(lista)) {
        linha[strcspn(linha, "\n")] = 0;
        
        Registro reg;
        int result = sscanf(linha, "%d,%d,%f,%ld", 
                          &reg.usuario, &reg.filme, 
                          &reg.avaliacao, &reg.timestamp);
        
        if (result == 4) {
            inserirNoFinalVetor(lista, reg);
        } else {
            printf("Formato inválido na linha: %s\n", linha);
        }
    }

    if (listaCheiaVetor(lista) && !feof(arquivo)) {
        printf("Atenção: Lista atingiu capacidade máxima (%d registros)\n", MAXTAM);
    }

    fclose(arquivo);
}

void carregarDadosParaPilhaVetor(const char *nomeArquivo, PilhaVetor *P) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        exit(1);
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo) && !pilhaCheiaVetor(P)) {
        linha[strcspn(linha, "\n")] = 0;
        
        Registro reg;
        if (sscanf(linha, "%d,%d,%f,%ld", 
                  &reg.usuario, &reg.filme, 
                  &reg.avaliacao, &reg.timestamp) == 4) {
            empilharVetor(P, reg);
        }
    }

    if (pilhaCheiaVetor(P) && !feof(arquivo)) {
        printf("Atenção: Pilha atingiu capacidade máxima (%d registros)\n", MAXTAM);
    }

    fclose(arquivo);
}

void carregarDadosParaFilaVetor(const char *nomeArquivo, FilaVetor *Q) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        exit(1);
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo) && !filaCheiaVetor(Q)) {
        linha[strcspn(linha, "\n")] = 0;
        
        Registro reg;
        if (sscanf(linha, "%d,%d,%f,%ld", 
                  &reg.usuario, &reg.filme, 
                  &reg.avaliacao, &reg.timestamp) == 4) {
            enfileirarVetor(Q, reg);
        }
    }

    if (filaCheiaVetor(Q) && !feof(arquivo)) {
        printf("Atenção: Fila atingiu capacidade máxima (%d registros)\n", MAXTAM);
    }

    fclose(arquivo);
}
#endif
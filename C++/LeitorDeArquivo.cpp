#include "LeitorDeArquivo.hpp"

void LeitorDeArquivo::carregarDadosParaLista(const char *nomeArquivo, Lista *lista) {
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
            lista->inserirNoFinal(reg);
        } else {
            printf("Formato inválido na linha: %s\n", linha);
        }
    }

    fclose(arquivo);
}

void LeitorDeArquivo::carregarDadosParaFila(const char *nomeArquivo, Fila *fila) {
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
            fila->enfileirar(reg);
        } else {
            printf("Formato inválido na linha: %s\n", linha);
        }
    }

    fclose(arquivo);
}

void LeitorDeArquivo::carregarDadosParaPilha(const char *nomeArquivo, Pilha *p) {
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
            p->empilhar(reg);
        }
    }
    fclose(arquivo);
}

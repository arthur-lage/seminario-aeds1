# Seminario AEDS: Algoritmos de Ordenação em C

Este repositório contém implementações em C de três algoritmos de ordenação clássicos: **Insertion Sort**, **Selection Sort** e **Gnome Sort**. Cada algoritmo possui características específicas que o tornam mais ou menos adequado para diferentes cenários.

## 🔄 Insertion Sort
O **Insertion Sort** é um algoritmo simples que constrói a lista ordenada um item de cada vez, movendo elementos para a posição correta através de comparações. É eficiente para conjuntos de dados pequenos ou quase ordenados, com complexidade:
- **Pior caso**: O(n²)
- **Melhor caso**: O(n) (quando a lista já está ordenada)

## 🔍 Selection Sort
O **Selection Sort** divide a lista em duas partes:
1. Sublista ordenada
2. Sublista não ordenada

A cada iteração, encontra o menor elemento da sublista não ordenada e o move para o final da sublista ordenada. Sua complexidade é sempre **O(n²)**, tornando-o menos eficiente para listas grandes, porém com as vantagens:
- Implementação simples
- Uso mínimo de memória

## 🧙 Gnome Sort
O **Gnome Sort** (ou "Stupid Sort") é um algoritmo baseado em comparações que funciona similar ao Insertion Sort, mas com implementação mais simples. Características:
- Complexidade:
  - Pior caso: O(n²)
  - Melhor caso: O(n) (lista ordenada)
- Funcionamento: Percorre a lista comparando elementos adjacentes e os troca quando desordenados

## 🛠 Compilação e Execução
- Em C:
```bash
# Comando para compilar um programa específico
gcc arquivo.c -o ./programa

# Executar o programa
./programa
```

- Em C++:
```bash
# Comando para compilar um programa específico
gcc arquivo.c -o ./programa

# Executar o programa
./programa
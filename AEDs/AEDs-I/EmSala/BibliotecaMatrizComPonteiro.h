#ifndef MATRIZCOMPONTEIRO_H
#define MATRIZCOMPONTEIRO_H
/*
* objetivo: Criar uma biblioteca para manipulação de matrizes usando ponteiros.
* Autor: Diego Vianna Leite Montemor
* matricula: 2025.1.08.023
* materia: AEDs 1 - Prática
*/


const int TAM = 128;
typedef int Vetor[TAM][TAM];

void MultiplicarValores(Vetor matriz, int linhas, int colunas, int valor);
void TransporMatriz(Vetor matriz, int linhas, int colunas, Vetor transposta);
void InverterColunas(Vetor matriz, int linhas, int colunas);
void InverterLinhas(Vetor matriz, int linhas, int colunas);


#endif
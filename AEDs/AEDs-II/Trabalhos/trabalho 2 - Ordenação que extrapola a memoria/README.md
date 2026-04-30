# Trabalho 2 - Ordenação que Extrapola a Memória

Este trabalho da disciplina de AEDs implementa uma ordenação externa de números inteiros. A ideia é tratar um arquivo de entrada grande, dividindo os dados em blocos que cabem na memória, ordenando cada bloco e depois fazendo a fusão desses blocos para gerar um arquivo final ordenado.

## Objetivo

O projeto foi desenvolvido para exercitar leitura e escrita de arquivos, alocação dinâmica de memória e uma estratégia de ordenação adequada para conjuntos de dados maiores do que a memória disponível em uma única etapa.

## Como funciona

1. O programa lê o arquivo entrada_desordenada.txt.
2. O usuário informa quantos números cabem na memória, definindo o tamanho de cada bloco.
3. Cada bloco é carregado em memória, ordenado com Quick Sort e salvo em um arquivo temporário chamado bloco_X.txt.
4. Depois que todos os blocos são criados, o programa faz o merge dos blocos já ordenados.
5. O resultado final é gravado em saida_ordenada.txt.
6. Ao final, os arquivos temporários de bloco são removidos.

## Estrutura dos arquivos

- OrdenacaoDoArquivo(trabalho2)/main.c: ponto de entrada do programa.
- OrdenacaoDoArquivo(trabalho2)/ordenacao.c: implementa o Quick Sort, a criação dos blocos e a fusão final.
- OrdenacaoDoArquivo(trabalho2)/ordenacao.h: declarações das funções do projeto.
- OrdenacaoDoArquivo(trabalho2)/Makefile: automatiza a compilação.
- GeradorDoArquivo/main.cpp: utilitário separado para gerar o arquivo de entrada.

## Compilação

O projeto principal está na pasta OrdenacaoDoArquivo(trabalho2).

Com Make:

1. Abra o terminal nessa pasta.
2. Execute:
   make

Sem Make:

1. Compile manualmente com GCC:
   gcc -Wall -g -pedantic -std=c11 -c main.c ordenacao.c
2. Faça o link dos objetos gerados:
   gcc -o ordenacaoDeArquivo.exe main.o ordenacao.o

## Execução

Depois de compilado, execute o programa na mesma pasta onde está o arquivo entrada_desordenada.txt.

No Windows:

1. Rode o executável gerado.
2. Informe no terminal o tamanho do bloco que cabe na memória.

Exemplo:

1. ordenacaoDeArquivo.exe
2. Digite quantos números cabem na memória.

## Arquivos de entrada e saída

- entrada_desordenada.txt: arquivo com os números desordenados.
- saida_ordenada.txt: arquivo final gerado pelo programa, já em ordem crescente.
- bloco_X.txt: arquivos temporários criados durante a execução.

## Observações

- A ordenação interna dos blocos é feita com Quick Sort.
- A fusão final percorre os blocos temporários e escolhe o menor valor disponível a cada passo.
- O valor informado pelo usuário define o limite de números carregados em memória em cada bloco.
- O programa foi pensado para cenários em que o arquivo não cabe inteiro na memória de uma vez.

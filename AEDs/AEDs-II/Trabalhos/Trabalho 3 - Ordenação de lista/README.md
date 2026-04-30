# Trabalho 3 - Ordenação de Lista

Este trabalho da disciplina de AEDs implementa a ordenação de uma lista de jogadores lida a partir de um arquivo CSV. O programa permite escolher entre três algoritmos de ordenação e exibe, ao final, o tempo de execução e métricas de desempenho.

## Objetivo

O projeto foi desenvolvido para exercitar leitura de arquivos, manipulação de estruturas, comparação entre algoritmos de ordenação e análise básica de desempenho.

## Como funciona

1. O programa lê o arquivo jogadores.csv.
2. Os registros são armazenados em memória como estruturas do tipo Jogador.
3. O usuário escolhe um dos algoritmos de ordenação disponíveis.
4. O vetor é ordenado pelo nome do jogador.
5. O resultado é impresso no terminal junto com as métricas coletadas durante a execução.

## Algoritmos disponíveis

1. Ordenação Simples: Bubble Sort.
2. Ordenação Ótima: Merge Sort.
3. Ordenação Linear: Radix Sort aplicado sobre os nomes.

## Estrutura dos arquivos

- main.c: lê o arquivo CSV, executa a ordenação escolhida e imprime os resultados.
- jogadores.csv: base de dados usada como entrada.
- makefile: automatiza a compilação do projeto.
- Relatorio do Trabalho Prático 3 - AEDs 2.pdf: relatório do trabalho.

## Saída do programa

Depois da ordenação, o programa exibe no terminal:

- a lista de jogadores ordenada;
- o tempo total de execução em milissegundos;
- o número de comparações;
- o número de movimentações;
- a estimativa de memória usada.

## Compilação

O projeto pode ser compilado com GCC.

Com Make:

1. Abra o terminal na pasta do trabalho.
2. Execute:
   make

Sem Make:

1. Compile manualmente com GCC:
   gcc -Wall -Wextra -g -pedantic main.c -o ordenacao

## Execução

Depois de compilado, execute o programa na mesma pasta onde está o arquivo jogadores.csv.

1. Rode o executável gerado.
2. Escolha um algoritmo informando:
   - 1 para Bubble Sort;
   - 2 para Merge Sort;
   - 3 para Radix Sort.

Exemplo:

1. ./ordenacao
2. Digite 2 para ordenar com Merge Sort.

No Windows, o executável pode aparecer como ordenacao.exe.

## Observações

- A ordenação é feita pelo nome do jogador.
- O programa usa locale para respeitar a ordenação de caracteres especiais quando possível.
- As métricas exibidas ao final ajudam a comparar o comportamento dos algoritmos.

# Trabalho 2 - Comparação de Sequências de DNA

Este trabalho da disciplina de AEDs-III implementa a comparação entre duas sequências de DNA usando duas abordagens distintas: programação dinâmica e algoritmo guloso. O programa lê duas strings de entrada, calcula a pontuação obtida por cada estratégia e exibe o resultado com o tempo de execução de cada uma.

## Objetivo

O projeto foi desenvolvido para praticar leitura de arquivos, manipulação de strings, alocação dinâmica de memória e comparação entre estratégias de resolução de problemas de alinhamento de sequências.

## Como funciona

1. O programa recebe o caminho de um arquivo de entrada pela linha de comando.
2. Esse arquivo deve conter duas linhas, uma para cada sequência de DNA.
3. As sequências são carregadas dinamicamente em memória.
4. O programa executa duas análises:
   - programação dinâmica;
   - solução gulosa.
5. Para cada abordagem, o programa mostra a pontuação final e o tempo gasto.

## Regras de pontuação

As funções do projeto consideram os seguintes critérios:

- A com T ou T com A soma 2 pontos.
- C com G ou G com C soma 2 pontos.
- Lacunas penalizam a pontuação.
- Comparações que não formam par válido recebem penalidade.

## Estrutura dos arquivos

- base.c: arquivo principal do projeto, responsável pela leitura do arquivo e pela execução das análises.
- algoritmos.c: implementação da programação dinâmica e da abordagem gulosa.
- algoritmos.h: declarações das funções utilizadas no projeto.
- instancias/: pasta com arquivos de teste.
- makefile: automatiza a compilação do trabalho.

## Formato do arquivo de entrada

O arquivo de entrada deve conter exatamente duas linhas, por exemplo:

ATCGTAC
TACGATC

Cada linha representa uma sequência de DNA composta pelos caracteres A, T, C e G.

## Compilação

O projeto pode ser compilado com GCC.

Com Make:

1. Abra o terminal na pasta do trabalho.
2. Execute:
   make

Sem Make:

1. Compile os arquivos manualmente:
   gcc -Wall -Wextra -g base.c algoritmos.c -o base

## Execução

O programa recebe o caminho do arquivo como argumento.

Exemplo:

1. ./base instancias/100-1

Na pasta de teste também existem várias instâncias com tamanhos diferentes para comparação.

Se desejar usar a regra auxiliar do Makefile, execute:

1. make run

## Saída do programa

Ao final, o programa imprime:

- o resultado da programação dinâmica;
- o tempo de execução da programação dinâmica;
- o resultado do algoritmo guloso;
- o tempo de execução do algoritmo guloso.

## Observações

- O arquivo base.c já está definido como parte fixa da avaliação e não deve ser alterado.
- O programa libera a memória alocada dinamicamente após o uso.
- Os arquivos da pasta instancias servem como casos de teste para validar o comportamento das implementações.

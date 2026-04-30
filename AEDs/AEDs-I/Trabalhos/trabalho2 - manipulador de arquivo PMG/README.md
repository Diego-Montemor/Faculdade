# Trabalho 2 - Manipulador de Arquivo PGM

Este trabalho da disciplina de AEDs-I implementa um manipulador de imagens em C++. O programa lê uma imagem no formato PGM P2, aplica transformações escolhidas pelo usuário e salva o resultado em novos arquivos de imagem.

## Objetivo

O projeto foi desenvolvido para praticar leitura e escrita de arquivos, uso de ponteiros, manipulação de matrizes lineares e operações básicas de processamento de imagens.

## Como funciona

1. O programa lê a imagem de entrada no arquivo converted_image.pgm.
2. A imagem é carregada em memória como um vetor de pixels inteiros.
3. O usuário escolhe uma operação no menu.
4. O programa gera uma nova imagem PGM com o resultado da transformação escolhida.

## Funcionalidades

- Ajuste de brilho.
- Rotação da imagem em 90 graus para a direita, 180 graus ou -90 graus.
- Inversão de cores.
- Binarização da imagem.
- Redução da imagem para 64x64 pixels.

## Arquivos gerados

Dependendo da opção escolhida, o programa salva:

- ImagemComBrilhoAjustado.pgm
- ImagemRotacionada.pgm
- ImagemInversa.pgm
- ImagemBinarizada.pgm
- ImagemIconizada.pgm

## Formato da entrada

O arquivo de entrada deve estar no formato PGM P2 e conter:

- a assinatura P2;
- a largura e a altura da imagem;
- o valor máximo do pixel;
- a sequência dos pixels em texto.

## Estrutura do programa

- main.cpp: lê a imagem, mostra o menu e chama as funções de processamento.
- converted_image.pgm: imagem original usada como entrada.

## Compilação

O projeto pode ser compilado com g++.

Exemplo:

1. Abra o terminal na pasta do trabalho.
2. Execute:
   g++ -Wall -Wextra -pedantic -std=c++11 main.cpp -o manipulador_pgm

## Execução

Depois de compilado, execute o programa na mesma pasta onde está o arquivo converted_image.pgm.

1. Rode o executável gerado.
2. Escolha uma opção do menu.
3. Informe os dados adicionais quando o programa solicitar.

## Observações

- O programa valida se a imagem está no formato P2.
- As transformações são feitas em memória e o resultado é salvo em um novo arquivo PGM.
- A opção de iconização gera uma imagem com 64x64 pixels.

# Trabalho 1 - Verificação de Palíndromo

Este trabalho da disciplina de AEDs implementa um verificador de palíndromos em linguagem C. O programa lê um arquivo de entrada com uma palavra ou frase por linha, normaliza o texto e informa se cada linha é ou não um palíndromo.

## Objetivo

O projeto foi desenvolvido para praticar manipulação de strings, uso de arquivos e organização de dados com ponteiros e estrutura dinâmica.

## Como funciona

1. O programa abre o arquivo data.txt.
2. Cada linha é lida e removida a quebra de linha.
3. O texto é normalizado:
   - converte letras para minúsculas;
   - remove espaços e sinais de pontuação;
   - trata alguns caracteres acentuados em UTF-8, como á, é, í, ó, ú e ç.
4. Em seguida, o conteúdo é verificado como palíndromo.
5. O resultado de cada linha é exibido no terminal e gravado em saida.txt.

## Estrutura dos arquivos

- main.c: responsável pela leitura do arquivo de entrada e pela escrita do resultado.
- Palindromo.c: contém a normalização do texto e a verificação do palíndromo.
- Palindromo.h: declarações de estruturas e funções do projeto.
- data.txt: arquivo de entrada com os testes.
- saida.txt: arquivo gerado com os resultados.
- makefile: automatiza a compilação do projeto.

## Compilação

O projeto pode ser compilado com GCC.

Com Make:

1. Abra o terminal na pasta do trabalho.
2. Execute o comando:
   make

Sem Make:

1. Compile os arquivos manualmente:
   gcc -Wall -Wextra -Wpedantic -std=c11 -O2 main.c Palindromo.c -o palindromo

## Execução

Depois de compilado, execute o programa na mesma pasta onde estão data.txt e saida.txt:

1. Com Make:
   make run
2. Ou executando o binário gerado:
   ./palindromo

No Windows, o executável pode aparecer como palindromo.exe.

## Exemplo de entrada

O arquivo data.txt contém exemplos como:

- Ana
- Maria
- 12/3/21
- 01010
- OtTo
- Ônibus

## Exemplo de saída

Para o arquivo fornecido, o programa gera:

- 1
- 0
- 1
- 1
- 1
- 0

## Observações

- A verificação considera apenas letras e números.
- O texto é comparado já normalizado, então diferenças de maiúsculas, espaços e pontuação não interferem no resultado.
- O tratamento de acentos cobre os caracteres usados no português que aparecem no projeto.

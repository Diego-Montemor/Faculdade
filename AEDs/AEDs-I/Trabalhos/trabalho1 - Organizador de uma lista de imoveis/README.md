# Trabalho 1 - Organizador de uma Lista de Imóveis

Este trabalho da disciplina de AEDs implementa um sistema simples de gerenciamento de imóveis em C++. O programa permite cadastrar novos imóveis, buscar registros por diferentes critérios, listar todos os imóveis, gerar estatísticas e excluir registros do banco de dados em memória.

## Objetivo

O projeto foi desenvolvido para exercitar programação estruturada, manipulação de registros, uso de vetores e construção de menus interativos em console.

## Como funciona

1. O programa carrega os dados a partir do arquivo BD_Imoveis2.txt.
2. Os imóveis são armazenados em uma estrutura com campos como tipo, finalidade, endereço, bairro, cidade, área, valor e características adicionais.
3. O usuário interage com um menu principal para escolher a operação desejada.
4. As ações disponíveis incluem inclusão, busca, relatório, listagem e exclusão.

## Funcionalidades

- Inclusão de um novo imóvel.
- Busca de imóveis por tipo, finalidade, endereço, bairro, cidade, área ou valor.
- Relatório de estatísticas.
- Listagem de todos os imóveis disponíveis.
- Exclusão de um imóvel.

## Estrutura dos arquivos

- main.cpp: arquivo principal do sistema de gerenciamento de imóveis.
- BD_Imoveis2.txt: base de dados usada como entrada.
- README.md: documentação do trabalho.

## Formato dos dados

Cada imóvel é representado por campos como:

- tipo;
- finalidade;
- endereço;
- bairro;
- cidade;
- área;
- valor;
- IPTU;
- quartos, suítes, banheiros e vagas;
- características como cozinha, sala, varanda, área de serviço, piso, estado, armários, ar-condicionado, aquecedor e ventilador.

## Execução

O projeto pode ser executado em qualquer ambiente que suporte C++ e entrada interativa via console.

1. Compile o arquivo main.cpp.
2. Execute o programa.
3. Utilize o menu para navegar pelas opções do sistema.

## Observações

- O arquivo BD_Imoveis2.txt serve como base inicial dos registros.
- Ao cadastrar imóveis, o programa solicita que espaços sejam substituídos por underscores em alguns campos.
- Os imóveis são manipulados em memória durante a execução do sistema.

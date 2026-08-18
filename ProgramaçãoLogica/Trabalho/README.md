# Trabalho de Programação Lógica (Prolog)

Descrição

- Arquivo principal: `TrabalhoProlog.pl` — implementa soluções para os exercícios do trabalho em Prolog.
- Autor: Diego Vianna Leite Montemor (identificação no cabeçalho do arquivo).

Objetivo

- Implementar operações sobre listas e ordenação conforme os exercícios: cálculo de tamanho, verificação e ordenação (bubble sort por tamanho), e ordenação por frequência de comprimentos (lfsort).

Conteúdo

- `TrabalhoProlog.pl` — predicados implementados:
  - `tamlista/2` — calcula o tamanho de uma lista.
  - `troca/2`, `confere/1`, `lsort/2` — implementação de bubble sort por tamanho de sublistas.
  - `comprimento/2`, `frequenciaComprimento/2`, `associarFrequencia/3` — auxiliares para cálculo de frequências.
  - `ordena/2`, `ordenaFrequencia/2`, `lfsort/2` — ordenação por frequência de comprimentos.

Requisitos

- SWI-Prolog (recomenda-se a versão mais recente disponível).

Como executar

1. Abra o terminal e acesse a pasta do trabalho:

```powershell
cd "ProgramaçãoLogica\Trabalho"
```

2. Inicie o SWI-Prolog e carregue o arquivo:

```prolog
?- ['TrabalhoProlog.pl'].  % ou: consult('TrabalhoProlog.pl').
```

3. Exemplos de consultas:

```prolog
?- tamlista([a,b,c], N).
% N = 3.

?- lsort([[a,b],[c],[d,e,f]], R).
% R = [[c],[a,b],[d,e,f]].

?- lfsort([[a,b],[c],[d,e,f],[g]], R).
% Ordena as sublistas de acordo com a frequência de seus comprimentos.
```

Observações e dicas

- Os predicados usam recursão e manipulação de listas; revise as definições para entender os passos de ordenação.
- Para depuração, consulte consultas intermediárias como `comprimento/2` e `frequenciaComprimento/2`.
- Caso queira executar testes automáticos, é possível criar um arquivo de testes (por exemplo, usando `plunit`) e carregá-lo via `run_tests/0`.

Licença

- Uso acadêmico: redistribuição e modificação permitidas para fins de estudo.

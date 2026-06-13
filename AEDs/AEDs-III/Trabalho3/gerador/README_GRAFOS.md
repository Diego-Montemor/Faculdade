# Gerador de Grafos para Análise de Algoritmos

Script Python que gera múltiplos grafos conforme especificado no trabalho prático.

## Requisitos

- Python 3.7+
- NetworkX
- Módulo `generator.py` no mesmo diretório

## Instalação

Instale as dependências:

```bash
pip install -r requirements.txt
```

## Uso

Execute o script:

```bash
python generate_graphs.py
```

## Configuração

O script gera grafos das seguintes topologias:

1. **Erdős-Rényi** (`erdos`)
   - Parâmetro: p = 0.1 (probabilidade de aresta)
   - 10 grafos de 500 a 10000 nós

2. **Barabási-Albert** (`barabasi`)
   - Parâmetro: m = 3 (arestas por novo nó)
   - 10 grafos de 500 a 10000 nós

3. **Watts-Strogatz** (`watts`)
   - Parâmetros: k = 4, p = 0.3
   - 10 grafos de 500 a 10000 nós

Total: **30 grafos gerados** em 3 topologias diferentes

## Saída

Os grafos são salvos em:

```
gerador/grafos_gerados/
├── erdos/
│   ├── erdos_500_n1.txt
│   ├── erdos_1000_n2.txt
│   └── ...
├── barabasi/
│   ├── barabasi_500_n1.txt
│   └── ...
└── watts/
    ├── watts_500_n1.txt
    └── ...
```

## Formato dos Arquivos

Cada arquivo contém:

```
<num_nós> <num_arestas>
<nó1> <nó2> <peso1>
<nó3> <nó4> <peso2>
...
```

## Notas

- Cada topologia gera 10 grafos com tamanhos entre 500 e 10000 vértices
- Os grafos são garantidos como conexos
- Os pesos das arestas são números aleatórios entre 1 e 100
- A execução pode levar alguns minutos dependendo da máquina

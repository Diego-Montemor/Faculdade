# 🔬 Guia Completo - Gerador de Grafos para Análise de Caminhos Mais Curtos

Este projeto fornece um conjunto de ferramentas Python para gerar grafos conforme especificado no trabalho prático 3 (AEDS 3 - UNIFAL).

## 📋 Requisitos

- Python 3.7+
- NetworkX instalado

### Instalação de dependências:

```bash
pip install -r requirements.txt
```

## 🚀 Scripts Disponíveis

### 1. **test_generator.py** - Teste Rápido (⏱️ ~2 minutos)

Para validar que tudo está funcionando corretamente:

```bash
python test_generator.py
```

**O que faz:**

- Gera 6 grafos de teste (pequenos: 100-300 nós)
- Valida a instalação e o gerador
- Salva em `grafos_gerados_teste/`

**Quando usar:** Primeira execução para verificar se está tudo OK.

---

### 2. **generate_graphs.py** - Geração Padrão (⏱️ ~30-45 minutos)

Para gerar todos os grafos conforme especificado no PDF:

```bash
python generate_graphs.py
```

**O que faz:**

- Gera 30 grafos total
- 3 topologias diferentes
- 10 grafos por topologia
- Tamanhos entre 500 e 10000 nós
- Salva em `grafos_gerados/`

**Topologias:**

1. **Erdős-Rényi** (aleatório, p=0.1)
2. **Barabási-Albert** (sem escala, m=3)
3. **Watts-Strogatz** (mundo pequeno, k=4, p=0.3)

**Tamanhos de nós:**
500, 1000, 1500, 2000, 2500, 3000, 4000, 5000, 7500, 10000

---

### 3. **generate_graphs_advanced.py** - Geração Customizável (⏱️ variável)

Para controle total sobre a geração:

```bash
python generate_graphs_advanced.py
```

**Vantagens:**

- Saída formatada e bem organizada
- Log detalhado em JSON
- Estatísticas automáticas
- Fácil de modificar parâmetros

---

### 4. **analyze_graphs.py** - Análise dos Grafos (⏱️ instantâneo)

Para visualizar informações dos grafos gerados:

```bash
python analyze_graphs.py
```

**O que mostra:**

- Resumo geral de geração
- Estatísticas por topologia
- Número de nós e arestas
- Tamanho dos arquivos
- Médias e totais

---

## 📁 Estrutura de Saída

Após a execução, os grafos são organizados assim:

```
grafos_gerados/
├── erdos/
│   ├── erdos_500_n1.txt
│   ├── erdos_1000_n2.txt
│   └── ... (10 grafos)
├── barabasi/
│   ├── barabasi_500_n1.txt
│   └── ... (10 grafos)
├── watts/
│   ├── watts_500_n1.txt
│   └── ... (10 grafos)
└── generation_log.json
```

---

## 📊 Formato dos Arquivos de Grafo

Cada arquivo `.txt` contém:

```
<número_de_nós> <número_de_arestas>
<nó_origem> <nó_destino> <peso>
<nó_origem> <nó_destino> <peso>
...
```

**Exemplo:**

```
20 37
0 1 42
0 2 15
1 3 89
...
```

---

## 🔧 Configuração Customizada

Para modificar as topologias ou parâmetros, edite o arquivo do script e altere o dicionário `topologies`:

```python
topologies = {
    "complete": {
        "description": "Grafo Completo",
        "params": []  # Sem parâmetros adicionais
    },
    "regular": {
        "description": "Grafo Regular",
        "params": [5]  # grau = 5
    }
}
```

**Topologias disponíveis no generator.py:**

- `complete` - Grafo completo
- `erdos` - Erdős-Rényi (parâmetro: p)
- `watts` - Watts-Strogatz (parâmetros: k, p)
- `barabasi` - Barabási-Albert (parâmetro: m)
- `turan` - Turán (parâmetro: r)
- `powerlaw` - Power Law Cluster (parâmetros: m, p)
- `regular` - Regular (parâmetro: d)
- `udg_u` - UDG uniforme (parâmetro: radius)
- `udg_r` - UDG aleatório (parâmetro: radius)

---

## ⏱️ Tempo de Execução Estimado

| Script                      | Grafos | Tempo Estimado |
| --------------------------- | ------ | -------------- |
| test_generator.py           | 6      | 2-3 min        |
| generate_graphs.py          | 30     | 30-45 min      |
| generate_graphs_advanced.py | 30     | 30-45 min      |
| analyze_graphs.py           | -      | Instantâneo    |

> **Nota:** O tempo varia conforme a máquina. Grafos maiores (10000 nós) levam mais tempo.

---

## 🐛 Solução de Problemas

### "ImportError: No module named 'networkx'"

```bash
pip install networkx
```

### "Error: Not enough arguments provided"

Certifique-se de que o `generator.py` está no mesmo diretório dos scripts.

### Gerador muito lento

- Grafos de 10000 nós podem levar 1-2 minutos cada
- Reduzir o tamanho máximo de nós se necessário
- Executar em máquina com mais poder computacional

### Arquivo de grafo vazio ou corrompido

O gerador tenta 10 vezes gerar um grafo conexo antes de desistir. Se falhar, tente novamente.

---

## 📈 Próximos Passos

Após gerar os grafos:

1. **Implementar os algoritmos** em C/C++
2. **Criar executáveis** que leem os grafos
3. **Medir tempos de execução** para cada algoritmo
4. **Compilar resultados** em tabelas/gráficos para o relatório

---

## 📝 Notas Importantes

✅ **Todos os grafos são garantidos como conexos**
✅ **Pesos das arestas variam entre 1 e 100**
✅ **Coordenadas dos nós variam entre 0 e 100**
✅ **Seed aleatória é diferente para cada geração**

---

## 👨‍💻 Autor

Scripts desenvolvidos para o trabalho prático 3 - AEDS 3 (UNIFAL)

---

**Data de entrega:** 12/05/2025 às 08h00 no Moodle

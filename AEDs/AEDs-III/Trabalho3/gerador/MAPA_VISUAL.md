# 🗺️ MAPA VISUAL - Gerador de Grafos

## Fluxo de Uso Recomendado

```
┌─────────────────────────────────────────────────────────────┐
│              COMEÇAR AQUI: python menu.py                   │
└────────────────┬────────────────────────────────────────────┘
                 │
                 ▼
        ┌────────────────────┐
        │   MENU PRINCIPAL   │
        └──────┬─────────────┘
               │
        ┌──────┴──────┬──────────┬────────────┬────────────┐
        │             │          │            │            │
        ▼             ▼          ▼            ▼            ▼
      [1]          [2]        [3]          [4]          [5]
     TESTE       GERAR      AVANÇADO     ANALISAR     GUIA
    RÁPIDO      PADRÃO       (custom)      GRAFOS     (help)
     (2-3       (30-45        (30-45      (instant)   (ler
      min)       min)          min)                    docs)
      │           │             │            │          │
      ▼           ▼             ▼            ▼          ▼
   Valida    Gera 30        Gera 30     Mostra       LEIA:
   Instala   grafos         grafos     estatís.   GUIA_
   ção       automático    customiz.   JSON      COMPLETO
             3 topologias  3 topolo.   & tabelas   .md
             10 cada       10 cada
```

---

## Estrutura de Diretórios

```
Nova pasta/
│
├─ codigo/                    ← Seus algoritmos em C/C++
│  ├─ algorithms.c
│  ├─ algorithms.h
│  └─ makefile
│
└─ gerador/                   ← AQUI VOCÊ ESTÁ
   │
   ├─ 🎯 COMECE AQUI
   │  ├─ 00_LEIA_PRIMEIRO.md          ← Você está aqui
   │  ├─ INDICE.md                    ← Mapa de documentos
   │  └─ python menu.py               ← Menu interativo
   │
   ├─ 🐍 SCRIPTS (execute estes)
   │  ├─ test_generator.py            ← Teste rápido (2-3 min)
   │  ├─ generate_graphs.py           ← Gerar 30 grafos (30-45 min)
   │  ├─ generate_graphs_advanced.py  ← Versão customizável
   │  ├─ analyze_graphs.py            ← Ver estatísticas
   │  └─ menu.py                      ← Escolha qual executar
   │
   ├─ 📚 DOCUMENTAÇÃO (leia se tiver dúvidas)
   │  ├─ INICIO_RAPIDO.md             ← 3 passos (2 min)
   │  ├─ GUIA_COMPLETO.md             ← Detalhes (30 min)
   │  ├─ README_GRAFOS.md             ← Formato dos grafos
   │  ├─ RESUMO_SCRIPTS.md            ← O que foi criado
   │  ├─ CHECKLIST_COMPLETO.md        ← Validação
   │  └─ INDICE.md                    ← Índice de tudo
   │
   ├─ 🔧 UTILITÁRIOS
   │  └─ executar.bat                 ← Para Windows (clique duplo)
   │
   ├─ 📋 ORIGINAIS
   │  ├─ generator.py                 ← Fornecido (não editar)
   │  └─ requirements.txt             ← pip install networkx
   │
   └─ 📁 SAÍDA (criada ao executar)
      └─ grafos_gerados/
         ├─ erdos/                    ← 10 grafos
         │  ├─ erdos_500_n1.txt
         │  ├─ erdos_1000_n2.txt
         │  └─ ... (até 10000 nós)
         │
         ├─ barabasi/                 ← 10 grafos
         │  ├─ barabasi_500_n1.txt
         │  └─ ... (até 10000 nós)
         │
         ├─ watts/                    ← 10 grafos
         │  ├─ watts_500_n1.txt
         │  └─ ... (até 10000 nós)
         │
         └─ generation_log.json       ← Estatísticas
```

---

## Decisão Rápida

```
┌─ O QUE VOCÊ QUER?
│
├─ "Quero começar AGORA"
│  └─ Execute: python menu.py
│
├─ "Quero testar rapidinho"
│  └─ Execute: python test_generator.py
│
├─ "Quero gerar os 30 grafos"
│  └─ Execute: python generate_graphs.py
│     (deixe rodando por ~40 min)
│
├─ "Quero ver os resultados"
│  └─ Execute: python analyze_graphs.py
│
├─ "Quero entender como funciona"
│  └─ Leia: GUIA_COMPLETO.md
│
├─ "Estou no Windows"
│  └─ Clique duplo: executar.bat
│
├─ "Algo não funciona"
│  └─ Leia: GUIA_COMPLETO.md (troubleshooting)
│
└─ "Quero customizar"
   └─ Edite: generate_graphs_advanced.py
      Leia: GUIA_COMPLETO.md (configuração)
```

---

## Timeline Típico

```
T=0 min
├─ Abrir terminal
├─ pip install networkx
└─ python menu.py

T=1 min
├─ Escolher opção 1 (teste)
└─ Aguardar 2-3 minutos

T=4 min
├─ Ver resultado: ✅ 6 grafos gerados
└─ Escolher opção 2 (gerar tudo)

T=5 min
├─ Começa geração de 30 grafos
└─ Pode fechar e voltar depois

T=45-50 min (30-45 min depois)
├─ Geração termina
├─ Executar: python analyze_graphs.py
└─ Ver estatísticas: 30 grafos prontos

T=51 min
├─ Grafos em: gerador/grafos_gerados/
└─ Usar em seu código C/C++
```

---

## Formato dos Grafos Gerados

```
Arquivo: erdos_500_n1.txt
Conteúdo:

500 1547              ← 500 nós, 1547 arestas
0 1 42               ← Nó 0 conectado a Nó 1, peso 42
0 2 15               ← Nó 0 conectado a Nó 2, peso 15
0 5 89
1 2 67
1 3 23
...
499 498 51
```

**Como usar em C/C++:**

```c
// Abrir arquivo
FILE *f = fopen("erdos_500_n1.txt", "r");

// Ler primeira linha
int n, m;
fscanf(f, "%d %d", &n, &m);

// Ler arestas
for (int i = 0; i < m; i++) {
    int u, v, weight;
    fscanf(f, "%d %d %d", &u, &v, &weight);
    // Adicionar aresta na matriz/adjacência
}
```

---

## Checklist de Execução

```
ANTES DE COMEÇAR:
☐ Tenho Python 3.7+ instalado
☐ Estou na pasta: Nova pasta/gerador/

PREPARAÇÃO:
☐ pip install networkx

TESTE RÁPIDO (2-3 min):
☐ python test_generator.py
☐ Resultado: ✅ 6 grafos gerados

GERAÇÃO COMPLETA (30-45 min):
☐ python generate_graphs.py
☐ Resultado: ✅ 30 grafos em grafos_gerados/

VALIDAÇÃO:
☐ python analyze_graphs.py
☐ Ver: 30 grafos, estatísticas, tamanhos

PRONTO PARA CÓDIGO C/C++:
☐ Grafos em: grafos_gerados/erdos/, /barabasi/, /watts/
☐ Implementar algoritmos
☐ Medir tempos
☐ Criar relatório
```

---

## Resposta Rápida para Erros

```
"ImportError: No module named 'networkx'"
└─ Execute: pip install networkx

"ModuleNotFoundError: No module named 'secrets'"
└─ Use Python 3.6+ (update Python)

"generator.py not found"
└─ Certifique-se que está em gerador/

"Permission denied on executar.bat"
└─ Clique direito → "Executar como administrador"

"Timeout while generating graphs"
└─ Grafos grandes podem levar tempo
└─ Tente novamente ou reduza tamanho máximo
```

---

## Próximos Passos Após Gerar Grafos

```
1. GRAFOS GERADOS ✅
   └─ Localização: grafos_gerados/

2. IMPLEMENTAR ALGORITMOS
   ├─ Algoritmo de Duan (obrigatório)
   ├─ Dijkstra (obrigatório)
   └─ Um a sua escolha

3. MEDIR TEMPOS
   ├─ Execute cada algoritmo em todos os 30 grafos
   └─ Anote os tempos

4. COMPILAR RESULTADOS
   ├─ Crie tabelas com tempos
   ├─ Crie gráficos
   └─ Compare complexidade teórica vs prática

5. PREPARAR RELATÓRIO (PDF)
   ├─ Introdução
   ├─ Algoritmos (descrição + complexidade)
   ├─ Resultados (tabelas/gráficos)
   └─ Makefile e instruções

6. PREPARAR SLIDES (PDF)
   ├─ 7-12 minutos
   └─ Apresentação clara

7. ENTREGAR NO MOODLE
   ├─ PDF do relatório
   ├─ PDF dos slides
   └─ ZIP com código
```

---

## Visão Geral Técnica

```
┌──────────────────────────────────────────────────────────┐
│           GERADOR DE GRAFOS - VISÃO TÉCNICA             │
└──────────────────────────────────────────────────────────┘

ENTRADA: generator.py (fornecido)
  ↓
PROCESSAMENTO:
  ├─ Gera grafos com networkx
  ├─ 3 topologias diferentes
  ├─ Tamanhos 500 a 10000 nós
  ├─ 10 grafos por topologia
  └─ Pesos aleatórios 1-100
  ↓
SAÍDA: 30 arquivos .txt
  ├─ grafos_gerados/erdos/ (10 arquivos)
  ├─ grafos_gerados/barabasi/ (10 arquivos)
  ├─ grafos_gerados/watts/ (10 arquivos)
  └─ generation_log.json (estatísticas)
  ↓
USO: Seus algoritmos em C/C++
  ├─ Ler grafos
  ├─ Executar algoritmos
  └─ Medir tempos
```

---

## Agora Você Sabe

✅ Onde encontrar os scripts
✅ Como executar cada um
✅ Quanto tempo leva
✅ Qual arquivo faz o quê
✅ Onde encontrar ajuda
✅ Como usar os grafos em C/C++

---

## Comande Agora

```bash
python menu.py
```

Ou se estiver no Windows, clique duplo em `executar.bat`

---

**Boa sorte com seu trabalho! 🎓**

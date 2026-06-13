# 📑 ÍNDICE DE ARQUIVOS - Gerador de Grafos

Bem-vindo! Este é um guia para todos os arquivos criados para gerar grafos conforme o trabalho prático 3.

---

## 🎯 INÍCIO RÁPIDO

Se é a primeira vez aqui, comece por:

1. Leia: **[INICIO_RAPIDO.md](INICIO_RAPIDO.md)** (2 minutos)
2. Execute: `python menu.py` ou `python test_generator.py`

---

## 📂 GUIA DOS ARQUIVOS

### 🔴 EXECUTAR (Scripts Python)

Para executar qualquer script, use: `python nome_do_script.py`

| Script                          | O que faz                           | Tempo       | Para quem          |
| ------------------------------- | ----------------------------------- | ----------- | ------------------ |
| **menu.py**                     | Menu interativo com todas as opções | -           | Iniciantes         |
| **test_generator.py**           | Testa com 6 grafos pequenos         | 2-3 min     | Validar instalação |
| **generate_graphs.py**          | Gera 30 grafos conforme PDF         | 30-45 min   | Produção           |
| **generate_graphs_advanced.py** | Versão customizável com logs        | 30-45 min   | Avançados          |
| **analyze_graphs.py**           | Mostra estatísticas dos grafos      | Instantâneo | Validar resultados |

**Recomendação:** Comece com `python menu.py`

---

### 📚 BLER (Documentação)

Leia os arquivos na ordem:

| Arquivo                   | Tamanho         | Para quem  | Leia se                     |
| ------------------------- | --------------- | ---------- | --------------------------- |
| **INICIO_RAPIDO.md**      | ⭐ Curto        | Todos      | quer começar rápido         |
| **GUIA_COMPLETO.md**      | ⭐⭐⭐ Completo | Referência | quer entender tudo          |
| **README_GRAFOS.md**      | ⭐ Curto        | Técnico    | quer detalhes dos grafos    |
| **RESUMO_SCRIPTS.md**     | ⭐⭐ Médio      | Referência | quer saber o que foi criado |
| **CHECKLIST_COMPLETO.md** | ⭐ Curto        | Validação  | quer checar status          |

---

## 🔍 BUSCAR POR NECESSIDADE

### "Quero começar agora"

→ Leia: **INICIO_RAPIDO.md**
→ Execute: `python menu.py`

### "Quero entender tudo em detalhes"

→ Leia: **GUIA_COMPLETO.md**

### "Quero testar rapidinho"

→ Execute: `python test_generator.py`

### "Quero gerar todos os 30 grafos"

→ Execute: `python generate_graphs.py`

### "Quero ver o que foi criado"

→ Leia: **RESUMO_SCRIPTS.md** ou **CHECKLIST_COMPLETO.md**

### "Algo não está funcionando"

→ Leia: **GUIA_COMPLETO.md** (seção Troubleshooting)

### "Quero customizar os grafos"

→ Edite: **generate_graphs_advanced.py**
→ Leia: **GUIA_COMPLETO.md** (seção Configuração)

### "Estou no Windows"

→ Clique duplo em: **executar.bat**
→ Ou execute: `python menu.py`

---

## 📊 ESTRUTURA DE ARQUIVOS

```
gerador/
│
├─ 🐍 SCRIPTS EXECUTÁVEIS
│  ├─ menu.py                      ← COMECE AQUI!
│  ├─ test_generator.py            ← Teste rápido
│  ├─ generate_graphs.py           ← Gerar 30 grafos
│  ├─ generate_graphs_advanced.py  ← Versão customizável
│  └─ analyze_graphs.py            ← Analisar resultados
│
├─ 📚 DOCUMENTAÇÃO (LEIA NESTA ORDEM)
│  ├─ INICIO_RAPIDO.md             ← ⭐ COMECE AQUI!
│  ├─ GUIA_COMPLETO.md             ← Detalhes completos
│  ├─ README_GRAFOS.md             ← Formato dos grafos
│  ├─ RESUMO_SCRIPTS.md            ← O que foi criado
│  └─ CHECKLIST_COMPLETO.md        ← Status final
│
├─ 🔧 UTILITÁRIOS
│  └─ executar.bat                 ← Atalho Windows
│
├─ 📋 ORIGINAIS
│  ├─ generator.py                 ← Fornecido
│  └─ requirements.txt             ← Dependências
│
└─ 📁 SAÍDA (criada ao gerar)
   └─ grafos_gerados/
      ├─ erdos/
      ├─ barabasi/
      └─ watts/
```

---

## ⏱️ TEMPOS DE EXECUÇÃO

| Atividade                   | Tempo       |
| --------------------------- | ----------- |
| Ler INICIO_RAPIDO.md        | 2 min       |
| Instalar dependências       | 1 min       |
| Executar test_generator.py  | 2-3 min     |
| Executar generate_graphs.py | 30-45 min   |
| Executar analyze_graphs.py  | < 1 seg     |
| **TOTAL (primeiro uso)**    | **~50 min** |

---

## 🎓 PARA FAZER O TRABALHO

**Passo 1:** Gerar os grafos

```bash
python generate_graphs.py
```

Tempo: ~40 minutos (execute à noite)

**Passo 2:** Implementar os 3 algoritmos em C/C++

- Use os grafos em `grafos_gerados/`
- Meça tempos de execução

**Passo 3:** Analisar os resultados

- Crie tabelas/gráficos
- Compare com complexidade teórica

**Passo 4:** Preparar apresentação

- Slides em PDF
- Apresentação 7-12 minutos

**Passo 5:** Entregar no Moodle (12/05 às 8h)

- Arquivo PDF com relatório
- Slides PDF
- Código em ZIP

---

## ❓ PERGUNTAS FREQUENTES

**P: Por onde começo?**
R: Execute `python menu.py` ou leia `INICIO_RAPIDO.md`

**P: Quanto tempo leva?**
R: Teste rápido: 2-3 min | Gerar tudo: 30-45 min

**P: Funciona no Windows?**
R: Sim! Clique duplo em `executar.bat` ou execute `python menu.py`

**P: Preciso instalar algo?**
R: Sim, execute: `pip install networkx`

**P: Quantos grafos serão gerados?**
R: 30 grafos (3 topologias × 10 grafos cada)

**P: Qual é o tamanho?**
R: ~500 MB a 1 GB (depende da máquina)

**P: Posso customizar?**
R: Sim, edite `generate_graphs_advanced.py`

---

## ✅ CHECKLIST INICIAL

- [ ] Li INICIO_RAPIDO.md
- [ ] Instalei NetworkX (`pip install networkx`)
- [ ] Executei `python test_generator.py` com sucesso
- [ ] Entendo o que cada script faz
- [ ] Pronto para gerar os 30 grafos

---

## 🔗 NAVEGAÇÃO RÁPIDA

[INICIO_RAPIDO.md](INICIO_RAPIDO.md) → [GUIA_COMPLETO.md](GUIA_COMPLETO.md) → [RESUMO_SCRIPTS.md](RESUMO_SCRIPTS.md)

---

## 📞 NEED HELP?

1. **Para começar:** INICIO_RAPIDO.md
2. **Para entender:** GUIA_COMPLETO.md
3. **Para troubleshoot:** GUIA_COMPLETO.md (seção Problemas)
4. **Para validar:** CHECKLIST_COMPLETO.md

---

## 🚀 PRÓXIMOS PASSOS

```
1. python menu.py          # Abrir menu
2. Opção 2                 # Gerar 30 grafos
3. Aguardar ~40 minutos
4. python analyze_graphs.py # Ver resultado
5. Implementar C/C++       # Próximo passo do trabalho
```

---

**Tudo pronto! Comece com: `python menu.py`**

Data: 17 de maio de 2026

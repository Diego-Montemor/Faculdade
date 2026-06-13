# 📦 Resumo dos Scripts Criados

Criamos um conjunto completo de ferramentas para gerar grafos conforme especificado no trabalho prático 3. Veja abaixo:

---

## 🎯 Scripts Principais

### 1. **menu.py** (Menu Interativo)

- **Propósito:** Interface amigável para executar outros scripts
- **Como usar:** `python menu.py`
- **Tempo:** Instantâneo
- **Para quem:** Usuários que preferem interface visual

### 2. **test_generator.py** (Teste Rápido)

- **Propósito:** Validar que tudo está funcionando
- **Como usar:** `python test_generator.py`
- **Tempo:** 2-3 minutos
- **Saída:** 6 grafos pequenos (100-300 nós)
- **Para quem:** Primeira execução, validação rápida

### 3. **generate_graphs.py** (Geração Padrão)

- **Propósito:** Gerar os 30 grafos conforme PDF
- **Como usar:** `python generate_graphs.py`
- **Tempo:** 30-45 minutos
- **Saída:** 30 grafos (3 topologias × 10 grafos cada)
- **Para quem:** Geração completa conforme especificado

### 4. **generate_graphs_advanced.py** (Versão Customizável)

- **Propósito:** Gerar grafos com mais controle e logs detalhados
- **Como usar:** `python generate_graphs_advanced.py`
- **Tempo:** 30-45 minutos (dependendo config)
- **Saída:** 30 grafos + arquivo JSON com estatísticas
- **Para quem:** Quem quer customizar topologias/parâmetros

### 5. **analyze_graphs.py** (Análise)

- **Propósito:** Mostrar estatísticas dos grafos gerados
- **Como usar:** `python analyze_graphs.py`
- **Tempo:** Instantâneo
- **Saída:** Tabelas com nós, arestas, tamanhos
- **Para quem:** Verificar qualidade dos grafos gerados

---

## 📚 Arquivos de Documentação

### **INICIO_RAPIDO.md**

- Começo rápido em 3 passos
- Instruções essenciais
- Solução de problemas básicos

### **GUIA_COMPLETO.md**

- Documentação detalhada (em português)
- Explicação de cada script
- Tempos de execução
- Troubleshooting completo
- Configurações customizadas

### **README_GRAFOS.md**

- Informações sobre formato dos grafos
- Estrutura de saída
- Descrição das topologias

---

## 🔧 Archivos Utilitários

### **executar.bat**

- Atalho para Windows
- Clique duplo para abrir o menu

---

## 📊 Topologias Geradas

```python
Padrão:
├── Erdős-Rényi (p=0.1)      → aleatório
├── Barabási-Albert (m=3)     → sem escala / power law
└── Watts-Strogatz (k=4, p=0.3) → mundo pequeno
```

---

## 📈 Plano de Execução Recomendado

1. **Passo 1:** Testar

   ```bash
   python test_generator.py
   ```

   Tempo: ~3 min

2. **Passo 2:** Gerar todos os grafos

   ```bash
   python generate_graphs.py
   ```

   Tempo: ~40 min (execute à noite ou em background)

3. **Passo 3:** Analisar resultados

   ```bash
   python analyze_graphs.py
   ```

   Tempo: ~1 seg

4. **Passo 4:** Usar os grafos em C/C++
   - Grafos estarão em `grafos_gerados/`
   - Prontos para usar nos algoritmos

---

## 🎯 Atendimento aos Requisitos do PDF

✅ **"Ao menos 3 topologias diferentes"**

- Implementamos: Erdős-Rényi, Barabási-Albert, Watts-Strogatz

✅ **"Cada topologia deve conter grafos entre 500 e 10000 vértices"**

- Geramos: 500, 1000, 1500, 2000, 2500, 3000, 4000, 5000, 7500, 10000

✅ **"Ao menos 10 grafos de cada topologia"**

- Geramos: Exatamente 10 grafos por topologia

✅ **Total: 30 grafos** (conforme especificado)

---

## 💡 Dicas Úteis

🔹 **Para testar antes de gerar tudo:**

```bash
python test_generator.py
```

🔹 **Para executar no Windows:**

- Clique duplo em `executar.bat`
- Ou: `python menu.py`

🔹 **Para ver progresso durante geração:**

- Abra outro terminal
- Execute `python analyze_graphs.py`
- Veja grafos sendo criados em tempo real

🔹 **Para customizar topologias:**

- Edite `generate_graphs_advanced.py`
- Procure por `topologies = {`
- Modifique conforme necessário

---

## ⚙️ Requisitos Técnicos

✅ Python 3.7+
✅ NetworkX (`pip install networkx`)
✅ Pasta `gerador/` com todos os scripts
✅ `generator.py` no mesmo diretório
✅ `requirements.txt` com dependências

---

## 🐛 Debug

Se algo der errado:

1. Verifique se Python está instalado:

   ```bash
   python --version
   ```

2. Verifique se NetworkX está instalado:

   ```bash
   pip install networkx
   ```

3. Verifique se está na pasta correta:

   ```bash
   dir generator.py
   ```

4. Se ainda não funcionar, veja `GUIA_COMPLETO.md`

---

## 📞 Suporte

Para dúvidas sobre:

- **Como executar:** Veja `INICIO_RAPIDO.md`
- **Detalhes técnicos:** Veja `GUIA_COMPLETO.md`
- **Formato dos grafos:** Veja `README_GRAFOS.md`
- **Scripts específicos:** Veja comentários no código

---

## ✨ Próximos Passos

Após gerar os grafos:

1. Implemente os 3 algoritmos em C/C++
2. Use os grafos em `grafos_gerados/` para testar
3. Meça tempos de execução
4. Crie tabelas/gráficos para o relatório PDF
5. Prepare slides para apresentação

---

**Status:** ✅ Todos os scripts prontos para uso!

**Data de criação:** $(date)

**Localização:** `c:\Users\monte\OneDrive\Área de Trabalho\Nova pasta\gerador\`

# 🎯 Início Rápido - Gerador de Grafos

## Como Começar em 3 Passos

### 1️⃣ Instalar dependências

```bash
pip install -r requirements.txt
```

### 2️⃣ Executar o menu interativo

```bash
python menu.py
```

### 3️⃣ Escolher a opção desejada

- **Opção 1**: Teste rápido (~2 min)
- **Opção 2**: Gerar todos os 30 grafos (~30-45 min)
- **Opção 4**: Analisar grafos gerados
- **Opção 5**: Ver guia completo

---

## Scripts Disponíveis

| Script                        | Descrição                 | Tempo       |
| ----------------------------- | ------------------------- | ----------- |
| `menu.py`                     | Menu interativo           | -           |
| `test_generator.py`           | Teste rápido com 6 grafos | 2-3 min     |
| `generate_graphs.py`          | Gera 30 grafos padrão     | 30-45 min   |
| `generate_graphs_advanced.py` | Versão customizável       | 30-45 min   |
| `analyze_graphs.py`           | Analisa grafos gerados    | instantâneo |

---

## Estrutura de Arquivos

```
gerador/
├── generator.py                 # Gerador de grafos (fornecido)
├── requirements.txt            # Dependências
├── menu.py                    # Menu principal
├── test_generator.py          # Teste rápido
├── generate_graphs.py         # Geração padrão
├── generate_graphs_advanced.py # Geração customizável
├── analyze_graphs.py          # Análise
├── GUIA_COMPLETO.md          # Documentação detalhada
├── README_GRAFOS.md           # Guia de grafos
└── grafos_gerados/            # Saída dos grafos
    ├── erdos/
    ├── barabasi/
    └── watts/
```

---

## Informações Importantes

✅ **Topologias geradas:** Erdős-Rényi, Barabási-Albert, Watts-Strogatz  
✅ **Grafos por topologia:** 10  
✅ **Total de grafos:** 30  
✅ **Tamanho dos grafos:** 500 a 10000 nós  
✅ **Formato:** Lista de arestas com pesos (1-100)  
✅ **Garantia:** Todos os grafos são conexos

---

## Solução Rápida de Problemas

❌ **"No module named networkx"**

```bash
pip install networkx
```

❌ **Script não encontrado**

- Certifique-se de estar na pasta `gerador/`
- Use `python menu.py` na pasta correta

❌ **Generator.py não encontrado**

- Todos os scripts devem estar na pasta `gerador/`
- Não mova ou renomeie `generator.py`

---

## 📚 Para Mais Detalhes

Veja o arquivo `GUIA_COMPLETO.md` para documentação completa.

---

**Pronto para começar? Execute: `python menu.py`**

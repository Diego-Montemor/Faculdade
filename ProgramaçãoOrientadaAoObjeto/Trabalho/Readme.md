# Trabalho: Programação Orientada a Objetos — Sistema Acadêmico

Este diretório contém o trabalho da disciplina de Programação Orientada a Objetos (UNIFAL-MG), desenvolvido como atividade semestral. O artefato principal do trabalho é o sistema acadêmico que implementa funcionalidades de cadastro de turmas, lançamentos de avaliações, persistência em diferentes formatos, controle de acesso por papéis e uma interface JavaFX em evolução.

**Autores:** 
 - Diego Vianna Leite Montemor
 - Carlos Eduardo Pereira
 - Guilherme de Oliveira Aredes
 - Francisco Toro Tonissi
 - Pedro Ferreira Prado

**Disciplina:** Programação Orientada a Objetos

**Resumo:**

- Sistema acadêmico modular com camadas de domínio, serviços, persistência e apresentação.
- Suporta persistência em TXT, XML e JSON; testes automatizados; logging; Docker; JavaFX.

**Onde encontrar o projeto completo:**

- Código e documentação principal: [academic-system-semester-assignment-2026/README.md](ProgramaçãoOrientadaAoObjeto/Trabalho/academic-system-semester-assignment-2026/README.md#L1)

Estrutura relevante dentro desta pasta:

- [academic-system-semester-assignment-2026](ProgramaçãoOrientadaAoObjeto/Trabalho/academic-system-semester-assignment-2026/README.md#L1) — subprojeto com implementações Java e Python e arquivos de dados (`academic_data.*`).
- `academic_data.txt` / `academic_data.json` / `academic_data.xml` — exemplos de dados de persistência.

Como executar a versão Java (resumido):

```bash
cd ProgramaçãoOrientadaAoObjeto/Trabalho/academic-system-semester-assignment-2026/academic-system-java
mvn clean install
mvn exec:java
```

Como executar a versão Python (se desejar):

```bash
cd ProgramaçãoOrientadaAoObjeto/Trabalho/academic-system-semester-assignment-2026/academic-system-python
python -m venv .venv
source .venv/Scripts/activate    # Windows: .venv\Scripts\activate
pip install -r requirements.txt
python main.py
```

Observações:

- Consulte o README do subdiretório para documentação detalhada, requisitos e instruções de build/exec ([academic-system-semester-assignment-2026/README.md](ProgramaçãoOrientadaAoObjeto/Trabalho/academic-system-semester-assignment-2026/README.md#L1)).


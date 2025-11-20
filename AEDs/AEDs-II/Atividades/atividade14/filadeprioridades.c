#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Implementações das três variantes de fila de prioridades
#include "filadeprioridades.h"

// Estrutura baseada em vetor
// Mantida em ordem crescente por idade (dos mais novos para os mais velhos)
VetorOrdenado* criarVetorOrdenado(int capacidadeInicial) {
    VetorOrdenado* vo = (VetorOrdenado*)malloc(sizeof(VetorOrdenado));
    if (vo == NULL) {
        fprintf(stderr, "Erro ao alocar VetorOrdenado\n");
        exit(1);
    }
    vo->dados = (Jogador*)malloc(capacidadeInicial * sizeof(Jogador));
    if (vo->dados == NULL) {
        fprintf(stderr, "Erro ao alocar dados do vetor\n");
        free(vo);
        exit(1);
    }
    vo->tamanho = 0;
    vo->capacidade = capacidadeInicial;
    return vo;
}

void destruirVetorOrdenado(VetorOrdenado* v) {
    free(v->dados);
    free(v);
}

// Inserção (mantendo a ordenação)
void inserirVetorOrdenado(VetorOrdenado* v, Jogador j) {
    // Cresce o array se necessário
    if (v->tamanho == v->capacidade) {
        v->capacidade *= 2;
        v->dados = (Jogador*)realloc(v->dados, v->capacidade * sizeof(Jogador));
        if (v->dados == NULL) {
            fprintf(stderr, "Erro ao realocar dados do vetor\n");
            exit(1);
        }
    }

    // Varre de trás para frente abrindo espaço
    int idx = v->tamanho - 1;
    while (idx >= 0 && v->dados[idx].idade > j.idade) {
        v->dados[idx + 1] = v->dados[idx]; // move para a direita
        idx--;
    }
    
    // Inserir na posição correta
    v->dados[idx + 1] = j;
    v->tamanho++;
}

// Remoção
// Retira o elemento de maior prioridade (idade mais alta), que fica no final
Jogador removerVetorOrdenado(VetorOrdenado* v) {
    if (v->tamanho == 0) {
        fprintf(stderr, "Erro: Fila (vetor) vazia!\n");
        exit(1);
    }
    v->tamanho--;
    return v->dados[v->tamanho]; // Retorna o último elemento
}

// Lista não ordenada (inserção rápida, remoção exige busca do máximo)
ListaNaoOrdenada* criarListaNaoOrdenada() {
    ListaNaoOrdenada* listaNU = (ListaNaoOrdenada*)malloc(sizeof(ListaNaoOrdenada));
    if (listaNU == NULL) {
        fprintf(stderr, "Erro ao alocar ListaNaoOrdenada\n");
        exit(1);
    }
    listaNU->head = NULL;
    return listaNU;
}

void destruirListaNaoOrdenada(ListaNaoOrdenada* lista) {
    Node* cursor = lista->head;
    while (cursor != NULL) {
        Node* aux = cursor;
        cursor = cursor->next;
        free(aux);
    }
    free(lista);
}

// Inserção simples: colocamos no início da lista
void inserirListaNaoOrdenada(ListaNaoOrdenada* l, Jogador j) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro ao alocar no (lista nao ordenada)\n");
        exit(1);
    }
    novoNo->jogador = j;
    novoNo->next = l->head;
    l->head = novoNo;
}

// Remoção
// Busca linear pelo nó com maior idade e remove-o
Jogador removerListaNaoOrdenada(ListaNaoOrdenada* l) {
    if (l->head == NULL) {
        fprintf(stderr, "Erro: Fila (lista nao ordenada) vazia!\n");
        exit(1);
    }

    Node* noPrior = l->head;
    Node* anteriorPrior = NULL;
    Node* cursor = l->head;
    Node* anterior = NULL;

    // 1) varredura para localizar o mais velho
    while (cursor != NULL) {
        if (cursor->jogador.idade > noPrior->jogador.idade) {
            noPrior = cursor;
            anteriorPrior = anterior;
        }
        anterior = cursor;
        cursor = cursor->next;
    }

    // 2) remoção do nó escolhido
    if (anteriorPrior == NULL) { // máximo estava no início
        l->head = noPrior->next;
    } else {
        anteriorPrior->next = noPrior->next;
    }

    Jogador j = noPrior->jogador;
    free(noPrior);
    return j;
}

// Lista encadeada que se mantém ordenada por prioridade
ListaEncadeadaOrdenada* criarListaEncadeadaOrdenada() {
    ListaEncadeadaOrdenada* listaO = (ListaEncadeadaOrdenada*)malloc(sizeof(ListaEncadeadaOrdenada));
    if (listaO == NULL) {
        fprintf(stderr, "Erro ao alocar ListaEncadeadaOrdenada\n");
        exit(1);
    }
    listaO->head = NULL;
    return listaO;
}

void destruirListaEncadeadaOrdenada(ListaEncadeadaOrdenada* l) {
    Node* cursor = l->head;
    while (cursor != NULL) {
        Node* aux = cursor;
        cursor = cursor->next;
        free(aux);
    }
    free(l);
}

// Inserção
// Encontra a posição adequada para preservar a ordem (decrescente)
void inserirListaEncadeadaOrdenada(ListaEncadeadaOrdenada* l, Jogador j) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro ao alocar no (lista ordenada)\n");
        exit(1);
    }
    novoNo->jogador = j;

    // Caso A: lista vazia ou elemento entra no topo
    if (l->head == NULL || j.idade > l->head->jogador.idade) {
        novoNo->next = l->head;
        l->head = novoNo;
    } else {
        // Caso B: varre até encontrar o ponto de inserção
        Node* cursor = l->head;
        while (cursor->next != NULL && cursor->next->jogador.idade > j.idade) {
            cursor = cursor->next;
        }
        novoNo->next = cursor->next;
        cursor->next = novoNo;
    }
}

// Remoção
// Retira o elemento de maior prioridade (maior idade), que fica na cabeça
Jogador removerListaEncadeadaOrdenada(ListaEncadeadaOrdenada* l) {
    if (l->head == NULL) {
        fprintf(stderr, "Erro: Fila (lista ordenada) vazia!\n");
        exit(1);
    }
    
    Node* aux = l->head;
    Jogador j = aux->jogador;
    l->head = l->head->next;
    free(aux);
    return j;
}


int main() {
    // Geração de um pequeno conjunto de teste
    const int QTDE_JOGADORES = 10;
    Jogador* amostra = (Jogador*)malloc(QTDE_JOGADORES * sizeof(Jogador));
    if (amostra == NULL) {
        fprintf(stderr, "Erro ao alocar dados de teste\n");
        return 1;
    }

    // Popula em ordem decrescente (pior cenário para manter o vetor ordenado)
    for (int i = 0; i < QTDE_JOGADORES; i++) {
        sprintf(amostra[i].nome, "Jogador_%d", QTDE_JOGADORES - i);
        amostra[i].idade = QTDE_JOGADORES - i;
    }

    Jogador ultimo;

    // Teste: implementação com vetor ordenado
    printf("Teste — Vetor ordenado:\n");
    VetorOrdenado* pqVetor = criarVetorOrdenado(10);
    
    for (int i = 0; i < QTDE_JOGADORES; i++) {
        inserirVetorOrdenado(pqVetor, amostra[i]);
    }
    for (int i = 0; i < QTDE_JOGADORES; i++) {
        ultimo = removerVetorOrdenado(pqVetor);
    }
    printf("Concluido (vetor). Ultimo extraido: %s (idade %d)\n\n", ultimo.nome, ultimo.idade);
    destruirVetorOrdenado(pqVetor);


    // Teste: lista encadeada que mantém a ordenação
    printf("Teste — Lista encadeada ordenada:\n");
    ListaEncadeadaOrdenada* pqListaOrd = criarListaEncadeadaOrdenada();

    for (int i = 0; i < QTDE_JOGADORES; i++) {
        inserirListaEncadeadaOrdenada(pqListaOrd, amostra[i]);
    }
    for (int i = 0; i < QTDE_JOGADORES; i++) {
        ultimo = removerListaEncadeadaOrdenada(pqListaOrd);
    }
    printf("Concluido (lista ord.). Ultimo extraido: %s (idade %d)\n\n", ultimo.nome, ultimo.idade);
    destruirListaEncadeadaOrdenada(pqListaOrd);


    // Teste: lista sem ordenação (remoção encontra o máximo)
    printf("Teste — Lista nao ordenada:\n");
    ListaNaoOrdenada* pqListaNao = criarListaNaoOrdenada();

    for (int i = 0; i < QTDE_JOGADORES; i++) {
        inserirListaNaoOrdenada(pqListaNao, amostra[i]);
    }
    for (int i = 0; i < QTDE_JOGADORES; i++) {
        ultimo = removerListaNaoOrdenada(pqListaNao);
    }
    printf("Concluido (lista nao ord.). Ultimo extraido: %s (idade %d)\n\n", ultimo.nome, ultimo.idade);
    destruirListaNaoOrdenada(pqListaNao);


    // Liberar dados de teste
    free(amostra);

    return 0;
}
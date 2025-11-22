#include <stdio.h> 
#include <stdlib.h> 
#include "hash.h"

int M;

struct Hash* criar_hash(int tamanho) {
    M = tamanho;
    struct Hash* hash = (struct Hash*) malloc(sizeof(struct Hash));
    hash->items = (struct Item*) calloc(tamanho, sizeof(struct Item)); 
    return hash;
}

void hash_insere(struct Hash* hash, struct Item item) {
    if(hash->items[hashing(item.valor)].valor == 0) {
        hash->items[hashing(item.valor)] = item;
        hash->items[hashing(item.valor)].prox = NULL;
        printf("\nItem adicionado");
    } else {
        struct Item *newItem = (struct Item*) malloc(sizeof(struct Item)); 
        *newItem = item;
        newItem->prox = NULL;


        struct Item *tmp = &hash->items[hashing(item.valor)];
        while (tmp->prox != NULL) {
            tmp = tmp->prox;
        }
        
        tmp->prox = newItem;
        printf("\nItem encadeado adicionado");
    }
}

void hash_remove(struct Hash* hash, struct Item item) {
    struct Item *atual = &hash->items[hashing(item.valor)];
    struct Item *anterior = NULL;

    if (atual->valor == 0 && atual->prox == NULL) {
        printf("\nItem nao encontrado para remocao.");
        return;
    }

    if (atual->valor == item.valor) {
        if (atual->prox == NULL) {
            // Não tem lista encadeada
            atual->valor = 0; 
            printf("\nItem removido.");
        } else {
            // Tem lista encadeada. 
            struct Item *tmp = atual->prox;
            atual->valor = tmp->valor; 
            atual->prox = tmp->prox;   
            free(tmp);                 
            printf("\nItem removido.");
        }
        return;
    }
    anterior = atual;
    atual = atual->prox;
    while (atual != NULL) {
        if (atual->valor == item.valor) {
            anterior->prox = atual->prox; 
            free(atual);                 
            printf("\nItem encadeado removido!");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }

    printf("\nItem nao encontrado na lista encadeada.");
}


struct Item busca(struct Hash* hash, struct Item item) {
    struct Item *tmp = &hash->items[hashing(item.valor)];
    if (tmp->valor == 0 && tmp->prox == NULL) {
        struct Item naoEncontrado = {0, NULL}; // Retorna item vazio/inválido
        printf("\nItem nao encontrado.");
        return naoEncontrado;
    }

    // Percorre a lista encadeada
    while (tmp != NULL) {
        if (tmp->valor == item.valor) {
            printf("\nItem encontrado: %d", tmp->valor);
            return *tmp; // Retorna o valor encontrado
        }
        tmp = tmp->prox;
    }

    struct Item naoEncontrado = {0, NULL};
    printf("\nItem nao encontrado.");
    return naoEncontrado;
}

int hashing(int chave) {
    return (chave % M);
}

int main() { 
    int n;
    /* Cria hash com 20 posições */
    struct Hash* hash = criar_hash(10);
    struct Item item;
    do {
        printf("\n\n\n******************** Escolha a opção *******************");
        printf("\n1.Inserir item");
        printf("\n2.Remover item");
        printf("\n3.Obter item");
        printf("\n0.Sair");
        printf("\nEntre sua opção : ");
        scanf("%d",&n);
        switch(n) {
            case 1: printf("\nDigite o item ");
                    scanf("%d",&item.valor);
                    hash_insere(hash, item);
                    break;
            case 2: printf("\nDigite o item ");
                    scanf("%d",&item.valor);
                    hash_remove(hash, item);
                    break;
            case 3: printf("\nDigite o item ");
                    scanf("%d",&item.valor);
                    item = busca(hash, item);
                    break;
            case 0: exit(0);
                    break;
            default: printf("\n Opção errada!");
                    break;
            }
        } while(1);
    
}
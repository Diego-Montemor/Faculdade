#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no *maior, *menor; 
}*p,*tmp, *tmp1;

struct no* BuscaBinaria(struct no* raiz, int valor){
    if(raiz == NULL || raiz->valor == valor) return raiz;/*faz a função retornar o valor caso ela tenha sido encontrada ou NULL
                                                           devido ela não achar o valor após ter decido */

    if(raiz->valor >valor)return BuscaBinaria(raiz->menor, valor);//vai pra esquerda
    else return BuscaBinaria(raiz->maior, valor);//vai para a direita
}

struct no* inserir(struct no* raiz, struct no* valor){
     if(raiz == NULL) return valor;
     if(raiz->valor > valor->valor){
        raiz->menor = inserir(raiz->menor, valor);
     }else raiz->maior = inserir(raiz->maior, valor);
     return raiz;
}

struct no* buscaPai(struct no* raiz, struct no* valor){
    if(raiz == valor) return NULL;
    if((raiz->menor == valor && raiz->menor != NULL) || (raiz->maior == valor && raiz->maior != NULL)) return raiz;

    if(raiz->valor > valor) return buscaPai(raiz->menor, valor);
        else return buscaPai(raiz->menor, valor);
}

struct no* RemoveRaiz(struct no* raiz){
    struct no* p = raiz; 
    struct no* q = raiz->menor;

    while(q != NULL){
        p = q;
        q = q->maior;
    }

    p->menor = q->menor;
    q->menor = raiz->menor;
    q->maior = raiz->maior;

    return q;
}

struct no* RemoveNo(struct no* raiz, int valor){
    struct no* n = BuscaBinaria(raiz, valor);

    if(n){
        struct no* pai = buscaPai(raiz, valor);
        if(pai){
            
        }
    }


}

int main(){
    int op = -1, valor;
    struct no *item;
    while(op != 0){
        printf("\n1.Busca");
        printf("\n2.Inserir valor");
        printf("\n3.Busca pelo Pai");
        printf("\n0.Sair");
        printf("\nR: ");
        scanf("%d",&op);
        switch (op){
        case 1:
            printf("\nDigite o valor que deseja buscar: ");
            scanf("%d", &valor);
            tmp = p;
            item = BuscaBinaria(tmp,valor);
            if(item != NULL){
                printf("\no valor %d esta presente",item->valor);
            }else printf("o valor buscado nao esta presente");
             
            break;
        case 2:
            printf("\nDigite o valor a ser inserido na arvore: ");
            scanf("%d",&valor);
            tmp = p;
            if(BuscaBinaria(tmp,valor) == NULL){
                tmp1 = (struct no*) malloc (sizeof(struct no));
                tmp1->valor = valor;
                tmp1->maior = NULL;
                tmp1->menor = NULL;
                tmp = p;
                inserir(tmp,tmp1);
                printf("O valor foi inserido com susseso!!!");
            }else printf("O valor pedido ja esta presente na arvore");
            break;
        case 3:
            printf("\nDigite o valor que deseja saber o pai: ");
            scanf("%d",&valor);
            tmp = p;
            item = buscaPai(tmp, valor);
            if(item == NULL){
                printf("\nO valor nao possui um pai");
            }else printf("o valor do pai e: %d", item->valor);
        default:
            printf("\nfuncao nao encontrada! ");
        }   
    }

    return 0;
}

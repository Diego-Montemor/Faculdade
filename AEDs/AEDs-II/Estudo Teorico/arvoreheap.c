#include <stdlib.h>
#include <stdio.h>

int noPai(int vetor[],int x){
    return vetor[(x-1)/2];    
}

void troca(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void inserir(int *vetor[], int valor, int *tamanho){
    int pos = *tamanho;
    *(vetor + pos) = valor;

    while(*(vetor + noPai(vetor,*(vetor + pos))) < *(vetor + pos)){
        troca(noPai(vetor,*(vetor + pos)),*(vetor + pos));
        pos = (pos - 1)/2;
    }

    *tamanho++;
}

int main(){

    int arvoreHeap[15], tamanho = 0;
    // 7,8,22,17,15,12,11,8,115,1
    inserir(arvoreHeap,7,&tamanho);
    inserir(arvoreHeap,8,&tamanho);
    inserir(arvoreHeap,22,&tamanho);
    inserir(arvoreHeap,17,&tamanho);
    inserir(arvoreHeap,15,&tamanho);
    inserir(arvoreHeap,12,&tamanho);
    inserir(arvoreHeap,11,&tamanho);
    inserir(arvoreHeap,8,&tamanho);
    inserir(arvoreHeap,115,&tamanho);
    inserir(arvoreHeap,1,&tamanho);

    for(int i = 0; i <= tamanho; i++){
        printf(arvoreHeap[i],",");
    }

}
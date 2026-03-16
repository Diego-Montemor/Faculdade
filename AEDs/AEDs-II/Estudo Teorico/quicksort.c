#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void imprimir(int vetor[], int tamanho){
    printf("%d",vetor[0]);
    for(int i = 1; i < tamanho; i++){
        printf(",%d", vetor[i]);
    }
    printf("\n");
}

int partition(int vetor[], int inicio, int fim){
    int pivo = vetor[fim];
    int i = inicio - 1;

    for(int j = inicio; j < fim; j++){

        if(vetor[j] < pivo){
            i++;
            troca(&vetor[j], &vetor[i]);
        }

    }
    troca(&vetor[i+1], &vetor[fim]);
    return (i+1);
}

void quicksort(int vetor[], int inicio, int fim){
    if(inicio < fim){
        int ipartition = partition(vetor, inicio,fim);

        quicksort(vetor, inicio, ipartition -1);
        quicksort(vetor, ipartition + 1, fim);
    }
}

int intercalar(int vetor[], int inicio,int meio, int fim){
    int i,j,k;

    


}

int main(){

    int vetor[20] = {23,1,56,32,12,3,54,19,7,38,45,9,8,4,2,25,76,13,12,100};
    quicksort(vetor,0,19);
    imprimir(vetor, 20);
}
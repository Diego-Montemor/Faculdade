#include <stdlib.h>
#include <stdio.h>

void troca(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
- heap[(i-1)/2] – retornará o nó pai
- heap[(2*i)+1] – retornará o filho a esquerda
- heap[(2*i)+2] – retornará o filho a direita
*/
// Função de inserir em uma MIN-heap
void inserirMIN(int heap[], int valor, int *tamanho){
    heap[*tamanho] = valor;
    int i = *tamanho;
    while(heap[(i-1)/2] > heap[i]){// para a min-heap, verifica se o pai é MAIOR que o filho
        troca(&heap[(i-1)/2],&heap[i]);
        i = (i-1)/2;
    }
    (*tamanho)++;
}
int removeMIN(int heap[], int *tamanho){
    int valor = heap[0];
    troca(&heap[0],&heap[*tamanho -1]);
    heap[*tamanho -1] = __INT_MAX__;
    int i = 0;
    while (i < *tamanho -2){
        int filhoDir = heap[(2*i)+2];
        int filhoEsq = heap[(2*i)+1];
        int j = i;
        i = filhoDir < filhoEsq ? (2*i)+2 : (2*i)+1;
        if(i < *tamanho -2){
            troca(&heap[i],&heap[j]);
        }
    }

    (*tamanho)--;
    return valor;
}

void heapMIMsort(int heap[], int *tamanho, int MINheap[]){
    int tam = *tamanho;
    for(int i = 0; i < tam ;i++){
        heap[i] = removeMIN(MINheap, tamanho);
    }
    for(int i = 0; i <= tam-1; i++){
        printf("%d,",heap[i]);
    }
}


// Função de inserir em uma MAX-heap
void inserirMAX(int heap[], int valor, int *tamanho){
    heap[*tamanho] = valor;
    int i = *tamanho;
    while(heap[(i-1)/2] < heap[i]){// para a max-heap, verifica se o pai é MENOR que o filho
        troca(&heap[(i-1)/2],&heap[i]);
        i = (i-1)/2;
    }
    (*tamanho)++;
}

void removeMAX(int heap[], int *tamanho){
    troca(&heap[0],&heap[*tamanho -1]);
    heap[*tamanho -1] = -1;
    int i = 0;
    while (i < *tamanho -2){
        int filhoDir = heap[(2*i)+2];
        int filhoEsq = heap[(2*i)+1];
        int j = i;
        i = filhoDir > filhoEsq ? (2*i)+2 : (2*i)+1;
        if(i < *tamanho -2){//evita trocar com lixo de momoria
            troca(&heap[i],&heap[j]);
        }
    }

    (*tamanho)--;
}

int main(){

    printf("Numeros de entrada: 7,8,22,17,15,12,11,8,115,1 \nMIN-heap: ");
//  +--[MIN-heap]--+    
    int arvoreHeapMIN[15], tamanhoMIN = 0;
    // 7,8,22,17,15,12,11,8,115,1      30, 20, 40, 10, 25, 35 
    inserirMIN(arvoreHeapMIN,7,&tamanhoMIN);
    inserirMIN(arvoreHeapMIN,8,&tamanhoMIN);
    inserirMIN(arvoreHeapMIN,22,&tamanhoMIN);
    inserirMIN(arvoreHeapMIN,17,&tamanhoMIN);
    inserirMIN(arvoreHeapMIN,15,&tamanhoMIN);
    inserirMIN(arvoreHeapMIN,12,&tamanhoMIN);
    inserirMIN(arvoreHeapMIN,11,&tamanhoMIN);
    inserirMIN(arvoreHeapMIN,8,&tamanhoMIN);
    inserirMIN(arvoreHeapMIN,115,&tamanhoMIN);
    inserirMIN(arvoreHeapMIN,1,&tamanhoMIN);
    printf("\nsem ordenar: ");
    for(int i = 0; i <= tamanhoMIN-1; i++){
        printf("%d,",arvoreHeapMIN[i]);
    }
    printf("\nordenado: ");
    int MINheapOrdenado[tamanhoMIN];
    heapMIMsort(MINheapOrdenado,&tamanhoMIN,arvoreHeapMIN);
    for(int i = 0; i <= tamanhoMIN-1; i++){
        printf("%d,",MINheapOrdenado[i]);
    }
    

    printf("\nMAX-heap: ");

//  +--[MAX-heap]--+
    int arvoreHeapMAX[15], tamanhoMAX = 0;
    // 7,8,22,17,15,12,11,8,115,1   
    inserirMAX(arvoreHeapMAX,7,&tamanhoMAX);
    inserirMAX(arvoreHeapMAX,8,&tamanhoMAX);
    inserirMAX(arvoreHeapMAX,22,&tamanhoMAX);
    inserirMAX(arvoreHeapMAX,17,&tamanhoMAX);
    inserirMAX(arvoreHeapMAX,15,&tamanhoMAX);
    inserirMAX(arvoreHeapMAX,12,&tamanhoMAX);
    inserirMAX(arvoreHeapMAX,11,&tamanhoMAX);
    inserirMAX(arvoreHeapMAX,8,&tamanhoMAX);
    inserirMAX(arvoreHeapMAX,115,&tamanhoMAX);
    inserirMAX(arvoreHeapMAX,1,&tamanhoMAX);

    for(int i = 0; i <= tamanhoMAX - 1; i++){
        printf("%d,",arvoreHeapMAX[i]);
    }
    printf("\n1 remocao: ");
    removeMAX(arvoreHeapMAX,&tamanhoMAX);
    for(int i = 0; i <= tamanhoMAX - 1; i++){
        printf("%d,",arvoreHeapMAX[i]);
    }
    printf("\n2 remocao: ");
    removeMAX(arvoreHeapMAX,&tamanhoMAX);
    for(int i = 0; i <= tamanhoMAX - 1; i++){
        printf("%d,",arvoreHeapMAX[i]);
    }
    printf("\n3 remocao: ");
    removeMAX(arvoreHeapMAX,&tamanhoMAX);
    for(int i = 0; i <= tamanhoMAX - 1; i++){
        printf("%d,",arvoreHeapMAX[i]);
    }

}
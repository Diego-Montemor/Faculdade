#include <iostream>

using namespace std;

// Função de ordenação Bubble Sort (varre o vetor trocando vizinhos fora de ordem)
void bobble(int Vetor[], int tam){
    // Laço externo: controla quantas passagens serão feitas
    for(int i = tam - 1 ; i >= 1 ; i--){
        // Laço interno: percorre os elementos vizinhos e troca quando necessário
        for(int j = 0 ; j < tam - 1 ; j++){
            if(Vetor[j] > Vetor[j + 1]){
                // Troca de posição entre Vetor[j] e Vetor[j+1]
                int aux = Vetor[j];
                Vetor[j] = Vetor[j + 1];
                Vetor[j + 1] = aux;
            }
        }
    }
}

int main(){

    // Declara variáveis inteiras e um ponteiro para int
    int X, Y, Z;
    int *p;

    // Declara e inicializa um vetor de inteiros de 10 posições
    int v[] = {11,12,13,14,15,16,17,18,19,20};

    // Atribui valores às variáveis
    X = 10;
    Y = 12;
    Z = 17;

    // Ponteiro p recebe o endereço de X
    p = &X;
    // Imprime o endereço de X e seu valor (formatação printf)
    printf("\nO valor de &X: %p  \nO valor de X: %X\n", &X, X);
    // Imprime o conteúdo de p (endereço armazenado) e o valor apontado por p (*p)
    printf("\nO valor de P: %p  \nO valor de *P: %d\n", p, *p);

    // Incrementa o ponteiro p (avança para o próximo int em memória)
    p++;
    // Após incrementar, imprime o novo endereço e o valor lido naquele endereço
    printf("\nO valor de p: %p\nO valor de *p: %d\n", p, *p);

    // Percorre o vetor do início ao fim usando um ponteiro q
    printf("\n--[Valores  do vetor]--");
    for(int *q = v; q < v + 10 ; q++){
        // q aponta para v[i]; *q é o valor do elemento atual
        printf("\nO valor de &v[i]: %p\nO valor de v[i]: %d", q, *q);
    }

    // Percorre o vetor do fim para o início usando um ponteiro q
    printf("\nValores do vetor");
    for(int *q = v + 10 - 1; q >= v ; q--){
        printf("\nO valor de &v[i]: %p\nOvalor de v[i]: %d", q, *q);
    }

    return 0;
}
#include "algoritmos.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Preencher os campos abaixo
Participantes do grupo
Nome: Diego Vianna Leite Montemor  Matrícula: 2025.1.08.023
Nome: Pedro Medina Stracieri       Matrícula: 2023.1.08.033
Nome: Francisco Toro Tonissi       Matrícula: 2025.1.08.025
Nome: Pedro Ferrera Prado          Matrícula: 2025.1.08.028
*/


//  [Feito pelo Francisco]
//Ferramentas Auxiliares:

int juizdasLetras(char l1, char l2){
    if((l1 == 'A' && l2 == 'T') || (l1 == 'T' && l2 == 'A') || (l1 == 'C' && l2 == 'G') || (l1 == 'G' && 
    l2 == 'C')){
        return 2;
    }else{
        return -1;
    }
    /*Aqui é para quando for colocar a diagonal, é necessario verificar se 
      bate o A com T ou o C com G e se nao bater, decrmenta 1 da pontuacao. */ 
}
//Essa função serve para comparar os 3 possiveis caminhos que o algoritmo vai fazer
int escolherMaior(int a, int b, int c){ 
    int maior = a;
    if(b > maior){
        maior = b;
    }

    if(c > maior){
        maior = c;
    }

    return maior;

}

long int programacao_dinamica(char *s1, char *s2) {
    long int pontuacao = 0;
    
    int tamanho1 = strlen(s1);
    int tamanho2 = strlen(s2);

   int **matriz = malloc((tamanho1 + 1) * sizeof(int *)); // Cria as linhas
    for(int i = 0; i <= tamanho1; i++){
        matriz[i] = malloc((tamanho2 + 1) * sizeof(int));  // Cria as colunas de cada linha
    }

    matriz[0][0] = 0;
    //O for do i, serve pra prencher a coluna j[0] decrementando sempre -2
    for(int i = 1; i <= tamanho1; i++){
        matriz[i][0] = matriz[i - 1][0] - 2; 
    }
    // o for do j, serve pra prencher a linha i[0] decrementando sempre -2
    for(int j = 1; j <= tamanho2; j++){
        matriz[0][j] = matriz[0][j - 1] - 2; 
    }

    for(int i = 1; i <= tamanho1; i++){
        for(int j = 1; j <= tamanho2; j++){
            char letraAtual1 = s1[i - 1];
            char letraAtual2 = s2[j - 1];

        int valor_diagonal   =  matriz[i - 1][j - 1] + juizdasLetras(letraAtual1, letraAtual2); //calcula caso a melhor escolha seja pela diagonal
        int valor_cima = matriz[i - 1][j] - 2; //calcula caso a melhor condição (para ficar com a maior pontuacao) seja o valor a cima
        int valor_esquerda = matriz[i][j - 1] - 2; //calcula caso a melhor condição (para ficar com a maior pontuacao) seja o valor a esquerda
        matriz[i][j] = escolherMaior(valor_diagonal, valor_cima, valor_esquerda);
        }
    }

    long int resposta_final = matriz[tamanho1][tamanho2]; //o ultimo espaço da matriz sera a resposta final

    for(int i = 0; i <= tamanho1; i++){
        free(matriz[i]);
    }
    free(matriz); //libera memória

    return resposta_final;
    //return pontuacao;
}

// [Feito por mim(Diego)]
bool compara(char *p1, char *p2){ // compara os dois char para achar um par
    if((*p1 == 'A' && *p2 == 'T') || (*p1 == 'T' && *p2 == 'A') || (*p1 == 'C' && *p2 == 'G') || (*p1 == 'G' && *p2 == 'C')){
        return true;
    }else return false;
}

long int guloso(char *s1, char *s2){
    long int pontuacao = 0;
    int i = 0, j = 0;
    // verifica se vai precisar colocar uma lacuna ou não
    while (s1[i] != '\0' && s2[j] != '\0') { 
        if (compara(&s1[i], &s2[j])) {
            pontuacao += 2;
            i++;
            j++;
        } else if (s2[j + 1] != '\0' && compara(&s1[i], &s2[j + 1])) {
            pontuacao -= 2;   // lacuna em s1
            j++;
        } else if (s1[i + 1] != '\0' && compara(&s1[i + 1], &s2[j])) {
            pontuacao -= 2;   // lacuna em s2
            i++;
        } else {
            pontuacao -= 1;   // lacuna não ajuda
            i++;
            j++;
        }
    }
    // pontua com -2 as "lacunas" adicionadas na fita s1
     while (s1[i] != '\0') {
        pontuacao -= 2;
        i++;
    }
    // pontua com -2 as "lacunas" adicionadas na fita s2
    while (s2[j] != '\0') {
        pontuacao -= 2;
        j++;
    }
    return pontuacao;
}



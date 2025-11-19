#include <iostream>
using namespace std;

// Função de ordenação usando o método Bubble Sort com ponteiros
void bubblePonteiro(int Vetor[], int tam){   
    for(int i = 0; i < tam - 1; i++){ // Percorre o vetor várias vezes      
        for(int j = 0; j < tam - i - 1; j++){// Compara elementos adjacentes e troca se estiverem fora de ordem
            if(*(Vetor + j) > *(Vetor + j + 1)){                
                int temp = *(Vetor + j);  // Troca os valores usando ponteiros
                *(Vetor + j) = *(Vetor + j + 1);
                *(Vetor + j + 1) = temp;
            }
        }
    }
}

// Função de ordenação usando o método Selection Sort com ponteiros
void selectionPonteiro(int Vetor[], int tam){    
    for(int i = 0; i < tam - 1; i++){ // Percorre o vetor para encontrar o menor elemento e colocá-lo na posição correta
        int minIndex = i;        
        for(int j = i + 1; j < tam; j++){ // Busca o menor elemento no restante do vetor
            if(*(Vetor + j) < *(Vetor + minIndex)){
                minIndex = j;
            }
        }
        // Troca o menor elemento encontrado com o elemento da posição atual
        if(minIndex != i){
            int temp = *(Vetor + i);
            *(Vetor + i) = *(Vetor + minIndex);
            *(Vetor + minIndex) = temp;
        }
    }
}

// Função de ordenação usando o método Insertion Sort com ponteiros
void insertionPonteiro(int Vetor[], int tam){    
    for(int i = 1; i < tam; i++){ // Percorre o vetor a partir do segundo elemento
        int Valor = *(Vetor + i);
        int j = i - 1;
        // Move os elementos maiores que a chave para frente
        while(j >= 0 && *(Vetor + j) > Valor){
            *(Vetor + j + 1) = *(Vetor + j);
            j--;
        }
        *(Vetor + j + 1) = Valor;
    }
}
#include <iostream>
using namespace std;

void listagem(int Vetor[], int tam){
    for (int i = 0; i < tam; i++){
        cout << Vetor[i] << " ";
    }
    cout << endl;
}

void bobble(int Vetor[], int tam){
    for(int i = tam - 1 ; i >= 1 ; i--){
        for(int j = 0 ; j < tam - 1 ; j++){
            if(Vetor[j] > Vetor[j + 1]){
                int aux = Vetor[j];
                Vetor[j] = Vetor[j + 1];
                Vetor[j + 1] = aux;
            }
        }
    }
}

void selection(int Vetor[], int tam){
    for(int i = 0; i < tam - 1; i++){
        int min = i;
        for(int j = i + 1; j < tam; j++){
            if(Vetor[j] < Vetor[min]){
                min = j;
            }
        }
        if(min != i){
            int aux = Vetor[i];
            Vetor[i] = Vetor[min];
            Vetor[min] = aux;
        }
    }
}

void insertion(int Vetor[], int tam){
    for(int i = 1; i < tam; i++){
        int v = Vetor[i];
        int j = i - 1;
        while(j >= 0 and Vetor[j] > v){
            Vetor[j + 1] = Vetor[j];
            j--;
        }
        Vetor[j + 1] = v;
    }
}
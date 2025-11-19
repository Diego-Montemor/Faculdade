#include <iostream>
#include <cstdlib>
#include <time.h>
#include "ordenacao.h"

using namespace std;

int main(){
    //srand(time(NULL));
    int tam = 10;
    int vCrescente[tam] = {1,2,3,4,5,6,7,8,9,10};
    int vDecrescente[tam] = {10,9,8,7,6,5,4,3,2,1};
    int vAleat[tam];
    for (int i = 0; i < tam; i++){
        vAleat[i] = rand() % 20;
    }
    cout << "Qual metodo de ordenação deseja utilizar?/n(1).bubble  (2).selection  (3).insertion/nR: " << endl;
    int opcao;
    cin >> opcao;

    switch (opcao){
        case 1:{
            cout << "Bubble Sort" << endl;
            cout << "vetor Aleatorio" << endl;
            listagem(vAleat, tam);
            bobble(vAleat, tam);
            listagem(vAleat, tam);
            cout << "Vetor crescente" << endl;
            listagem(vCrescente,tam);
            bobble(vCrescente, tam);
            listagem(vCrescente, tam);
            cout << "Vetor decrescente" << endl;
            listagem(vDecrescente,tam);
            bobble(vDecrescente,tam);
            listagem(vDecrescente,tam);
            break;
        }
        case 2:{
            cout << "Selection Sort" << endl;
            cout << "vetor Aleatorio" << endl;
            listagem(vAleat, tam);
            selection(vAleat, tam);
            listagem(vAleat, tam);
            cout << "Vetor crescente" << endl;
            listagem(vCrescente,tam);
            selection(vCrescente, tam);
            listagem(vCrescente, tam);
            cout << "Vetor decrescente" << endl;
            listagem(vDecrescente,tam);
            selection(vDecrescente,tam);
            listagem(vDecrescente,tam);
            break;
        }
        case 3:{
            cout << "Insertion Sort" << endl;
            cout << "vetor Aleatorio" << endl;
            listagem(vAleat, tam);
            insertion(vAleat, tam);
            listagem(vAleat, tam);
            cout << "Vetor crescente" << endl;
            listagem(vCrescente,tam);
            insertion(vCrescente, tam);
            listagem(vCrescente, tam);
            cout << "Vetor decrescente" << endl;
            listagem(vDecrescente,tam);
            insertion(vDecrescente,tam);
            listagem(vDecrescente,tam);
            break;
        }
    }
    return 0;
}
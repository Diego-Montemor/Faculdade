#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    
    int Minimo, Maximo, NumeroGerado, Quantidade, i;
    
    srand(time(NULL));
    
    ofstream ValoresGerados("ValoresGerados.txt");
    if (not ValoresGerados.is_open()){
        return 1;
    }
    
    cout << "Digite a quantidade de valores que você deseja: ";
    cin >> Quantidade;
    cout << "Digite o valor maximo a ser gerado: ";
    cin >> Maximo;
    cout << "Digite o valor minimo a ser gerado: ";
    cin >> Minimo;
    
    while (Maximo < Minimo){
        cout <<"Digite um numero menor que o valor maximo (" << Maximo << "): ";
        cin >> Minimo;
    }
    
    i = 1;
    
    while (i <= Quantidade){
        
        NumeroGerado = rand() % Maximo;
        while(NumeroGerado < Minimo){
            NumeroGerado = rand() % Maximo;
        }
        ValoresGerados << NumeroGerado << endl;
        i = i + 1;
        
    }
    ValoresGerados.close();
    return 0;
}
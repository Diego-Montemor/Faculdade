#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int i, numero,resto,divisores, primo;
    
    cout << "Digite um numero: ";
    cin >> numero;
    i = 1;
    divisores = 0;
    while(numero >= i){
        resto = numero % i;
        if (resto == 0){
            divisores = divisores + 1;
        }
        i = i + 1;
    }
    if (divisores <= 2){
        cout << "Esse numero é primo" << endl;
    }else{
        cout << "Esse numero não é primo" << endl;
    }
    cout << "Total de divisores é " << divisores << endl; 
    
    return 0;
}


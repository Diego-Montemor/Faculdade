#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int i,numero,soma;
    
    cout << "Diegite um numero: ";
    cin >> numero;
    
    i = 0;
    soma = 0;
    
    while (numero >= 0){
        soma = soma + numero;
        i = i + 1;
        cout << "Digite mais um numero: ";
        cin >> numero;
    }
    
    cout << "Foram digitados " << i << " numeros" << endl;
    cout << "E a soma total desses numeros foi de " << soma << endl;
    
    return 0;
}

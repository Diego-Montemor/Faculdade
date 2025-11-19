#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {   
    int numero,i,conta;
    
    cout << "Digite um numero: ";
    cin >> numero;
    i = 1;
    conta = 0;
    while(i <= numero){
        int i1,i2;
        i1 = i;
        i2 = i + 1;
        if (i2 > numero){
            i2 = 0;
        }
        conta = conta + (i1 - i2);
        i = i + 2;
    }   
    cout << "o valor da conta deu: " << conta;
    
    return 0;
}


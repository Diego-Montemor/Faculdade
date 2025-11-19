#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    int numero,i;
    
    cout << "Digite um numero: ";
    cin >> numero;
    
    i = numero - 1;
    cout << numero << "! = " << numero;
    while (i > 0){
        cout << "x" << i;
        numero = (numero*i);
        i = i - 1;       
    }
    cout <<" = " << numero;
    
    return 0;
}

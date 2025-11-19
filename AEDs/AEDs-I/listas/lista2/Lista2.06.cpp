#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) { 
    float numero,pi, fracao;
    int i,ic;
    cout << "Digite um numero: ";
    cin >> numero;
    fracao = 0;
    ic = 0;
    i = 1;
    while (i < numero){
        float fi;
        fi = (float)1/(3+ic);  
        if ((i % 2) == 1){
            fracao = fracao - fi;
        }else{
            fracao = fracao + fi;
        }
        i = i + 1;
        ic = ic + 2;
    } 
    pi = 4*(1+fracao);
    cout << "O valor final de pi vai ser " << pi;
    // 3,339
    return 0;
}
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;
int main(int argc, char** argv) {
    
    int NMenor, NMaior, numero, Quant, NMenorGerado,NMaiorGerado;
    
    
    cout << "Digite a quantidade de numeros que você quer:";
    cin >> Quant;
    cout << "Digite um numero para ser o minimo:";
    cin >> NMenor;
    cout << "Digite um numero para ser o maximo:";
    cin >> NMaior;
    
    srand(time(NULL));
    NMenorGerado = NMaior + 10;
    NMaiorGerado = 0;
    
    while(Quant > 0){
            numero = rand() % NMaior;
        if (numero < NMenor){
            numero = rand() %NMaior;
        }
            if (numero > NMaiorGerado){
                NMaiorGerado = numero;
            }
            if (numero < NMenorGerado){
                NMenorGerado = numero;
            }
            
        Quant = Quant - 1;
    }
    
            
    cout << "O menor numero gerado foi o " << NMenorGerado << "\nO maior numero gerado foi o " << NMaiorGerado;
     
    
    
    return 0;
}


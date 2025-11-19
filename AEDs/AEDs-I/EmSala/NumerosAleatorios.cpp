#include <cstdlib>
#include <iostream>
#include <time.h>


using namespace std;

int main(int argc, char** argv) {
    
    int segredo, chute;
    
    cout << "numero aleatorio" << endl;
    srand(time(NULL));
    segredo = rand() % 101;
    
    cout << "Um numero foi gerado entre 1 e 100" << endl;
    cout << "Qual é este valor?";
    
    cin >> chute;
    
    while (chute != segredo){
        cout << "você errou, tente outro numero";
        cin >> chute;
    }
    
    
    cout << "o valor gerado foi " << segredo << " e você acertou";
    
    return 0;
}


#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main(int argc, char** argv) {
    srand(time(NULL));
    int PMax,PMin,idade,i,j,quantidade,PGeradas,PValidas;
    string TipoSanguineo;
    string TiposSanguineo[2][4] = {
        {"A-","B-","AB-","O-"},
        {"A+","B+","AB+","O+"}
    };
    
    cout << "Digite a quantidade de pessoas que você quer testar: ";
    cin >> quantidade;
    PValidas =0;
    PGeradas = 1;
    while (PGeradas <= quantidade){
           
    idade = 18 + rand() % (130 - 18 + 1);
    
    PMax = 7 + rand() % (25 - 7 +1);
    
    PMin = 2 + rand() % (20 - 2 +1);
    
    j = rand() % 4;
    
    i = rand() % 2;
    
    TipoSanguineo = TiposSanguineo[i][j];
    
    if ((TipoSanguineo == "A-" or TipoSanguineo == "B-") and (PMax > 14 and PMin > 10)){
        
        PValidas = PValidas +1;
        
    }
    PGeradas = PGeradas +1;
    }
    cout << "A porcentagem de pessoas validas é de " << (float) PValidas/quantidade*100 << "%";
    
    return 0;
}
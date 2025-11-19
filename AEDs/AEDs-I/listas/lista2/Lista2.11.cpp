#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    
    int PMax,PMin,idade,i,j,PValidas,escolha,PGeradas;
    string TipoSanguineo;
    string TiposSanguineo[2][4] = {
        {"A-","B-","AB-","O-"},
        {"A+","B+","AB+","O+"}
    };
    PValidas = 0;
    escolha = 1;
    PGeradas = 0;
    while (escolha != 2 ){
            cout << "Digite sua idade: ";
    cin >> idade;
    while(idade < 18 or idade > 130){
        cout << "Digite uma idade valida: ";
        cin >> idade;
    }
    
    cout << "Digite sua pressão Maxima: ";
    cin >> PMax;
    while(PMax < 7 or PMax > 25){
        cout << "Digite sua Pressão Maxima valida(de 7 a 25): ";
        cin >>PMax;
    }
    
    cout << "Digite sua Pressão Minima: ";
    cin >> PMin;
    while(PMin < 2 or PMin > 20){
        cout << "Digite sua Pressão Minima valida(de 2 a 20): ";
        cin >> PMin;
    }
    
    cout << "Selecione seu tipo sanguineo:\n" << "(1).A\t(2).B\t(3).AB\t(4).O" << endl;
    cin >> j;
    
    cout << "Selecione seu RH:\n" << "(1).-\t(2).+" << endl;
    cin >> i;
    
    TipoSanguineo = TiposSanguineo[i - 1][j - 1];
    
        if ((TipoSanguineo == "A-" or TipoSanguineo == "B-") and (PMax > 14 and PMin > 10)){
        
        PValidas = PValidas +1;
        
        }
    
        PGeradas = PGeradas +1;
        cout << "Deseja contar mais alguem?\n(1).Sim\t(2).Não" << endl;
        cin >> escolha;
    }
    cout << "A porcentagem de pessoas validas é de " << (float) PValidas/PGeradas*100 << "%";
   
    return 0;
}
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    string senha,TentativaDeSenha;
    int tentativas;
    
    cout << "Crie uma senha: ";
    cin >> senha;
    tentativas = 2;
    
    cout << "Insira uma senha: ";
    cin >> TentativaDeSenha;
    
    while (tentativas > 0 and TentativaDeSenha != senha){
        cout << "Senha incorreta, tente novamente: ";
        cin >> TentativaDeSenha;
        tentativas = tentativas -1;
    }
    
    if (TentativaDeSenha == senha){
        cout << "Senha correta!";
    }else{
        cout << "Acabou as tentativas";
    }
    
    
    return 0;
}


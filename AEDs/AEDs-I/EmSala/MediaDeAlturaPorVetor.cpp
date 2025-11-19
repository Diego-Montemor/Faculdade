#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    const int MAX = 100;
    int vetor[MAX];
    int i = 0, valor = 0, tam = 0, vdesejado;

    ifstream arquivo("MediaDeAlturaPorVetor.txt");
    if (!arquivo.is_open()) {
        cout << "\n\tErro: Arquivo não encontrado.\n";
        return 1;
    }

    while (arquivo >> valor && tam < MAX) {
        vetor[tam] = valor;
        tam++;
    }
    arquivo.close();

    cout << "Valores no vetor : ";
    for (i = 0; i < tam; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    cout << "\nDigite o valor desejado : ";
    cin >> vdesejado;

    int primeirapos = -1;
    for (i = 0; i < tam; i++) {
        if(vetor[i] == vdesejado){
            primeirapos = i;
            break;
        }
    }
    if(primeirapos != -1){
        cout << "\nA primeira posição do valor " << vdesejado << " está na " << (primeirapos + 1) <<"º posição " << endl;
    }else{
        cout << "\nErro, valor nao encontrado!" << endl;
        return 0;
    }
   
    cout << "\nAs posições do valor pedido é/são : ";
    for (i = 0; i < tam; i++) {
    if(vetor[i] == vdesejado){
        cout << (i+1) << " ";
    }
    }
     cout << endl;  
       
       
    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

typedef struct {
    int chave;
} Registro;

int menu(){
    int op;
    cout << "1. Busca1\n"
         << "2. Busca2\n"
         << "3. Busca Ordena\n"
         << "4. Busca Binaria\n"
         << "5. Incercerir\n"
         << "6. remover\n"
         << "R: ";
    cin >> op;
    return op;
}

int busca(Registro L[], int x , int n){
    int i = 0 , 
        pos = 0;
    while (i <= n){
        if(L[i].chave == x){
            pos = i + 1;
            break;
        }else i++;
    }
    return pos;
}

int busca2(Registro L[], int x, int n){
    int i = 0;
    L[n + 1].chave = x;
    while(L[i].chave != x){
        i++;
    }

    if (i != n + 1) {
        return i + 1;   
    } else {
        return 0;       
    }
}

int buscaOrd(Registro L[], int x, int n){
    int i = 0;
    L[n + 1].chave = x;
    while(L[i].chave < x){
        i++;
    }

    if (i == n + 1 or L[i].chave != x) {
        return 0;   
    } else {
        return i + 1;       
    }
}

int buscaBinaria(Registro L[], int x, int n){
    int inf = 0,
        sup = n,
        buscaBin = 0;
    while(inf <= sup){
        int meio = floor((inf + sup)/2);
        if(L[meio].chave == x){
            buscaBin = meio;
            break;
        }else if(L[meio].chave < x){
            inf = meio + 1;
        }else sup = meio - 1;
    }
    return buscaBin + 1;
}

int inserir(Registro L[], int QuantAtual, int Quant, int x){
    if(QuantAtual <= Quant){
        if(busca2(L, x, QuantAtual) == 0){
            L[QuantAtual + 1].chave = x;
            QuantAtual++;
            return QuantAtual;
        }else return 0;
    }else return -1;
}

int* remover(Registro L[], int QuantAtual, int Quant, int x, int n){
    if(QuantAtual >= 0){
        int item = busca2(L,x,n);
        if(item > 0){
            for(int i = item - 1; i < n; i++){
                L[i] = L[i + 1];
            }
            return 0;
        }
    }else return nullptr;
}

int main() {
    Registro L[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b1, b2, bo, bb, ins, rem, op = 10;

    while(op != 0){
        switch (op){
        case 1:{
            cout << "Digite um numero para buscar pela funcao busca1: ";
            cin >> b1;
            b1 = busca(L,b1,10);
            op = menu();
            break;
        }
        case 2:{
            cout << "Digite um numero para buscar pela funcao busca2: ";
            cin >> b2;
            b2 = busca2(L,b2,10);
            op = menu();
            break;
        }
        case 3:{    
            cout << "Digite um numero para buscar pela funcao busca ordenada: ";
            cin >> bo;
            bo = buscaOrd(L,bo,10);
            op = menu();
            break;
        }
        case 4:{
            cout << "Digite um numero para buscar pela funcao busca binaria: ";
            cin >> bb;
            bb = buscaBinaria(L, bb, 10);
            op = menu();
            break;
        }
        case 5:{
            cout << "Digite um numero para inserir no vetor: ";
            cin >> ins;
            ins = inserir(L,10,11,ins);
            break;
        }
        case 6:{
            cout << "Digite um numero para ser removido do vetor: ";
            cin >> rem;
            
            break;
        }
        default:
            op = menu();   
            break;
        }

    }
    return 0;
}
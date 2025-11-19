#include <iostream>

using namespace std;

int main(){

    int i1, i2, j1, j2;
    cout << "digite o tamanho i da matriz 1: ";
    cin >> i1;
    cout << "digite o tamanho j da matriz 1: ";
    cin >> j1;

    cout << "digite o tamanho i da matriz 2: ";
    cin >> i2;
    cout << "digite o tamanhho j da matriz 2: ";
    cin >> j2;

    int matriz1[i1][j1], matriz2[i2][j2];

    int Op;
    cout << "Qual calculo voce deseja fazer com a matriz?\n1.Soma   2.Multiplicacao\nR:";
    cin >> Op;
    while(Op < 1 and 2 < Op){
        cout << "Digite uma opcao valida";
        cin >> Op;
    }
    
    switch (Op){
    case 1:
        if(i1 == i2 and j1 == j2){
            for (int i = 0; i < i1; i++){
                for(int j = 0 ; j < j1 ; j++){
                    cout << "Digite o valor da matriz1[" << i << "][" << j << "]:";
                    cin >> matriz1[i][j];
                }
            }
            for (int i = 0; i < i2; i++){
                for(int j = 0 ; j < j2 ; j++){
                    cout << "Digite o valor da matriz1[" << i << "][" << j << "]:";
                    cin >> matriz2[i][j];
                }
            }
            int MatrizResultado[i1][j1];
            for(int i = 0; i < i1 ; i++){
                for(int j = 0; j < j1 ; j++){
                    MatrizResultado[i][j] = matriz1[i][j] + matriz2[i][j];
                    cout << MatrizResultado[i][j] << " ";
                }
                cout << endl;
            }
        }else cout << "dimensoes invalidas!!!";
        break;
    case 2:
        if(j1 == i2){
            for (int i = 0; i < i1; i++){
                for(int j = 0 ; j < j1 ; j++){
                    cout << "Digite o valor da matriz1[" << i << "][" << j << "]:";
                    cin >> matriz1[i][j];
                }
            }
            for (int i = 0; i < i2; i++){
                for(int j = 0 ; j < j2 ; j++){
                    cout << "Digite o valor da matriz1[" << i << "][" << j << "]:";
                    cin >> matriz2[i][j];
                }
            }            
            int MatrizResultado[i1][j2];
            for (int i = 0; i < i2; i++){
                for(int j = 0 ; j < j2 ; j++){
                    MatrizResultado[i][j] = 0 ;
                }
            }             
            for(int i = 0 ; i < i1 ; i++){
                for(int j = 0 ; j < j2 ; j++){
                    for(int x = 0 ; x < j1 ; x++){
                        MatrizResultado[i][j] = MatrizResultado[i][j]+(matriz1[i][x] * matriz2[x][j]);
                        cout << matriz1[i][x] << " x " << matriz2 [x][j] << " + ";
                    }
                    cout << " = " << MatrizResultado[i][j] << " ";
                }
                cout << endl;
            }
        }else cout << "dimensoes invalidas!!!";
        break;
    }
    return 0;
}


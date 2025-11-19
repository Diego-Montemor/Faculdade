#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

// Objetivo: Organizar uma tabela de números aleatórios em ordem crescente, decrescente ou manter a ordem original

int main(int argc, char** argv) {

    const int quant = 20;
    int i, tabela[quant], troca = 1, opcao;
    // gera uma tabela de números aleatórios entre 0 e 20
    srand(time(NULL));
    cout << "A tabela gerada foi: ";
    for (i = 0; i < quant; i++) {
        tabela[i] = rand() % (20 - 1 + 1); // define o intervalo de números aleatórios
        cout << tabela[i] << " ";
    }
    cout << endl;
    // solicita ao usuário como deseja organizar a tabela
    cout << "como você deseja organizar essa tabela?\n(1).crescente  (2).decrescente  (3).assim mesmo\nR: ";
    cin >> opcao;


    while (troca != 0) { // mantem o loop até que o número de trocas seja 0
        int p, p1, p2;
        troca = 0;
        for (p = 0; p < quant; p++) {
                p1 = tabela[p];
                p2 = tabela[p + 1];
            switch (opcao) {
                case 1:  // organiza a tabela em ordem crescente
                    if (p1 > p2) {
                        tabela[p] = p2;
                        tabela[p + 1] = p1;
                        troca++;
                    }
                break;
                case 2:  // organiza a tabela em ordem decrescente
                    if (p1 < p2) {
                        tabela[p] = p2;
                        tabela[p + 1] = p1;
                        troca++;
                    }
                break;
                default: //caso o usuario digite 3 ou qualquer outro número mantém a tabela na ordem original
                    troca = 0;
                break;
            }
        }
    }
    cout << endl;
    // retorna a tabela organizada
    cout << "A tabela ficou assim: ";
    for (i = 0; i < quant; i++) {
        cout << tabela[i] << " ";
    }
return 0;
}


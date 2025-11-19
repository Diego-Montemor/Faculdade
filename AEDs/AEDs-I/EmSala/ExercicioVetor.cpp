#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char** argv) {

    const int quant = 100;
    int tabela[quant], opcao = 0, NExcluido = 0, QuantAtual;
    QuantAtual = quant - NExcluido;
    srand(time(NULL));

    //gera uma tabela com a quantidade de elementos aleatorios desejada
    cout << "A tabela gerada foi: ";
    for (int i = 0; i < quant; i++) {
        tabela[i] = rand() % (30 - 1 + 1);
        cout << tabela[i] << " ";
    }

    while (opcao != 9) {// mantem o loop até que a opção 9 seja escolhida
        cout << "\nQual opção você deseja?\n(1).inverter os valores\n(2).adicionar um valor a todos\n(3).adicionar um valor a todos numeros não divisiveis por 3\n(4).excluir um valor\n(5).excluir todos elementos de um valor expecifico\n(6).adicionar um valor\n(7).adicionar um valor a um lugar expecifico\n(8).Excluir todos valores repetidos\n(9).Fim\nR: ";
        cin >> opcao;
        switch (opcao) { // separa cada opção em um case
            case 1: // Parte 1 flipa os valores de tras para frente
                for (int i = 0; i < QuantAtual / 2; i++) {
                    int n1, n2;
                    n1 = tabela[i];
                    n2 = tabela[quant - i - 1];

                    tabela[i] = n2;
                    tabela[quant - i - 1] = n1;
                }
                cout << "\nA tabela modificada pela parte 1 foi: ";
                for (int i = 0; i < QuantAtual; i++) {
                    cout << tabela[i] << " ";
                }
                break;
            case 2: // Parte 2 soma um valor a todos os elementos da tabela
                int valor;

                cout << "\nDigite um valor você deseja adicionar a todos os valores: ";
                cin >> valor;

                cout << "A tabela gerada pela Parte 2 foi: ";
                for (int i = 0; i < QuantAtual; i++) {
                    tabela[i] = tabela[i] + valor;
                    cout << tabela[i] << " ";
                }
                break;
            case 3: // Parte 3 soma um valor a todos os elementos que não são divisiveis por 3
                cout << "\nA tabela gerada pela parte 3 foi: ";
                for (int i = 0; i < QuantAtual; i++) {
                    if (not tabela[i] % 3 == 0) {
                        tabela[i] = tabela[i] + valor;
                    }
                    cout << tabela[i] << " ";
                }
                break;
            case 4: // Parte 4 exclui a primeira ocorrência de um valor
                int excluir, z;
                z = 0;
                cout << "Digite o valor que você deseja excluir: ";
                cin >> excluir;

                for (int i = 0; i < QuantAtual; i++) {
                    if (tabela[i] == excluir and z == 0) {
                        tabela[i] = 0;
                        z = 1;
                        NExcluido++;
                        for (int j = i + 1; j < QuantAtual; j = j + 2) {
                            int n1, n2;
                            n1 = tabela[j];
                            n2 = tabela[j + 1];

                            tabela[j - 1] = n1;
                            tabela[j] = n2;
                        }
                        QuantAtual--;
                    }
                }
                cout << "A tabela gerada pela Parte 4 foi: ";
                for (int i = 0; i < QuantAtual; i++) {
                    cout << tabela[i] << " ";
                }
                break;
            case 5: // Parte 5 exclui todas as ocorrências de um valor
                int ex;
                cout << "Digite o valor que você deseja excluir: ";
                cin >> ex;

                for (int i = 0; i < QuantAtual; i++) {
                    if (tabela[i] == ex) {
                        tabela[i] = 0;
                        NExcluido++;
                        for (int j = i + 1; j < QuantAtual; j = j + 2) {
                            int n1, n2;
                            n1 = tabela[j];
                            n2 = tabela[j + 1];

                            tabela[j - 1] = n1;
                            tabela[j] = n2;
                        }
                        QuantAtual--;
                    }
                }
                cout << "A tabela gerada pela Parte 5 foi: ";
                for (int i = 0; i < QuantAtual; i++) {
                    cout << tabela[i] << " ";
                }
                break;
            case 6: // Parte 6 adiciona um valor ao final da tabela
                if (QuantAtual < quant) {
                    int add;
                    cout << "Digite qual valor você deseja adicionar: ";
                    cin >> add;

                    tabela[QuantAtual] = add;
                    QuantAtual++;
                    cout << "\nA tabela modificada pela parte 6 foi: ";
                    for (int i = 0; i < QuantAtual; i++) {
                        cout << tabela[i] << " ";
                    }
                } else cout << "A tabela ja está cheia";
                break;
            case 7: // Parte 7 adiciona um valor em uma posição específica
                if (QuantAtual < quant) {
                    int add, pos;
                    cout << "Digite qual valor você deseja adicionar: ";
                    cin >> add;
                    cout << "Digite em qual posição você deseja adicionar: ";
                    cin >> pos;

                    for (int i = QuantAtual; i >= pos - 1; i--) {
                        tabela[i + 1] = tabela[i];

                    }
                    tabela[pos - 1] = add;
                    QuantAtual++;
                    cout << "\nA tabela modificada pela parte 7 foi: ";
                    for (int i = 0; i < QuantAtual; i++) {
                        cout << tabela[i] << " ";
                    }
                } else cout << "A tabela ja está cheia";
                break;
            case 8: // Parte 8 exclui todos os valores repetidos
                for (int i = 0; i < QuantAtual; i++) {
                    int n1 = tabela[i], igual = 0;
                    for (int j = 0; j < QuantAtual; j++) { // faz a verificação se tem repetição
                        int n2 = tabela[j];
                        if (n1 == n2) {
                            igual = 1;  // caso tenha repetição define "igual" = 1
                        }
                    }
                    if (igual = 1) {  // caso "igual" seja 1 ele verifica quais estão repetidos e apaga
                        for (int i = 0; i < QuantAtual; i++) {
                            if (tabela[i] == n1) {
                                tabela[i] = 0;
                                NExcluido++;
                                for (int j = i + 1; j < QuantAtual; j = j + 2) {  // anda com todos os valores para esquerda após um valor ter sido removido
                                    int p1, p2;
                                    p1 = tabela[j];
                                    p2 = tabela[j + 1];

                                    tabela[j - 1] = p1;
                                    tabela[j] = p2;
                                }
                                QuantAtual--;
                            }
                        }
                        igual = 0;
                    }
                }
                cout << "\nA tabela modificada pela parte 8 foi: ";
                for (int i = 0; i < QuantAtual; i++) {
                    cout << tabela[i] << " ";
                }
                break;
            case 9: // Parte 9 encerra o programa
                opcao = 9;
                break;
        }
    }
    return 0;
}
/*
Autor: Diego Vianna Leite Montemor
Data: 22/10/2023 20:08
Professor: Paulo Bresan
Disciplina: AEDs 1
Objetivo: Criar um programa que manipule um vetor de inteiros.
*/

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <locale.h>


using namespace std;

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Portuguese");
    const int quant = 100;
    int tabela[quant], opcao = 0, QuantAtual;
    QuantAtual = quant;
    srand(time(NULL));

    cout << "A tabela gerada foi: ";
    for (int i = 0; i < quant; i++) { // Cria o vetor contendo a quantidade de valores definido pela constante "quant" no intervalo de [0,100]
        tabela[i] = rand() % 101;
        cout << tabela[i] << " ";
    }

    while (opcao != 9) { // cria o menu de seleção de ações
        cout << "\nQual opção você deseja?\n";
        cout << "(1). contar a quantidade de ocorrências que um valor aparece\n";
        cout << "(2). contar a quantidade de ocorrências de valores de um intervalo\n";
        cout << "(3). buscar pela primeira ocorrência de um valor e informar a posição\n";
        cout << "(4). excluir um valor\n";
        cout << "(5). excluir todos elementos de um valor expecifico\n";
        cout << "(6). adicionar um valor\n";
        cout << "(7). adicionar um valor a um lugar expecifico\n";
        cout << "(8). Excluir todos valores repetidos\n";
        cout << "(9). Fim\n";
        cout << "R: ";
        cin >> opcao;
        switch (opcao) { // para cada uma das opções do menu ele executa a opção desejada
            case 1: {// Opção 1 (contar a quantidade de ocorrências que um valor aparece)
                int q = 0, x;
                cout << "Digite o valor que você deseja contar: ";
                cin >> x;
                for (int i = 0; i < QuantAtual; i++) {
                    if(tabela[i] == x){
                        q++; // conta quantas vezes o numero pedido aparece
                    }
                }
                cout << "O número de ocorrências do valor " << x << " é: " << q << endl;;
                break;
            }
            case 2: { // Opção 2 (contar a quantidade de ocorrências de valores de um intervalo)
                int p1,p2,n,m = 0;
                cout << "Digite o primeiro valor do intervalo: ";
                cin >> p1;
                cout << "Digite o segundo valor do intervalo: ";
                cin >> p2;
                cout << "Digite o valor que você deseja contar: ";
                cin >> n;
                for(int i = p1 - 1; i <= p2 - 1; i++){ // define a posição que deve fazer a busca do valor
                    if(tabela[i] == n){
                        m++; // conta quantas vezes o numero pedido aparece
                    }
                }
                cout << "O número de ocorrências do valor " << n << " no intervalo [" << p1 << "," << p2 << "] é: " << m << endl;
                break;
            }
            case 3: { // Opção 3 (buscar pela primeira ocorrência de um valor e informar a posição)
                int n;
                cout << "Digite o valor que você deseja buscar: ";
                cin >> n;
                for(int i = 0 ; i < QuantAtual ; i++){
                    if(tabela[i] == n){
                        cout << "o valor " << n << " foi encontrado na posição " << i + 1 << endl;
                        break; // encerra o for apos passar pela primeira ocorrência do valor pedido
                    }
                }
                break;
            }
            case 4: {// Opção 4 (excluir um valor)
                int excluir, z;
                z = 0;
                cout << "Digite o valor que você deseja excluir: ";
                cin >> excluir;

                for (int i = 0; i < QuantAtual; i++) {
                    if (tabela[i] == excluir and z == 0) { // verifica se o valor é igual ao valor pedido e se ainda n foi feito nenhuma exlução
                        z = 1; // define q ja ouve uma exclução para impedir q exclua mais de um item
                        for (int j = i + 1; j < QuantAtual; j = j + 2) { // anda com todos os valores do vetor para excluir o numero
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
            }
            case 5: {// Opção 5 (excluir todos elementos de um valor expecifico)
                int ex;
                cout << "Digite o valor que você deseja excluir: ";
                cin >> ex;

                for (int i = 0; i < QuantAtual; i++) {
                    if (tabela[i] == ex) { // verifica se o valor é igual ao valor pedido
                        for (int j = i + 1; j < QuantAtual; j = j + 2) { // anda com todos os valores para esquerda para cobrir o valor excluido
                            int n1, n2;
                            n1 = tabela[j];
                            n2 = tabela[j + 1];

                            tabela[j - 1] = n1;
                            tabela[j] = n2;
                        }
                        QuantAtual--; // diminui o valor da quantidade de valores no vetor para imprimir com a quantidade certa de valores
                    }
                }
                cout << "A tabela gerada pela Parte 5 foi: ";
                for (int i = 0; i < QuantAtual; i++) {
                    cout << tabela[i] << " ";
                }
                break;
            }
            case 6: {// Opção 6 (adicionar um valor)
                if (QuantAtual < quant) {
                    int add;
                    cout << "Digite qual valor você deseja adicionar: ";
                    cin >> add;

                    tabela[QuantAtual] = add; // adiciona o valor ao final do vetor
                    QuantAtual++;
                    cout << "\nA tabela modificada pela parte 6 foi: ";
                    for (int i = 0; i < QuantAtual; i++) {
                        cout << tabela[i] << " ";
                    }
                } else cout << "A tabela ja está cheia";
                break;
            }
            case 7: {// Opção 7 (adicionar um valor a um lugar expecifico)
                if (QuantAtual < quant) {
                    int add, pos;
                    cout << "Digite qual valor você deseja adicionar: ";
                    cin >> add;
                    cout << "Digite em qual posição você deseja adicionar: ";
                    cin >> pos;

                    for (int i = QuantAtual; i >= pos - 1; i--) { // anda com todos os valores para a direita da posição pedida
                        tabela[i + 1] = tabela[i];

                    }
                    tabela[pos - 1] = add; // adiciona o valor a posição pedida
                    QuantAtual++;
                    cout << "\nA tabela modificada pela parte 7 foi: ";
                    for (int i = 0; i < QuantAtual; i++) {
                        cout << tabela[i] << " ";
                    }
                } else cout << "A tabela ja está cheia";
                break;
            }
           case 8: {// Opção 8 (Excluir todos valores repetidos)
                for (int i = 0; i < QuantAtual; i++) {
                    for (int j = i + 1; j < QuantAtual; ) { // impede a exclução da priemira ocorrencia do valor e só aumenta o valor de j caso ele n seja excluido 
                        if (tabela[i] == tabela[j]) {// Remove o valor igual 
                            cout << "valor ecluido: " << tabela[j]  << endl;    // lista todos valores removidos                     
                            for (int k = j; k < QuantAtual - 1; k++) {
                                tabela[k] = tabela[k + 1];
                            }
                            QuantAtual--;
                        } else {
                            j++;
                        }
                    }
                }
                cout << "\nA tabela modificada pela parte 8 foi: ";
                for (int i = 0; i < QuantAtual; i++) {
                    cout << tabela[i] << " ";
                }
                break;
            }
            case 9: {// Opção 9 (Fim)
                opcao = 9; // define a opção como 9 para parar o while
                break;
            }
        }
    }
    return 0;
}
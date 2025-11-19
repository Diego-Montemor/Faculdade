#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Estrutura que representa um contato da agenda
typedef struct { 
    string nome;
    string email;
    string cidade;
    int celular;
} amigo; 

int main() {
    // opcao: escolha do menu; quant: quantidade de contatos em memória (começa em 1)
    int opcao , quant = 1;

    // Menu principal
    cout << "Oque voce deseja?\n(1).Escrever na agenda  (2).Ler a agenda  (3).Editar a agenda  (4).Sair\nR: ";
    cin >> opcao;

    // Vetor estático de contatos (capacidade para até 100)
    amigo amigos[100];

    // Direciona o fluxo de execução conforme a opção
    switch(opcao){
    case 1:{
        // Caso 1: Captura de novos contatos em memória (não grava no arquivo aqui)
        int continua = 1;
        while(continua == 1){ // Repete enquanto o usuário quiser adicionar contatos
            cout << quant ; // Mostra a posição atual de gravação

            // Coleta dos dados do contato e grava no vetor em memória
            cout << "Digite o nome do amigo: " ;
            cin >> amigos[quant - 1].nome;
            cout << "Digite o email do amigo: ";
            cin >> amigos[quant - 1].email;
            cout << "Digite a cidade do amigo: ";
            cin >> amigos[quant - 1].cidade;
            cout << "Digite o celular do amigo: ";
            cin >> amigos[quant - 1].celular;

            // Pergunta se deseja cadastrar outro contato
            cout << "Deseja continuar?\n(1).Sim  (2).Nao\n";    
            cin >> continua;
            if(continua == 1){
                // Avança o contador de contatos válidos em memória
                quant = quant + 1;
            }
        }
        // Sai do case 1
        break;
    }

    case 2:{
        // Caso 2: Leitura da agenda (dos dados em memória ou do arquivo)
        int opcao2;
        cout << "Qual lista voce deseja ler?\n(1).Escrita agora  (2).Lista salva anteriomente";
        cin >> opcao2;
        switch (opcao2){
        case 1: {
            // Opção 1: Mostrar o que já foi digitado nesta execução (em memória)
            if(quant > 1){
                for(int i = 0 ; i < quant ; i++){
                    cout << "O " << i << " da lista e o " << amigos[i].nome << " com o email "
                         << amigos[i].email << " na cidade " << amigos[i].cidade << "com o numero "
                         << amigos[i].celular << endl;
                }
            } else {
                cout << "Ainda nao tem nada escrito na lista atual";
            }
            break;
        }
        case 2: {
            // Opção 2: Carregar do arquivo Registro.txt até encontrar a palavra sentinela "Fim"
            ifstream LeituraAgenda("Registro.txt");
            if (!LeituraAgenda) {
                cout << "Erro ao abrir o arquivo para leitura." << endl;
                return 1;
            }
            int i=0; // Contador apenas para exibir a posição do contato na saída

            // Lê o primeiro nome para entrar no laço
            LeituraAgenda >> amigos[quant].nome;

            // Enquanto não encontrar a palavra "Fim", continua lendo os campos do contato
            while (amigos[quant].nome != "Fim"){ // Evita loop infinito com sentinela
                i++;
                
                // Lê os demais campos do contato atual
                LeituraAgenda >> amigos[quant].email;
                LeituraAgenda >> amigos[quant].cidade;
                LeituraAgenda >> amigos[quant].celular;

                // Exibe o contato lido
                cout << "O " << i << "° contato da lista é o " << amigos[quant].nome
                     << " com o email: " << amigos[quant].email
                     << " mora na cidade: " << amigos[quant].cidade
                     << " e seu telefone é: " << amigos[quant].celular;

                // Avança a posição de gravação em memória
                quant++;

                // Tenta ler o próximo nome (ou a palavra "Fim")
                LeituraAgenda >> amigos[quant].nome;
            }
   
            // Finaliza a leitura
            LeituraAgenda.close();
            cout << endl;
            break;
        }    
        // Sai do switch interno de leitura
        break;   
    }

    case 3:{ // Caso 3: operações de edição com o vetor "amigos"
        int opcao3;
        cout << "Oque deseja fazer?\n(1).Editar algum contato  (2).Deletar algum contato\n";  
        cin >> opcao3;
        while(opcao3 != 3){ // Repete até o usuário escolher sair (3)
            switch(opcao3){
            case 1:{
                // Edição de um contato existente
                int x;
                cout << "Qual contato deseja editar?\n";
                for(int i = 0 ; i < quant ; i++){
                    cout << i << " - " << amigos[i].nome << endl;
                }
                cin >> x; // Índice do contato a editar

                // Coleta e substitui os dados do contato escolhido
                cout << "Digite o novo nome do amigo: ";
                cin >> amigos[x].nome;
                cout << "Digite o novo email do amigo: ";
                cin >> amigos[x].email;
                cout << "Digite a nova cidade do amigo: ";
                cin >> amigos[x].cidade;
                cout << "Digite o novo celular do amigo: ";
                cin >> amigos[x].celular;
                break;
            }
            case 2:{
                // Exclusão de um contato: desloca os elementos à esquerda
                int x;
                cout << "Qual contato deseja deletar?\n";
                for(int i = 0 ; i < quant ; i++){
                    cout << i << " - " << amigos[i].nome << endl;
                }
                cin >> x; // Índice do contato a excluir

                // Move todos os contatos à frente uma posição para trás, sobrescrevendo o escolhido
                for(int i = x ; i < quant ; i++){
                    amigos[i] = amigos[i+1];
                }
                // Diminui a quantidade total após a remoção
                quant--;
                break;
            }
            default:
                // Qualquer outra opção sai do submenu de edição
                opcao3 = 3;
                break;
            } 
        }
        
        // Sai do case 3
        break;
    }

    default:
        // Default: persiste em arquivo tudo o que está no vetor 'amigos' (até 'quant')
        ofstream EscritaAgenda("Registro.txt");
        if (!EscritaAgenda) {
            cout << "Erro ao abrir o arquivo para escrita." << endl;
            return 1;
        }

        // Grava cada contato em uma linha: nome email cidade celular
        for(int i = 0 ; i < quant; i++){
            EscritaAgenda << amigos[i].nome << " "
                          << amigos[i].email << " "
                          << amigos[i].cidade << " "
                          << amigos[i].celular << endl;
        }
        EscritaAgenda.close(); // Fecha o arquivo de saída
        break;
    }

    // Encerra o programa
    return 0;
}
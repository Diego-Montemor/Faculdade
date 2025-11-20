#include <iostream>

using namespace std;

void dobra(int* p){
    *p = *p * 2;
}

int main(){

//  +--[Ponteiro de variavel]--+  

    int numero = 10;
    int* ponteiro;
    int* ponteiroVazio = nullptr;
    int** PonteiroDePonteiro = &ponteiro;

    ponteiro = &numero;
/*
    Para pegar um VALOR de onde o ponteiro aponta tem q usar *VARIAVEL
    Para pegar o INDEREÇO de alguma pariavel tem q usar &VARIAVEL

    Para usar um ponteiro tem q cria-lo usando int* VARIAVEL e dps declarar 
    uma POSIÇÂO DE MEMORIA para ele apontar assim: VARIAVEL = &VARIAVEL_APONTADA
    dessa forma se usar: *ponteiro  -> valor do objeto apontado
                         &variavel  -> endereço dessa variável (ex.: &numero). 
                         &ponteiro  -> endereço do próprio ponteiro.
                          ponteiro  -> contém o endereço do objeto apontado.
       
        Obs.: Declare e, de preferência, inicialize: int* p = nullptr; depois p = &alvo;
*/  
    cout << "\n\n--------------------------------------------"
         << "\nvalor na variavel numero: " << numero
         << "\nlocal da memoria da variavel numero: " << &numero
         << "\nconteudo da variavel ponteiro: " << ponteiro
         << "\nvalor na variavel ponteiro: " << *ponteiro
         << "\nlocal da memoria da variavel ponteiro: " << &ponteiro
         << "\n--------------------------------------------"
         << "\nConteudo de um ponteiro vazio: " << ponteiroVazio
         << "\n--------------------------------------------"
         << "\nvalor do ponteiro de ponteiro (com 1 * ): " << *PonteiroDePonteiro
         << "\nvalor do ponteiro de ponteiro (com 2 ** ): " << **PonteiroDePonteiro
         << "\nendereco do ponteiro de ponteiro: " << &PonteiroDePonteiro
         << "\nConteudo na variavel Ponteiro de Ponteiro: " << PonteiroDePonteiro
         << "\n--------------------------------------------"
         << endl;
    dobra(ponteiro);
    cout << "\nfuncao de dobrar o numero: " << numero << endl;



//  +--[Ponteiro em vetor]--+

    int vetor[5] = {0,1,2,3,4};
    int* pVetor;

    pVetor = &vetor[0];
/*
    Para usar ponteiro em um vetor é necessario usar criar um vetor comum e salvar
    o tamanho do vetor. E para usar ponteiro nesse vetor, tem q pegar a posição inicial
    do vetor e ir andando de casa em casa até a ultima casa, e caso tente pegar uma casa que está
    alem do limite do vetor, vai vir um lixo de memoria por conta de estar acessando outra posição de memoria.
     Para usar ponteiro com vetor:
            int* p = vetor; // ou p = &vetor[0]
            *(p + i) == vetor[i]
            Mantenha o tamanho 'n' para não ultrapassar os limites.
            Acessar além do fim é comportamento indefinido.
            Ex.: *(p + 2) acessa o 3º elemento (índice 2).
    
        Obs.: int* PONTEIRO[n] -> vetor de n ponteiros para int.
*/
    cout << "\n-------------------------------------------- "
        << "\nprimeira casa do vetor: " << *(pVetor + 0)    
         << "\nsegunda casa do vetor: " << *(pVetor + 1)
         << "\nterceira casa do vetor: " << *(pVetor + 2)
         << "\nquarta casa do vetor: " << *(pVetor + 3)
         << "\nquinta casa do vetor: " << *(pVetor + 4)
         << "\nsexta casa do vetor: " << *(pVetor + 5)
         << " <-- provavelmente saia um lixo de memoria por n ter esse espaco reservado para o vetor(o vetor so tem 5 casas reservadas)"
         << "\n--------------------------------------------"
         << endl;
    
    return 0;
}

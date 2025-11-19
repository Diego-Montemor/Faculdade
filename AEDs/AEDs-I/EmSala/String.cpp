#include <cstdlib>
#include <iostream>
#include <string>


using namespace std;

int main(int argc, char** argv) {
    // Objetivo: montar o nome completo manualmente em um buffer (NomeCompleto)
    // copiando, caractere a caractere, nome e sobrenomes, inserindo espaços entre eles.
    
    // Declara e inicializa os pedaços do nome como arrays de char terminados em '\0'
    char nome[6] = {'D','i','e','g','o','\0'},
         sobrenome1[7] = {'V','i','a','n','n','a','\0'},
         sobrenome2[6] = {'L','e','i','t','e','\0'},
         sobrenome3[9] = {'M','o','n','t','e','m','o','r','\0'};
    
    // Buffer que receberá o nome completo. Tamanho 30 é suficiente para este exemplo
    char NomeCompleto[30];

    // Índices de varredura para cada parte (evitam misturar os contadores)
    int i,i2,i3,i4;
    i = 0;
    i2 = 0;
    i3 = 0;
    i4 = 0;
    
    // Copia o "nome" para o início de NomeCompleto até encontrar o terminador '\0'
    while(nome[i] != '\0'){
        NomeCompleto[i] = nome[i];
        i++;
    }
    // Insere um espaço após o nome
    NomeCompleto[i] = ' ';
    i++;            

    // Copia o primeiro sobrenome logo após o espaço
    while(sobrenome1[i2] != '\0'){
        NomeCompleto[i] = sobrenome1[i2];
        i2++;
        i++;
    }
    // Insere espaço entre sobrenomes
    NomeCompleto[i] = ' ';
    i++;

    // Copia o segundo sobrenome
    while(sobrenome2[i3] != '\0'){
        NomeCompleto[i] = sobrenome2[i3];
        i3++;
        i++;
    }
    // Insere espaço antes do último sobrenome
    NomeCompleto[i] = ' ';
    i++;

    // Copia o terceiro sobrenome
    while(sobrenome3[i4] != '\0'){
        NomeCompleto[i] = sobrenome3[i4];
        i4++;
        i++;
    }

    // Atribuição do terminador.
    NomeCompleto[i] = '\0';
    
    // Imprime o conteúdo do buffer (assumindo que esteja corretamente terminado em '\0')
    printf(NomeCompleto);
    return 0;
}


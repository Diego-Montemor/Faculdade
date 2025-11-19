#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

    int i, iMaior, iMenor , QuantAlturas, QuantidadePedida;
    float altura, media, soma, MaiorAltura, MenorAltura;

    i = 1;
    soma = 0;
    
    ifstream arquivo("MediaDasAlturas2.txt");
    if (not arquivo.is_open()){
        cout << "\n\tERRO: O arquivo não foi aberto!!!";
        return 1;
    }
    
    arquivo >> altura;
    MaiorAltura = altura;
    MenorAltura = altura;
    i = 0;      
    
    while (altura > 0) {
        i = i + 1;
        cout << "\nAltura " << i << "° foi " << altura;         
        if (MaiorAltura < altura) {
            MaiorAltura = altura;
            iMaior = i;
        }
        if ( (MenorAltura > altura) and (altura != 0) ) {
            MenorAltura = altura;
            iMenor = i;
        }
        soma = soma + altura;
        arquivo >> altura;       
    }
    media = soma / i;
    printf("\nA media das pessoas é %.2fm", media);
    printf("\nA menor das alturas foi a %d° pessoa ", iMenor);
    printf("com %.2fm", MenorAltura);
    printf("\nA maior das alturas foi a %d° pessoa ", iMaior);
    printf("com %.2fm", MaiorAltura);

    return 0;
}


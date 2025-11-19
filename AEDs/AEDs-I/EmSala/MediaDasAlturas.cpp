#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char** argv) {

    int i, iMaior, iMenor , QuantAlturas, QuantidadePedida;
    float altura, media, soma, MaiorAltura, MenorAltura;

    i = 1;
    soma = 0;

    printf("Digite a quantidade de pessoas que você quer calcular a media das altura: ");
    scanf("%d", &QuantidadePedida);
    QuantAlturas = 0;
    srand(time(NULL));
    
    MaiorAltura = 0;
    MenorAltura = 10;
          
    while (QuantidadePedida > 0) {


        // printf("digite a altura da %d° pessoa: ",i);
        altura = rand() % 231;
        
        while (altura < 150){
            altura = rand() %230;
        }
        QuantAlturas = QuantAlturas + 1;
        
        altura = altura / 100;
        
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
        i = i + 1;
        QuantidadePedida = QuantidadePedida - 1;
    }


    media = soma / QuantAlturas;
    printf("\nA media das pessoas é %.2fm", media);
    printf("\nA menor das alturas foi a %d° pessoa ", iMenor);
    printf("com %.2fm", MenorAltura);
    printf("\nA maior das alturas foi a %d° pessoa ", iMaior);
    printf("com %.2fm", MaiorAltura);

    return 0;
}


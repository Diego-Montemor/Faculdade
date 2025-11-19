/* 
 * File:   main.cpp
 * Author: monte
 *
 * Created on 20 de março de 2025, 06:36
 */

#include <cstdlib>
#include <stdio.h>
using namespace std;

int main(int argc, char** argv) {
    
    float numero1, numero2;
    
    printf("digite o numero 1:");
    scanf("%f", &numero1);
    printf("diegite o numero 2:");
    scanf("%f", &numero2);
    
    if (numero2 > numero1){
        printf("numero: %.2f", numero2);
    } else if(numero1 > numero2) {
        printf("\n\tnumero: %.2f", numero1);
    }else{
        printf("\n\tOs numeros são iguais");
    }
    
    return 0;
}


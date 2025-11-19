
#include <cstdlib>
#include <stdio.h>
int main(int argc, char** argv) {
    
    float n1,n2,n3,MaiorNumero;
    
    printf("digite um numero: ");
    scanf("%f", &n1);
    printf("digite outro numero: ");
    scanf("%f", &n2);
    printf("digite mais um numero: ");
    scanf("%f", &n3);
    
    MaiorNumero = n1;    
    if(n2 < MaiorNumero){
        MaiorNumero = n2;
    }
    if(n3 < MaiorNumero){
        MaiorNumero = n3;
    }
    printf("\nO menor numero entre eles é o %.1f",MaiorNumero);
    
    return 0;
}


#include <cstdlib>
#include <stdio.h>

using namespace std;
/*O operador % em uma expressão aritmética retorna o resto da divisão entre dois números inteiros, por exemplo,
 * 27 % 5 resulta no valor 2. Peça ao usuário um ano e determine se ele é bissexto. Um ano é bissexto se:
 * For divisível por 4 e não for divisível por 100, ou
 *For divisível por 400
 *Exemplo: 2024 é bissexto, mas 1900 não é.*/
int main(int argc, char** argv) {
    int ano;
    float validacao1,validacao2; 
    
    printf("digite um ano:");
    scanf("%d", &ano);
            
    validacao1 = ano%4;
    validacao2 = ano%100;
    if (validacao1 == 0 and  validacao2 != 0){
        printf("\nesse ano é bissexto!");
    } else{
        printf("\nesse ano não é bissexto!");
    }
    
    return 0;
}
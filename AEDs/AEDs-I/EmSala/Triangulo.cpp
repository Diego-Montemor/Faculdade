#include <cstdlib>
#include <stdio.h>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {

    // Declara os três lados do triângulo como números de ponto flutuante
    float L1, L2, L3;

    // Entrada do lado 1
    printf("digite o valor do lado 1: ");
    scanf("%f", &L1);
    // Entrada do lado 2
    printf("digite oo valor do lado 2:");
    scanf("%f", &L2);
    // Entrada do lado 3
    printf("digite o valor do lado 3:");
    scanf("%f", &L3);

    // Primeiro, valida se os lados são não negativos
    if ((L1 >= 0) and (L2 >= 0) and (L3 >= 0)) {
        // Verifica a desigualdade triangular (cada lado menor que a soma dos outros e maior que a diferença absoluta)
        // Usa fabs de <cmath> para módulo. A condição checa as três permutações possíveis.
        if (((fabs(L2 - L3) < L1 and L1 < L2 + L3) or (fabs(L1 - L3) < L2 and L2 < L1 + L3) or (fabs(L1 - L2) < L3 and L3 < L1 + L2))) {
            // Se passou, é um triângulo válido; imprime o tipo a seguir
            printf("Esse triangulo é valido e é um: ");

            // Caso 1: triângulo escaleno (todos os lados diferentes)
            if (L1 != L2 and L1 != L3 and L2 != L3) {
                printf("Escaleno");
                // Verificação de triângulo retângulo (Teorema de Pitágoras nas três combinações)
                if (((L1 * L1) == (L2 * L2)+(L3 * L3)) or ((L2 * L2) == (L1 * L1)+(L3 * L3)) or (L3 * L3) == (L1 * L1)+(L2 * L2)) {
                    printf(" E tambem é um triangulo retangulo");
                }
            // Caso 2: triângulo isósceles (dois lados iguais e o terceiro diferente)
            } else if ((L1 == L2 and L2 != L3) or (L3 == L1 and L1 != L2) or (L3 == L2 and L2 != L1)) {
                printf("Isoceles");
                // Checa se também é retângulo
                if (((L1 * L1) == (L2 * L2)+(L3 * L3)) or ((L2 * L2) == (L1 * L1)+(L3 * L3)) or (L3 * L3) == (L1 * L1)+(L2 * L2)) {
                    printf(" E tambem é um triangulo retangulo");
                }
            // Caso 3: triângulo equilátero (os três lados iguais)
            } else if (L1 == L2 and L1 == L3) {
                printf("Equilatero");
            }
        } else {
            // Não atende à desigualdade triangular
            printf("\nEsse triangulo não é valido");
        }

    } else {
        // Lados negativos implicam triângulo inexistente
        printf("Esse triangulo não existe");
    }

    // Finaliza o programa com sucesso
    return 0;
}


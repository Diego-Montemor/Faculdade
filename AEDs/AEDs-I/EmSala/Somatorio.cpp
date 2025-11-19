#include <cstdlib>
#include <stdio.h>
using namespace std;

int main(int argc, char** argv) {
    
    // Calcula um somatório da expressão ((n1 - n2) / n3) enquanto n3 <= 50
    float somatorio = 0; 
    int n1, n2, n3; 
    
    // Inicializações
    n1 = 50; // começa em 50 e será decrementado a cada iteração
    n2 = 1;  // começa em 1 e será incrementado de 2 em 2 a cada iteração
    n3 = 2;  // começa em 2 e controla a condição do laço
    
    // Laço principal: executa enquanto n3 for menor ou igual a 50
    while (n3 <= 50) {
        // Acumula no somatório o valor da fração (n1 - n2) / n3
        somatorio = ((n1 - n2) / n3) + somatorio;
        
        // Atualiza as variáveis para a próxima iteração
        n1 = n1 - 1; // decrementa 1
        n2 = n2 + 2; // incrementa 2
        n3 = n3 + 1; // incrementa 1
        
    }
    
    // Impressões dos valores finais de n1, n2 e n3 após o laço
    printf("%d", n1);
    printf("\n%d", n2);
    printf("\n%d", n3);
    
    // Exibe o resultado acumulado
    printf("\nO resultado final foi %.2f", somatorio);
    
    return 0;
}


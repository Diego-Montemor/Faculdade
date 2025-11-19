#include <cstdlib>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {
    // Programa: imprime uma tabela de conversão de Celsius (0 a 100) para Fahrenheit, de 5 em 5 graus
    
    // Declaração das variáveis: i (contador), C (Celsius) e F (Fahrenheit)
    int i;
    float C, F;
    
    // Inicializa o contador com 0 (graus Celsius inicial)
    i = 0;
    
    // Laço: repete enquanto i for menor ou igual a 100
    // Cada iteração representa uma linha da tabela, avançando de 5 em 5 graus
    while (i <= 100){
        // Define a temperatura em Celsius como o valor atual do contador
        C = i;
        
        // Converte Celsius para Fahrenheit usando a fórmula: F = C * 1.8 + 32
        F = (C * 1.8) + 32;
        
        // Imprime a temperatura em Celsius (inteira) seguida da equivalente em Fahrenheit (uma casa decimal)
        printf("\n%d°C", (int)C);
        printf(" -> %.1f°F", F);
        
        // Incrementa o contador de 5 em 5 para a próxima linha da tabela
        i = i + 5;
    }
    return 0;
}


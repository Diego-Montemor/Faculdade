/* 
 * File: SistemadeAprovaçãoDeEmpréstimo.cpp
 * Author: Diego Vianna Leite Montemor
 * RA:2025.1.8.023
 * Disciplina: AEDs1 (Pratica)
 * 
 * Created on 22 de março de 2025, 13:51
 * Objetivo: verificar se o usuario esta apto a realizar um emprestimo
 */

#include <cstdlib>
#include <stdio.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    //Cria variaveis
    float RendaMensal, ValorAceito; // Uma variavel do tipo float para ler numeros decimais
    int Idade, ParcelasEmAtrasoAtual, ParcelasEmAtraso2Anos, NomeNegativado;

    //Pede ao usuario inserir as informações que serão utilizadas no programa
    printf("Digite sua idade: ");
    scanf("%d", &Idade);
    printf("Digite sua renda mensal: ");
    scanf("%f", &RendaMensal);
    printf("Digite Quantas parcelas você possui em atraso: ");
    scanf("%d", &ParcelasEmAtrasoAtual);
    printf("Digite quantas parcelas atrasadas nos ultimos 2 anos: ");
    scanf("%d", &ParcelasEmAtraso2Anos);
    printf("Seu nome está negativado Sim(1) Não(0): ");
    scanf("%d", &NomeNegativado);

    if ((70 >= Idade and Idade >= 18)and(NomeNegativado == 0)and(RendaMensal >= 2000)) { // Verifica se o usuario esta apto a realizar um emprestimo
        if ((RendaMensal >= 2000)and(ParcelasEmAtrasoAtual <= 2)) { // Verifica se o usuario está qualificado para o emprestimo de até R$5.000,00
            ValorAceito = 1;
            if ((RendaMensal >= 5000)and(ParcelasEmAtraso2Anos <= 4 and ParcelasEmAtrasoAtual == 0)) { // Verifica se o usuario está qualificado para o emprestimo de até R$20.000,00
                ValorAceito = 2;
                if ((RendaMensal > 10000)and(ParcelasEmAtraso2Anos == 0)) { // Verifica se o usuario está qualificado para emprestimos acima de R$20.000,00
                    ValorAceito = 3;
                }
            }
        }

        // Retorna ao usuario o valor que ele está apto a solicitar
        if (ValorAceito == 1) {
            printf("É possivel fazer um emprestimo no valor de até R$5.000,00");
        } else if (ValorAceito == 2) {
            printf("É possivel fazer um emprestimo no valor de até R$20.000,00");
        } else if (ValorAceito == 3) {
            printf("É possivel fazer um emprestimo acima de R$20.000,00");
        } else { // Para caso o usuario seja aceito na primeira verificação e ainda n esteja apto a realie nenhum emprestimo
            printf("Emprestimo negado");
        }

    } else { // caso o usuario não estiver apto a receper nenhum emprestimo retorna com "Emprestimo negado"
        printf("Emprestimo negado");
    }

    return 0;
}


#include <cstdlib>
#include <stdio.h>
using namespace std;

/*
 Uma loja dá 10% de desconto para compras acima de R$100,00, 15% acima de R$500,00 e 20% acima de R$1.000,00.
 *  E ainda, no cartão de crédito, faz o valor da compra em 3 parcelas para compras até R$500,00,
 *  em 6 parcelas até R$1.000,00 e em 12 parcelas acima disso.
 *  Compras até R$100,00 não parcela no cartão de crédito.
 *  Peça o valor da compra ao usuário e informe o valor final a ser pago, aplicando o desconto se necessário, e o valor das parcelas para o cartão de crédito.
 */

int main(int argc, char** argv) {

    float ValorDaCompra, ValorFinal, ValorDescontado;

    printf("Digite o valor da compra: ");
    scanf("%f", &ValorDaCompra);

    if (ValorDaCompra >= 1000) {
        ValorDescontado = (0.2 * ValorDaCompra);
        ValorFinal = (ValorDaCompra - ValorDescontado);
    } else if (1000 > ValorDaCompra and ValorDaCompra >= 500) {
        ValorDescontado = (0.15 * ValorDaCompra);
        ValorFinal = (ValorDaCompra - ValorDescontado);
    } else if (500 > ValorDaCompra and ValorDaCompra >= 100) {
        ValorDescontado = (0.1 * ValorDaCompra);
        ValorFinal = ValorDaCompra - ValorDescontado;
    } else {
        printf("\nNão tem desconto para esse valor");
    }

    printf("\nValor da compra foi de %.2f",ValorDaCompra);
    printf("\nValor do desconto foi de %.2f", ValorDescontado);
    printf("\nValor total foi de %.2f", ValorFinal);


    if (ValorFinal >= 100) {
        int Resposta, Parcelas;


        printf("\nCaso queira parcelar no Cartão de credito digite 1:");
        scanf("%d", &Resposta);

        if (Resposta = 1) {
            if (ValorFinal >= 1000) {
                Parcelas = 12;
            } else if (1000 > ValorFinal and ValorFinal >= 500) {
                Parcelas = 6;
            } else if (500 > ValorFinal and ValorFinal >= 100) {
                Parcelas = 3;
            }

            printf("\nÉ possivel fazer até %dx ", Parcelas);
            printf("de %.2f sem juros.", (float) (ValorFinal / Parcelas));

        }

    }
    return 0;
}


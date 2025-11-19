#include <cstdlib>
#include <stdio.h>

int main(int argc, char** argv) {

    char* Classificacao;
    int AnosDeHabilitacao, InfracaoNosUltimosAnos, InfracoesGravesNosUltimosAnos, Idade;

    // Solicita ao usuário as informações necessárias   
    printf("Digite sua idade: ");
    scanf("%d", &Idade);
    printf("Digite há quantos anos você possui sua habilitação: ");
    scanf("%d", &AnosDeHabilitacao);
    printf("Digite quantas Infrações você cometeu nos ultimos 5 anos: ");
    scanf("%d", &InfracaoNosUltimosAnos);
    printf("Digite quantas infrações graves você cometeu nos ultimos 2 anos: ");
    scanf("%d", &InfracoesGravesNosUltimosAnos);

    if ((Idade < 18) or ( (18 >= Idade and Idade >=21) and AnosDeHabilitacao < 2 ) ){// Verifica se o usuário é menor de idade ou não possui habilitação suficiente
        Classificacao = "Inesperiente";
    } else if((65 >= Idade and Idade >= 22) and AnosDeHabilitacao >= 2 and InfracoesGravesNosUltimosAnos == 0 ){// Verifica se o usuário é maior de idade, possui habilitação suficiente e não cometeu infrações graves
        Classificacao = "Regular";
    } else if((Idade < 21 and InfracoesGravesNosUltimosAnos > 0) or Idade > 65 or (InfracaoNosUltimosAnos > 4) or InfracoesGravesNosUltimosAnos > 0 ){// Verifica se o usuário é menor de idade, cometeu infrações graves ou tem muitas infrações
        Classificacao = "Risco";
    } else if((60 >= Idade and Idade >= 30) and AnosDeHabilitacao > 5 and InfracaoNosUltimosAnos == 0 ){// Verifica se o usuário é maior de idade, possui habilitação suficiente e não cometeu infrações
        Classificacao = "Seguro";
    } else {// Caso não se encaixe em nenhuma das classificações anteriores
        printf("Esta faltando considerar algo");
    }

    printf("\nVocê foi classificado como um motorista: ");
    printf(Classificacao);// Retorna a classificação do motorista


    return 0;
}


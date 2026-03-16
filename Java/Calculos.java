import java.util.Scanner;
import java.util.ArrayList;

public class Calculos {
    public void main(String[] args) {
        Scanner leitor = new Scanner(System.in);
        System.out.println("Qual calculo você deseja realizar?");
        System.out.println("(1).Soma de n numeros");
        System.out.println("(2).Media de n numeros");
        System.out.println("(3).Fatorial de um numero");
        System.out.println("(4).Hello World!");
        System.out.println("(0).Sair");
        int opcao = leitor.nextInt();
        switch (opcao) {
            case 1:
                int valor = 1;
                int valorSoma = 0;
                while(valor != 0){
                    System.out.println("Digite um numero diferente de 0(zero) para ser somado: ");
                    valor = leitor.nextInt();
                    valorSoma = Somar(valor, valorSoma);
                }
                System.out.println("o valor obtido da soma de todos os numeros: " + valorSoma);
                break;
            case 2:
                int soma = 0, i = 0;
                int numero = 1, maisnumero = 1;
                while(maisnumero != 0){
                    i = i + 1;
                    System.out.println("Qual numero você deseja adicionar?");
                    numero = leitor.nextInt();
                    soma = Somar(numero, soma);
                    System.out.println("Deseja adicionar mais um numero?");
                    System.out.println("(1).Sim   (0).Não");
                    maisnumero = leitor.nextInt();
                }
                System.out.println("A media dos valores deu " + soma/i);
                break;
            case 3:
                System.out.println("Qual numero você deseja saber o fatorial?");
                int num = leitor.nextInt();
                num = fatorial(num);
                System.out.println("O fatorial é " + num);
                break;
            case 4:
                System.out.println("chamando o Hello World!");
                new HelloWorld();// daria pra ser: HelloWorld qualquernome = new HelloWorld(); e dessa forma n precisa de "static" na criação da função
                System.out.println(HelloWorld.olamundo());
                break;
        }
    }

    void Mmedia() {
        Scanner leitor = new Scanner(System.in);

        System.out.println("Digite o primeiro valor: ");
        int num1 = leitor.nextInt();

        System.out.println("Digite o segundo valor: ");
        int num2 = leitor.nextInt();

        double resultado = Media(num1,num2);
        System.out.println("A media dos numeros " + num1 + " e " + num2 + " é: " + resultado);
    }

    int Somar(int a, int b){
        return a+b;
    }

    double Media(int a, int b){
        return (a+b)/2;
    }

    int fatorial(int n){
        if(n==1){
            return 1;
        }else {
            return n*fatorial(n-1);
        }
    }
}

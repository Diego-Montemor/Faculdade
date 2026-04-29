package versao1_5;
import java.lang.classfile.instruction.SwitchCase;
import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class TesteConta {
    public static void main(String[] args) {
        Conta conta = new Conta(1000, "Diego", "Montemor");
        System.out.println("conta criada com o saldo inicial de R$ 1.000,00");
        int opcao = 1;
        Scanner escolha = new Scanner(System.in);

        while (opcao != 0){
            System.out.println("   -[Menu]-");
            System.out.println("(1).Depositar");
            System.out.println("(2).Sacar");
            System.out.println("(3).Checar saldo");
            System.out.println("(0).Sair");
            opcao = escolha.nextInt();
            switch (opcao) {
                case 1 -> {
                    System.out.print("Digite o valor que deseja depositar R$:");
                    float valor = escolha.nextFloat();
                    conta.depositar(valor);
                }
                case 2 -> {
                    System.out.print("Digite o valor que deseja sacar R$:");
                    float valor = escolha.nextFloat();
                    conta.sacar(valor);
                }
                case 3 -> System.out.println("Saldo atual: R$" + conta.getSaldo());
            }
        }


        System.out.println("valor atual na conta R$" + conta.getSaldo());
    }
}

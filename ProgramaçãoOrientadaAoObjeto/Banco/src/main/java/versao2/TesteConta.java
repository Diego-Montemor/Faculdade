package versao2;

import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class TesteConta {
    public static void main(String[] args) {
        Banco banco = new Banco();
        banco.addCliente(new Conta(1000, "Diego", "Montemor"));
        banco.addCliente(new Conta(3000, "Mariana", "Montemor"));
        banco.addCliente(new Conta(100000, "Matheus", "Montemor"));
        banco.addCliente(new Conta(50, "Wagner", "Montemor"));
        banco.addCliente(new Conta(36218, "Claudia", "Montemor"));

        banco.listClientes();

        Scanner scanner = new Scanner(System.in);
        int op;
        do {
            System.out.println("    [MENU]");
            System.out.println("(1).Criar novo cliente");
            System.out.println("(2).Consltar lista de clientes");
            System.out.println("(0).Sair");
            op = scanner.nextInt();
            switch (op){
                case 1:
                    System.out.println("Digite o nome da conta: ");
                    String nome = scanner.nextLine();
                    System.out.println("Digite o sobrenome: ");
                    String sobrenome = scanner.nextLine();
                    System.out.println("Digite o valor inicial da conta: ");
                    int valor = scanner.nextInt();
                    banco.addCliente(new Conta(valor,nome,sobrenome));
                    break;
                case 2:
                    banco.listClientes();
                    break;
                default:
                    op = 0;
            }

        }while (op != 0);

    }
}

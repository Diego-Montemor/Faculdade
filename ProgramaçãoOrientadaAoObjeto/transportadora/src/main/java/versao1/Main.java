package versao1;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    static void main() {
        System.out.println("Criando o veiculo");
        Veiculo veiculo = new Veiculo(10000);

        System.out.println("Veiculo criado com carga maxima de " + veiculo.getCargaMaxima() + "kg");

        veiculo.setCarga(1000);
        System.out.println("Adicionando carga de 1.000kg");
        veiculo.setCarga(4000);
        System.out.println("adicionando carga de 4.000kg");
        veiculo.setCarga(2000);
        System.out.println("Adicionando carga de 2.000kg");
        veiculo.setCarga(7000);
        System.out.println("Adicionando carga de 7.000kg");

        System.out.println("foi adicionado um total de "+ veiculo.getCarga() + "kg");
    }
}

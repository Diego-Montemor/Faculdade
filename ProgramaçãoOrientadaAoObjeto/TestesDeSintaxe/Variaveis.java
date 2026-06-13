public class Variaveis {
    static void alteraValores(int v1, int v2) {
        v1 = 5;
        v2 = v1;
        v2 = 9;
    }

    static void main() {
        int valor1 = 1;
        int valor2 = 2;
        System.out.println("valor 1 = " + valor1);
        System.out.println("valor 2 = " + valor2);
        System.out.println("apos a função:");
        alteraValores(valor1,valor2);
        System.out.println("valor 1 = " + valor1);
        System.out.println("valor 2 = " + valor2);
    }

}

package org.example;

public class TesteArray {
    public static void exibirArray(int[] array) {
        System.out.print("<");
        for (int i = 0; i < array.length; i++) {
            // Imprime um elemento
            System.out.print(array[i]);
            // Imprime uma vírgula como delimitador se não for o
            // último elemento
            if ((i+1) < array.length) {
                System.out.print(", ");
            }
        }
        System.out.print(">");
    }

    static void exibirMatriz(int[][] matriz) {
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[i].length; j++) {
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();
        }
    }


}

package org.example;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    static void main() {
        int[] array = { 2, 3, 5, 7, 11, 13, 17,19};
        TesteArray.exibirArray(array);
        int[] array2 = array;

        System.out.println("");

        for(int i = 0; i < array2.length; i++){
            if(i % 2 == 0) {
                array2[i] = i;
            }
        }
        TesteArray.exibirArray(array);

        int[][] matriz = new int[5][];

        for(int i = 0; i < matriz.length; i++){
            matriz[i] = new int[i];
            for(int j = 0; j < i; j++){
                matriz[i][j] = j*i;
            }
        }

        TesteArray.exibirMatriz(matriz);
    }

}

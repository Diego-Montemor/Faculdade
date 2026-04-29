package org.example;

public class Livro {

    // Propriedades (variaveis)
    String titulo;
    private int numeroDePaginas;

    // Contrutores

    // Metodos (função)

    void definirNumeroDePaginas(int numeroDePaginas){
        if(numeroDePaginas < 0){
            System.out.println("Erro! A quantidade de paginas precisa ser positivo");
        }else {
            this.numeroDePaginas = numeroDePaginas;
        }
    }
    int nPaginas(){
        return numeroDePaginas;
    }
}

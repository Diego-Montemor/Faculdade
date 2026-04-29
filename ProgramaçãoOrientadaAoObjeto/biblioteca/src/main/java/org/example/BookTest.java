package org.example;

public class BookTest {
    public static  void main(String[] args){
        Livro livro = new Livro();
        livro.titulo = "Divina Comédia";
        livro.definirNumeroDePaginas(-1);
        livro.definirNumeroDePaginas(944);

        System.out.println(livro.titulo + " " + livro.nPaginas());
    }

}

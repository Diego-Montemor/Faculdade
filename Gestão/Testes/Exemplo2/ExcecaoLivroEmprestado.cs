namespace Exemplo2;

public class ExcecaoLivroEmprestado : Exception
{
    public ExcecaoLivroEmprestado()
        : base("O livro já está emprestado.") { }
}

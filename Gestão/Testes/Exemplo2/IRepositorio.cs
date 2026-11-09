namespace Exemplo2;

// Contrato que permite trocar a implementação de armazenamento.
public interface IRepositorio
{
    void AdicionarLivroAcervo(string isbn, Livro livro);
    bool LivroEstaEmprestado(Livro livro);
    void EmprestarLivro(Livro livro, Usuario usuario);
    void ReceberLivroEmprestado(Livro livro);
    List<Livro> LivrosEmprestadosUsuario(Usuario usuario);
}

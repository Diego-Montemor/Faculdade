namespace Exemplo2;

// Serviço: recebe o repositório por injeção no construtor.
public class Biblioteca
{
    private readonly IRepositorio _repo;

    public Biblioteca(IRepositorio repo) => _repo = repo;

    public void AdicionarLivroAcervo(Livro livro)
        => _repo.AdicionarLivroAcervo(livro.ISBN, livro);

    public void EmprestarLivro(Livro livro, Usuario usuario)
    {
        if (_repo.LivroEstaEmprestado(livro))
            throw new ExcecaoLivroEmprestado();

        _repo.EmprestarLivro(livro, usuario);
    }

    public void ReceberLivroEmprestado(Livro livro)
        => _repo.ReceberLivroEmprestado(livro);

    public List<Livro> LivrosEmprestadosUsuario(Usuario usuario)
        => _repo.LivrosEmprestadosUsuario(usuario);
}

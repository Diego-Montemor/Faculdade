namespace Exemplo2;

public class RepositorioMemoria : IRepositorio
{
    private readonly Dictionary<string, Livro> _acervo = new();
    private readonly Dictionary<Livro, Usuario> _emprestimos = new();

    public void AdicionarLivroAcervo(string isbn, Livro livro)
        => _acervo[livro.ISBN] = livro;

    public bool LivroEstaEmprestado(Livro livro)
        => _emprestimos.ContainsKey(livro);

    public void EmprestarLivro(Livro livro, Usuario usuario)
        => _emprestimos[livro] = usuario;

    public void ReceberLivroEmprestado(Livro livro)
        => _emprestimos.Remove(livro);

    public List<Livro> LivrosEmprestadosUsuario(Usuario usuario)
        => _emprestimos
            .Where(e => ReferenceEquals(e.Value, usuario))
            .Select(e => e.Key)
            .ToList();
}

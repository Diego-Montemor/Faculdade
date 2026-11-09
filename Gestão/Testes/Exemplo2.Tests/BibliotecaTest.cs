using Exemplo2;
using Xunit;

namespace Exemplo2.Tests;

public class BibliotecaTest
{
    private readonly Biblioteca _bib = new(new RepositorioMemoria());
    private readonly Livro _livro1 = new("isbn1", "ESM");
    private readonly Livro _livro2 = new("isbn2", "GoF");
    private readonly Livro _livro3 = new("isbn3", "XP");
    private readonly Usuario _usuario1 = new("usu1", "Joao");
    private readonly Usuario _usuario2 = new("usu2", "Maria");

    // O xUnit cria uma instância desta classe para cada teste.
    // O construtor substitui o @BeforeEach do JUnit.
    public BibliotecaTest()
    {
        _bib.AdicionarLivroAcervo(_livro1);
        _bib.AdicionarLivroAcervo(_livro2);
        _bib.AdicionarLivroAcervo(_livro3);
    }

    [Fact]
    public void TestaEmprestimo()
    {
        _bib.EmprestarLivro(_livro1, _usuario1);
        _bib.EmprestarLivro(_livro2, _usuario1);
        var emprestados = _bib.LivrosEmprestadosUsuario(_usuario1);
        Assert.Equal(2, emprestados.Count);
        Assert.Contains(_livro1, emprestados);
        Assert.Contains(_livro2, emprestados);
    }

    [Fact]
    public void TestaEmprestimoVazio()
    {
        Assert.Empty(_bib.LivrosEmprestadosUsuario(_usuario1));
    }

    [Fact]
    public void TestaEmprestimoEDevolucao()
    {
        _bib.EmprestarLivro(_livro1, _usuario1);
        _bib.EmprestarLivro(_livro2, _usuario1);
        _bib.ReceberLivroEmprestado(_livro1);
        var emprestados = _bib.LivrosEmprestadosUsuario(_usuario1);
        Assert.Single(emprestados);
        Assert.DoesNotContain(_livro1, emprestados);
        Assert.Contains(_livro2, emprestados);
    }

    [Fact]
    public void TestaEmprestarLivroJaEmprestado()
    {
        _bib.EmprestarLivro(_livro1, _usuario1);
        Assert.Throws<ExcecaoLivroEmprestado>(
            () => _bib.EmprestarLivro(_livro1, _usuario2));
    }
}

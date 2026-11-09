using Exemplo4;
using Moq;
using Xunit;

namespace Exemplo4.Tests;

public class BookSearchTest
{
    private readonly Mock<IBookService> _service = new();

    // O construtor roda antes de cada teste (equivale ao @BeforeEach do JUnit).
    // Aqui "programamos" o mock: para cada ISBN, qual JSON ele deve devolver.
    public BookSearchTest()
    {
        _service.Setup(s => s.Search(It.IsAny<int>())).Returns(BookConst.NullBook);   // qualquer ISBN
        _service.Setup(s => s.Search(1234)).Returns(BookConst.Esm);
        _service.Setup(s => s.Search(5678)).Returns(BookConst.Hp);
    }

    [Fact]
    public void TestGetBook()
    {
        var bs = new BookSearch(_service.Object);   // .Object é o serviço falso
        string titulo = bs.GetBook(1234).Titulo;
        Assert.Equal("Eng Soft Moderna", titulo);
    }

    [Fact]
    public void TestGetAnotherBook()
    {
        var bs = new BookSearch(_service.Object);
        string titulo = bs.GetBook(5678).Titulo;
        Assert.Equal("Harry Potter", titulo);
    }

    [Fact]
    public void TestGetNullBook()
    {
        var bs = new BookSearch(_service.Object);
        string titulo = bs.GetBook(635263).Titulo;
        Assert.Equal("NULL", titulo);
    }
}

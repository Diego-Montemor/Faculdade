using System.Text.Json;

namespace Exemplo4;

// Classe testada. Ela depende de IBookService, que recebe pelo construtor:
// por isso o teste pode entregar um serviço falso (mock) no lugar do real.
public class BookSearch
{
    private readonly IBookService _rbs;

    public BookSearch(IBookService rbs)
    {
        _rbs = rbs;
    }

    public Book GetBook(int isbn)
    {
        string json = _rbs.Search(isbn);
        using JsonDocument obj = JsonDocument.Parse(json);   // equivale ao JSONObject do Java
        string titulo = obj.RootElement.GetProperty("titulo").GetString()!;
        return new Book(titulo);
    }
}

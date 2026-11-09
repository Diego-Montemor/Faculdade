namespace Exemplo7;

// Implementação que satisfaz o primeiro teste.
public class ShoppingCart
{
    private readonly List<Book> _items = new();
    private double _total;

    public void Add(Book book)
    {
        _items.Add(book);
        _total += book.Price;
    }

    public double GetTotal() => _total;
}

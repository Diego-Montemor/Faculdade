namespace Exemplo7;

public class Book
{
    public string Title { get; }
    public double Price { get; }
    public string Isbn { get; }

    public Book(string title, double price, string isbn)
    {
        Title = title;
        Price = price;
        Isbn = isbn;
    }
}

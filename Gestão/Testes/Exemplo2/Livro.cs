namespace Exemplo2;

// Entidade. Mantemos identidade por referência, como no exemplo Java.
public class Livro
{
    public string ISBN { get; }
    public string Nome { get; }

    public Livro(string isbn, string nome)
    {
        ISBN = isbn;
        Nome = nome;
    }
}

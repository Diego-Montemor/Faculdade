using Exemplo7;
using Xunit;

namespace Exemplo7.Tests;

public class ShoppingCartTest
{
    [Fact]
    public void TestAddGetTotal()
    {
        // Arrange: prepara os livros e o carrinho.
        var b1 = new Book("book1", 10, "1");
        var b2 = new Book("book2", 20, "2");
        var cart = new ShoppingCart();

        // Act: executa a operação.
        cart.Add(b1);
        cart.Add(b2);

        // Assert: tolerância de 0,01, como no teste original.
        Assert.InRange(Math.Abs(30.0 - cart.GetTotal()), 0.0, 0.01);
    }
}

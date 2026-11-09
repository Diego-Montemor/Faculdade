namespace Exemplo4;

// Serviço remoto de busca de livros: recebe um ISBN e devolve os dados em JSON.
// Em produção, ele faria uma chamada pela rede. No teste, é substituído por um mock.
// (Em C#, por convenção, o nome de uma interface começa com "I".)
public interface IBookService
{
    string Search(int isbn);
}

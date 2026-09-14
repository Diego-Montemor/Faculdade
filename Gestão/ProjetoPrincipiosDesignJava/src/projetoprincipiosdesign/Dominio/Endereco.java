package projetoprincipiosdesign.Dominio;

public class Endereco {
    private String logradouro;
    private Cidade cidade;

    public Endereco(String logradouro, Cidade cidade) {
        this.logradouro = logradouro;
        this.cidade = cidade;
    }

    public String getLogradouro() {
        return logradouro;
    }

    public void setLogradouro(String logradouro) {
        this.logradouro = logradouro;
    }

    public String getCidade() {
        return cidade.getNome();
    }

    public void setCidade(Cidade cidade) {
        this.cidade = cidade;
    }

    public String getCidadeNome() {
        return this.cidade.getNome();
    }
}

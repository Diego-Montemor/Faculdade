package versao1_5;

public class Conta {
    private double saldo;
    private String nome;
    private String sobreNome;
    public Conta(double valor, String dNome,String dSobrenome){
        saldo = valor;
        nome = dNome;
        sobreNome = dSobrenome;
    }

    public double getSaldo(){
        return saldo;
    }

    public String getNome(){
        return nome;
    }
    public String getSobreNome(){
        return sobreNome;
    }

    public String getNomeInteiro(){
        return nome + " " + sobreNome;
    }

    public void depositar(double valor){
        saldo = saldo + valor;
        System.out.println("R$" + valor + " depositado");
    }

    public void sacar(double valor){
        if(valor <= saldo) {
            saldo = saldo - valor;
            System.out.println("R$" + valor + "sacado");
        }
    }
}

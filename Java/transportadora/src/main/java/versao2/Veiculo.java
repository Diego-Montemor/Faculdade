package versao2;

public class Veiculo {
    private double cargaMaxima;
    private double carga = 0;

    public Veiculo(double valor){
        cargaMaxima = valor;
    }

    public double getCargaMaxima(){
        return cargaMaxima;
    }
    
    public void setCarga(double valor){
        carga = carga + valor;
    }
    
    public double getCarga(){
        return carga;
    }
}

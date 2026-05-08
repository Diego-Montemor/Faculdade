package versao2;

import java.util.ArrayList;
import java.util.List;

public class Banco {
    private List<Conta> clientes = new ArrayList<>();

    public void addCliente(Conta conta){
        clientes.add(conta);
    }

    public void listClientes(){
        for(int i = 0; i < clientes.size();i++){
            System.out.println("(" + (i+1) + ")." + clientes.get(i).getNomeInteiro() + ". Saldo atual: R$"+ clientes.get(i).getSaldo());
        }
    }
}

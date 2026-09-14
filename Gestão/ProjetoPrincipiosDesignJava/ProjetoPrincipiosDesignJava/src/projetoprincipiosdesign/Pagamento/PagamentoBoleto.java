package projetoprincipiosdesign.Pagamento;

import projetoprincipiosdesign.Persistencia.IPagamentoBoleto;

public class PagamentoBoleto implements IPagamentoBoleto {
    @Override
    public void gerarBoleto(double valor) {
        System.out.printf("Linha digitável gerada para R$ %.2f%n", valor);
    }
}

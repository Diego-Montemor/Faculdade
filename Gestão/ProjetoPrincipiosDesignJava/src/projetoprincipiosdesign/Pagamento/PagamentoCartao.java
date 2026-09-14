package projetoprincipiosdesign.Pagamento;

import projetoprincipiosdesign.Persistencia.IPagamentoCartao;

public class PagamentoCartao implements IPagamentoCartao {
    @Override
    public void parcelar(double valor, int parcelas) {
        System.out.printf(
            "Cartão parcelado em %dx de R$ %.2f%n",
            parcelas,
            valor / parcelas
        );
    }
}

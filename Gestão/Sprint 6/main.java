import java.util.ArrayList;
import java.util.List;

class Console {
    private final String nome;
    private final String tipo;
    private final double preco;

    public Console(String nome, String tipo, double preco) {
        if (nome == null || nome.isBlank() || tipo == null || tipo.isBlank() || preco < 0) {
            throw new IllegalArgumentException("Dados inválidos para o console.");
        }
        this.nome = nome;
        this.tipo = tipo;
        this.preco = preco;
    }

    public String getNome() {
        return nome;
    }

    public String getTipo() {
        return tipo;
    }

    public double getPreco() {
        return preco;
    }
}

interface IConsole {
    void ligar();

    double calcularPreco();

    String getNome();
}

class DadosConsole {
    private final String nome;
    private final double precoBase;

    public DadosConsole(String nome, double precoBase) {
        if (nome == null || nome.isBlank() || precoBase < 0) {
            throw new IllegalArgumentException("Dados inválidos para o console.");
        }
        this.nome = nome;
        this.precoBase = precoBase;
    }

    public String getNome() {
        return nome;
    }

    public double getPrecoBase() {
        return precoBase;
    }
}

class Nintendo implements IConsole {
    private final DadosConsole dados;

    public Nintendo(String nome, double precoBase) {
        this.dados = new DadosConsole(nome, precoBase);
    }

    @Override
    public void ligar() {
        System.out.println("Nintendo ligado.");
    }

    @Override
    public double calcularPreco() {
        return dados.getPrecoBase() * 1.10;
    }

    @Override
    public String getNome() {
        return dados.getNome();
    }
}

class Playstation implements IConsole {
    protected final DadosConsole dados;

    public Playstation(String nome, double precoBase) {
        this.dados = new DadosConsole(nome, precoBase);
    }

    @Override
    public void ligar() {
        System.out.println("Playstation ligado.");
    }

    @Override
    public double calcularPreco() {
        return dados.getPrecoBase() * 1.20;
    }

    @Override
    public String getNome() {
        return dados.getNome();
    }
}

class PlaystationPortatil extends Playstation {
    public PlaystationPortatil(String nome, double precoBase) {
        super(nome, precoBase);
    }

    @Override
    public void ligar() {
        System.out.println("Playstation Portátil ligado.");
    }

    @Override
    public double calcularPreco() {
        return dados.getPrecoBase() * 1.15;
    }
}

class Xbox implements IConsole {
    private final DadosConsole dados;

    public Xbox(String nome, double precoBase) {
        this.dados = new DadosConsole(nome, precoBase);
    }

    @Override
    public void ligar() {
        System.out.println("Xbox ligado.");
    }

    @Override
    public double calcularPreco() {
        return dados.getPrecoBase() * 1.18;
    }

    @Override
    public String getNome() {
        return dados.getNome();
    }
}

class Loja {
    public void venderConsole(IConsole console) {
        console.ligar();
        System.out.println(console.getNome() + " -> Preço final: R$ " + console.calcularPreco());
    }

    public void venderVarios(List<IConsole> consoles) {
        for (IConsole console : consoles) {
            venderConsole(console);
        }
    }

    public double calcularFaturamentoTotal(List<IConsole> consoles) {
        double total = 0;
        for (IConsole console : consoles) {
            total += console.calcularPreco();
        }
        return total;
    }
}

public class Atividade_POO_Problema {

    public static void main(String[] args) {
        IConsole nintendo = new Nintendo("Nintendo Switch", 2000);
        IConsole playstation = new Playstation("Playstation 5", 3000);
        IConsole portatil = new PlaystationPortatil("Playstation Portátil", 2500);

        Loja loja = new Loja();
        List<IConsole> consoles = new ArrayList<>();
        consoles.add(nintendo);
        consoles.add(playstation);
        consoles.add(portatil);

        loja.venderVarios(consoles);
        System.out.println("Faturamento total: R$ " + loja.calcularFaturamentoTotal(consoles));

        consoles.add(new Xbox("Xbox Series X", 3500));
        loja.venderVarios(consoles);
        System.out.println("Faturamento total com Xbox: R$ "
                + loja.calcularFaturamentoTotal(consoles));
    }
}

// ===================== PARTE 1 — Encapsulamento =====================
// TODO (1.1): os atributos de Console estão públicos, permitindo que
// qualquer código altere nome/tipo/preco livremente (inclusive para
// valores inválidos, como um preco negativo). Torne os atributos privados.
// TODO (1.2): como os atributos agora são privados, crie métodos getters
// para nome, tipo e preco (pense: por que não criar também setters aqui?).

// ===================== PARTE 2 — Construtores =====================
// TODO (2.1): hoje um Console pode ser criado "pela metade" (por exemplo,
// esquecendo de definir o preco, que ficaria 0.0). Crie um construtor em
// Console que exija nome, tipo e preco, garantindo que todo objeto nasça
// em um estado válido.
// TODO (2.2): atualize o Main para criar os consoles usando o novo
// construtor, em vez de criar o objeto vazio e preencher os atributos um
// a um.

// ===================== PARTE 3 — Interface e Composição =====================
// TODO (3.1): crie uma interface IConsole com três métodos: void ligar(),
// double calcularPreco() e String getNome().
// TODO (3.2): crie uma classe DadosConsole com os atributos privados nome
// e precoBase, um construtor que os receba, e getters para os dois. Essa
// classe vai representar os dados que todo console tem em comum.
// TODO (3.3): crie as classes Nintendo e Playstation, cada uma implementando
// IConsole. Em vez de repetir nome/precoBase dentro delas, cada uma deve
// ter um atributo do tipo DadosConsole e delegar a ele as chamadas de
// getNome() e getPrecoBase() (isso é composição: "ter um" DadosConsole, em
// vez de repetir os mesmos atributos em cada classe).
// TODO (3.4): mova para Nintendo e Playstation a lógica que hoje está no
// if/else da Loja: a mensagem de ligar() e o percentual usado em
// calcularPreco() de cada uma (10% para Nintendo, 20% para Playstation).
// REFLEXÃO: por que usar uma classe separada (DadosConsole) em vez de
// colocar nome/precoBase diretamente dentro de Nintendo e Playstation?

// ===================== PARTE 4 — Herança (usada de forma apropriada) =====================
// TODO (4.1): a classe Console original também previa um console
// "portátil". Em vez de fazer PlaystationPortatil implementar IConsole do
// zero (repetindo tudo o que já existe em Playstation), crie
// PlaystationPortatil como uma subclasse: class PlaystationPortatil extends
// Playstation. (Dica: para isso funcionar, o atributo que guarda o
// DadosConsole em Playstation precisa deixar de ser private e virar
// protected, para que a subclasse consiga acessá-lo.)
// TODO (4.2): sobrescreva (@Override) o método ligar() em
// PlaystationPortatil com a mensagem específica dela.
// TODO (4.3): sobrescreva (@Override) também o método calcularPreco() em
// PlaystationPortatil, usando um percentual próprio (por exemplo, 15% em
// vez dos 20% herdados de Playstation) — afinal, a versão portátil pode ter
// uma composição de custos diferente da versão de mesa.
// REFLEXÃO: PlaystationPortatil está sobrescrevendo DOIS métodos herdados
// de Playstation. Isso é um problema? Compare com o caso de
// PlaystationPortatil.jogarDisco() que vocês viram no material de SOLID
// (Solucao_P1), que lançava UnsupportedOperationException. Qual a diferença
// entre sobrescrever um método para mudar SEU CÁLCULO e sobrescrever um
// método para RECUSAR fazer o que ele promete (violando o Princípio de
// Substituição de Liskov)?

// ===================== PARTE 5 — Polimorfismo e Extensibilidade (OCP) =====================
// TODO (5.1): reescreva venderConsole() da Loja para que ele receba um
// IConsole (não mais um Console) e apenas chame console.ligar() e
// console.calcularPreco(), sem nenhum if/else ou instanceof.
// TODO (5.2): crie em Loja um método venderVarios(List<IConsole> consoles)
// que chame venderConsole() para cada elemento de uma lista.
// TODO (5.3): crie em Loja um método
// calcularFaturamentoTotal(List<IConsole> consoles), que retorne a soma de
// calcularPreco() de todos os consoles da lista.
// TODO (5.4) [extensibilidade]: crie uma nova classe Xbox implementando
// IConsole (com seu próprio percentual, por exemplo 18%), SEM alterar
// nenhuma linha da classe Loja.
// TODO (5.5): no Main, monte uma List<IConsole> com os consoles já
// existentes, chame venderVarios() e calcularFaturamentoTotal(); em
// seguida, adicione um Xbox a essa lista e chame os dois métodos de novo,
// sem alterar Loja.
// DESAFIO FINAL: o que precisou mudar em Loja para o Xbox passar a
// funcionar? O que isso demonstra sobre o Princípio Aberto/Fechado (OCP)?

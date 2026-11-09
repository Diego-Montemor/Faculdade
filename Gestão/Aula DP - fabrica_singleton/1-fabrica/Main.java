/**
* Exercício sobre o padrão de projeto Fábrica
*/

// TODO (1): crie aqui uma interface chamada "IChannel", com um método connect()
// Ela vai representar o "produto" que a fábrica saberá criar.
public interface IChannel {
    public void connect();
}


public static class TCPChannel implements IChannel {
    // TODO (2): faça esta classe implementar a interface IChannel
    // (isso é necessário para que ela possa ser retornada pela fábrica)

    public void connect() {
        System.out.println("Conectando via TCP...");
    }
}

// TODO (3): crie aqui uma classe UDPChannel, também implementando IChannel,
// cujo método connect() imprima "Conectando via UDP..."
// (essa classe vai servir para você testar a troca de implementação no final)
public static class UDPChannel implements IChannel {
    public void connect(){
        System.out.println("Conectando via UDP...");
    }

}

// TODO (4): crie aqui uma classe ChannelFactory com um método fábrica
// estático create(), que centralize a decisão de qual Channel instanciar.
// Ex.: public static Channel create() { ... return new TCPChannel(); }
public static class ChannelFactory {
    private static IChannel channel = new TCPChannel();
    public static Channel create(){
        return channel;
    }
}

interface Channel {}

public static void main() {
    ChannelFactory factory = new ChannelFactory();
    void f() {
        // TODO (5): O que deve ser alterado aqui?
        TCPChannel c = factory.create();
        c.connect();
    }

    void g() {
        // TODO (6): faça a mesma alteração da dica (5) aqui
        TCPChannel c = factory.create();
        c.connect();
    }

    void h() {
        // TODO (7): faça a mesma alteração da dica (5) aqui
        TCPChannel c = factory.create();
        c.connect();
    }

    m.f();
    m.g();
    m.h();

}

// TODO (8) [extra]: depois de terminar, altere apenas o método create() da
// ChannelFactory para retornar um UDPChannel em vez de um TCPChannel, e rode
// o programa novamente. Repare que nenhuma outra classe precisou ser alterada.

extern int nlinha;
void yyerror(const char *);

void erro_semantico(char *s){
    fprintf(stderr, "Erro léxico na linha %d.\n", nlinha);
    fprintf(stderr, " símbolo %s desconhecido\n\n", s);
    exit(10);
}

enum {
    INT = 10,
    LOG = 20
};

#define TAMPILHA 100
int Pilha[TAMPILHA];
int topo = -1;

void empilha (int v){
    if (topo > TAMPILHA) yyerror("Pilha cheia");
    Pilha[++topo] = v;
}

int desempilha (){
    if (topo == -1 ) yyerror("Pilha Vazia");
    return Pilha[topo--];
}

#define TAMTAB 100
typedef struct {
    char nome[30];
    int tipo;
    int desl;
} tiptab;

tiptab elementab, tabsimb[TAMTAB];
int topotab = -1;

void inseresimbolos(tiptab elem){
    int i;
    for (i = 0; i <= topotab; i++) {
        if (strcmp(elem.nome, tabsimb[i].nome) == 0) {
            erro_semantico("Identificador duplicado");
        }
    }
    tabsimb[++topotab] = elem;
}

int buscasimbolo(char *nome){
    int i;
    for (i = 0; i <= topotab; i++) {
        if (strcmp(nome, tabsimb[i].nome) == 0) {
            return i;
        }
    }
    erro_semantico("Identificador não encontrado");
    return -1;
}

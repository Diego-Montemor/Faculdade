%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.c"

int yylex();
void yyerror(const char *);
extern FILE *yyin, *yyout;
extern int nlinha;
extern char atomo[30];
int contavar = 0;
int rotulo = 0;
int tipo;
#define DEBUG(x) 

%}

%token T_PROG
%token T_INICIO
%token T_FIM
%token T_IDENTIF
%token T_LEIA
%token T_ESCREVA
%token T_ENQTO
%token T_FACA
%token T_FIMENQTO
%token T_SE 
%token T_ENTAO
%token T_SENAO
%token T_FIMSE
%token T_ATRIB
%token T_VEZES
%token T_DIV
%token T_MAIS
%token T_MENOS
%token T_MAIOR
%token T_MENOR
%token T_IGUAL
%token T_E 
%token T_OU
%token T_V 
%token T_F 
%token T_NUMERO
%token T_NAO 
%token T_ABRE
%token T_FECHA
%token T_LOGICO
%token T_INTEIRO

%define parse.error custom

%left T_E T_OU
%left T_IGUAL
%left T_MAIOR T_MENOR
%left T_MAIS T_MENOS
%left T_VEZES T_DIV

%%
programa
    : cabecalho 
        { fprintf(yyout,"\tINPP\n"); }
      variaveis 
        {
            DEBUG(mostratabela();)
            empilha(contavar);
            if (contavar > 0) {   
                fprintf(yyout,"\tAMEM\t%d\n",contavar); 
            }
        }
      T_INICIO lista_comandos T_FIM
        { 
            int conta = desempilha();
            if (conta > 0)
                fprintf(yyout,"\tDEMEM\tX\n");
            fprintf(yyout,"\tFIM\n"); 
            }
    ;

cabecalho
    : T_PROG T_IDENTIF
    ;

variaveis
    : /* vazio */
    | declaracao_variaveis
    ;

declaracao_variaveis
    : tipo lista_variaveis declaracao_variaveis
    | tipo lista_variaveis
    ;

tipo
    : T_LOGICO
        { tipo = LOG; }
    | T_INTEIRO
        { tipo = INT; }
    ;

lista_variaveis
    : lista_variaveis T_IDENTIF
        {
         strcpy(elementab.nome, atomo);
         elementab.tipo = tipo;
         elementab.end = contavar;
         inseresimbolos(elementab);
         contavar++;}
    | T_IDENTIF
        {strcpy(elementab.nome, atomo);
         elementab.tipo = tipo;
         elementab.end = contavar;
         inseresimbolos(elementab);
         contavar++;}
    ;

lista_comandos
    : /* vazio */
    | comando lista_comandos
    ;

comando
    : leitura
    | escrita
    | repeticao
    | selecao
    | atribuicao
    ;

leitura
    : T_LEIA T_IDENTIF
        { 
            int pos = buscasimbolo(atomo);
            fprintf(yyout,"\tLEIA\n\tARZG\t%d\n", tabsimb[pos].end); 
        }
    ;

escrita
    : T_ESCREVA expressao
        { fprintf(yyout,"\tESCR\n"); }
    ;

repeticao
    : T_ENQTO
        { 
        
            fprintf(yyout,"Lx\tNADA\n",++rotulo); 
            empilha(rotulo);    
        } 
      expressao
      T_FACA 
        { 
            fprintf(yyout,"\tDSVF\tLy\n",++rotulo); 
            empilha(rotulo);
        }
      lista_comandos 
      T_FIMENQTO
        { 
            int y = desempilha();
            int x = desempilha();
            fprintf(yyout,"\tDSVS\tL%d\n", x);
            fprintf(yyout,"L%d\tNADA\n", y);   
        }
    ;

selecao
    : T_SE expressao T_ENTAO 
        { 
            fprintf(yyout,"\tDSVF\tL%d\n", ++rotulo); 
            empilha(rotulo);
        }
      lista_comandos T_SENAO 
        { 
            int x = desempilha();
            fprintf(yyout,"\tDSVS\tL%d\n", ++rotulo);
            fprintf(yyout,"\tL%d\tNADA\n",x);
            empilha(rotulo); 
        }
      lista_comandos T_FIMSE
        { 
            int y = desempilha();
            fprintf(yyout,"\tL%d\tNADA\n",y); 
        }
    ;

atribuicao
    : T_IDENTIF 
        {
            int pos = buscasimbolo(atomo);
            empilha(pos);
        }
      T_ATRIB expressao
        { 
            int pos = desempilha();
            fprintf(yyout,"\tARZG\t%d\n", tabsimb[pos].end); 
        }
    ;

expressao
    : expressao T_VEZES expressao
        { fprintf(yyout,"\tMULT\n"); }
    | expressao T_DIV expressao
        { fprintf(yyout,"\tDIV\n"); }
    | expressao T_MAIS expressao
        { fprintf(yyout,"\tSOMA\n"); }
    | expressao T_MENOS expressao
        { fprintf(yyout,"\tSUBT\n"); }
    | expressao T_MAIOR expressao
        { fprintf(yyout,"\tCMMA\n"); }
    | expressao T_MENOR expressao
        { fprintf(yyout,"\tCMME\n"); }
    | expressao T_IGUAL expressao
        { fprintf(yyout,"\tCMIG"); }
    | expressao T_E expressao
        { fprintf(yyout,"\tCONJ\n"); }
    | expressao T_OU expressao
        { fprintf(yyout,"\tDISJ\n"); }
    | termo
    ;

termo
    : T_IDENTIF
        { 
          int pos = buscasimbolo(atomo);
          fprintf(yyout,"\tCRVG\t%d\n", tabsimb[pos].end); 
        }
    | T_NUMERO
        { fprintf(yyout,"\tCRCT\t%s\n", atomo); }
    | T_V
        { fprintf(yyout,"\tCRCT\t1\n"); }
    | T_F
        { fprintf(yyout,"\tCRCT\t0\n"); }
    | T_NAO termo
        { fprintf(yyout,"\tNEGA\n");}
    | T_ABRE expressao T_FECHA
    ; 

%%

void yyerror(const char *mensagem)
{
    fprintf(stderr, "Erro Interno: %s\n", mensagem);
}

static const char *nome_token(yysymbol_kind_t token)
{
    static const char *nomes[] = {
        [YYSYMBOL_T_PROG]      = "programa",
        [YYSYMBOL_T_INICIO]    = "início",
        [YYSYMBOL_T_FIM]       = "fim",
        [YYSYMBOL_T_IDENTIF]   = "identificador",
        [YYSYMBOL_T_LEIA]      = "leia",
        [YYSYMBOL_T_ESCREVA]   = "escreva",
        [YYSYMBOL_T_ENQTO]     = "enquanto",
        [YYSYMBOL_T_FACA]      = "faça",
        [YYSYMBOL_T_FIMENQTO]  = "fim-enquanto",
        [YYSYMBOL_T_SE]        = "se",
        [YYSYMBOL_T_ENTAO]     = "então",
        [YYSYMBOL_T_SENAO]     = "senão",
        [YYSYMBOL_T_FIMSE]     = "fim-se",
        [YYSYMBOL_T_ATRIB]     = "atribuição",
        [YYSYMBOL_T_VEZES]     = "'*'",
        [YYSYMBOL_T_DIV]       = "'/'",
        [YYSYMBOL_T_MAIS]      = "'+'",
        [YYSYMBOL_T_MENOS]     = "'-'",
        [YYSYMBOL_T_MAIOR]     = "'>'",
        [YYSYMBOL_T_MENOR]     = "'<'",
        [YYSYMBOL_T_IGUAL]     = "'='",
        [YYSYMBOL_T_E]         = "e",
        [YYSYMBOL_T_OU]        = "ou",
        [YYSYMBOL_T_V]         = "verdadeiro",
        [YYSYMBOL_T_F]         = "falso",
        [YYSYMBOL_T_NUMERO]    = "número",
        [YYSYMBOL_T_NAO]       = "não",
        [YYSYMBOL_T_ABRE]      = "'('",
        [YYSYMBOL_T_FECHA]     = "')'",
        [YYSYMBOL_T_LOGICO]    = "lógico",
        [YYSYMBOL_T_INTEIRO]   = "inteiro"
    };

    if (token >= 0 &&
        token < sizeof(nomes) / sizeof(nomes[0]) &&
        nomes[token] != NULL)
        return nomes[token];

    return "símbolo desconhecido";
}

static int yyreport_syntax_error(const yypcontext_t *ctx)
{
    yysymbol_kind_t token;
    yysymbol_kind_t expected[10];

    token = yypcontext_token(ctx);

    fprintf(stderr, "Erro de sintaxe na linha %d.\n",nlinha);
    fprintf(stderr, "  Símbolo encontrado: %s\n",
            nome_token(token));

    fprintf(stderr, "  Símbolos esperados: ");

    int n = yypcontext_expected_tokens(ctx, expected, 10);

    for (int i = 0; i < n; i++) {
        if (i > 0)
            fprintf(stderr, ", ");

        fprintf(stderr, "%s", nome_token(expected[i]));
    }
    fprintf(stderr, "\n\n");
    return 0;
}

int main(int argc, char *argv[]) {
    char nameIn[100], nameOut[100], *s;
    if (argc < 2) {
        printf("Uso:\n \t%s <nomeprog[.simples]>\n\n", argv[0]);
        exit(20);
    }
    strcpy(nameIn, argv[1]);
    s = strstr(nameIn, ".simples");
    if (s){
        *s = 0;
    }
    strcpy(nameOut, nameIn);
    strcat(nameOut, ".mvs");
    strcat(nameIn, ".simples");
    yyin = fopen(nameIn, "rt");
    yyout = fopen(nameOut, "wt");
    yyparse();
    fclose(yyin);
    fclose(yyout);
}
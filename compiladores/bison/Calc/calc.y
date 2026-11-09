%{
#include <stdio.h>
%}

%token ENTER
%token MAIS
%token MENOS
%token MULT
%token DIV
%token ABRE
%token FECHA
%token NUM

%start calculo

%left MAIS MENOS MULT DIV

%%

calculo: calculo expr ENTER { printf("Resultado: %d\n", $2); }
       | 
       ;

expr : expr MAIS expr { $$ = $1 + $3; }
     | expr MENOS expr { $$ = $1 - $3; }
     | expr MULT expr { $$ = $1 * $3; }
     | expr DIV expr { $$ = $1 / $3; }
     | ABRE expr FECHA { $$ = $2; }
     | NUM { $$ = $1; }
     ;

%%

void yyerror (char *msg) {
    printf("Erro: %s\n", msg);
} 

int main() {
    return 0;
}

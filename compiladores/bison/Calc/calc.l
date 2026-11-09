%{
#include <stdlib.h>
#include "calc.h"
void yyerror(char *);
%}

%%
"-"    { return MENOS; }
"+"    { return MAIS; }
"*"    { return MULT; }
"/"    { return DIV; }
"("    { return ABRE; }
")"    { return FECHA; }
"\n"   { return ENTER; }
[0-9]+ { return NUM; }
[ \t]  /* faz nada */
.      {
         char msg[100];
         sprintf(msg, "Erro léxico - símbolo desconhecido: %s", yytext);
         yyerror(msg);
         } 

%%

int yywrap (void) { return 1; }
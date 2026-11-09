identificador [a-zA-Z]([a-zA-Z0-9])*
numero [0-9]+
espaco [ \t]+
novalinha [\n]

%%
programa    {printf("%11s: palavra reservada\n", yytext);}
inicio      {printf("%11s: palavra reservada\n", yytext);}
fimprograma {printf("%11s: palavra reservada\n", yytext);}

leia        {printf("%11s: palavra reservada\n", yytext);}
escreva     {printf("%11s: palavra reservada\n", yytext);}

se          {printf("%11s: palavra reservada\n", yytext);}
entao       {printf("%11s: palavra reservada\n", yytext);}
senao       {printf("%11s: palavra reservada\n", yytext);}
fimse       {printf("%11s: palavra reservada\n", yytext);}

enquanto     {printf("%11s: palavra reservada\n", yytext);}
faca         {printf("%11s: palavra reservada\n", yytext);}
fimenquanto   {printf("%11s: palavra reservada\n", yytext);}

"+"          {printf("%11s: operador aritmético soma\n", yytext);}
"-"          {printf("%11s: operador aritmético subtração\n", yytext);}
"*"          {printf("%11s: operador aritmético multiplicação\n", yytext);}
div          {printf("%11s: operador aritmético divisão\n", yytext);}

">"          {printf("%11s: operador relacional maior que\n", yytext);}
"<"          {printf("%11s: operador relacional menor que\n", yytext);}
"="          {printf("%11s: operador relacional igual\n", yytext);}

e            {printf("%11s: operador lógico e\n", yytext);}
ou           {printf("%11s: operador lógico ou\n", yytext);}
nao          {printf("%11s: operador lógico não\n", yytext);}

"<-"         {printf("%11s: operador de atribuição\n", yytext);}
"("          {printf("%11s: delimitador abre parênteses\n", yytext);}
")"          {printf("%11s: delimitador fecha parênteses\n", yytext);}

inteiro       {printf("%11s: tipo de dado inteiro\n", yytext);}
logico        {printf("%11s: tipo de dado lógico\n", yytext);}
V             {printf("%11s: valor lógico verdadeiro\n", yytext);}
F             {printf("%11s: valor lógico falso\n", yytext);}

{identificador} {printf("%11s: identificador\n", yytext);}
{numero}       printf("%11s: número\n", yytext);
{espaco}       /* ignora espaços em branco */
{novalinha}    /* ignora novas linhas */
.              {printf("%11s: símbolo inválido\n", yytext);}

%%

int yywrap(void) {
    return 1;
}  

int main(int argc, char **argv) {
    yylex();
    return 0;
}

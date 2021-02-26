%{
//#include <math.h>
%}
             
/* Declaraciones de BISON */
%union{
	int entero;
}

%token <entero> ENTERO
%type <entero> exp
             
%left '+'
             
/* Gramática */
%%
             
input:    /* cadena vacía */
        | input line             
;

line:     '\n'
        | exp '\n'  { printf ("\tresultado: %d\n", $1); }
;
             
exp:     ENTERO	{ $$ = $1; }
	| exp '+' exp        { $$ = $1 + $3;    }
;

             
%%

int main() {
  yyparse();
}
             
yyerror (char *s)
{
  printf ("--%s--\n", s);
}
            
int yywrap()  
{  
  return 1;  
}  

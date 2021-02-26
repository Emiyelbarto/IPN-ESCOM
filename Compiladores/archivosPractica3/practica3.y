%{
#include <stdio.h>

int yylex();
int yyerror(char *s);

%}

%union{
	int entero;
}

%token <entero> NUM
%type <entero> exp
             
%left '+'
%left '-'
%left '/'
%left '*'

%%

input:  
    | input line
;

line: '\n'
    | exp '\n'{printf("Resultado: %d\n", $1); }
;

exp:     NUM	{ $$ = $1; }
	| exp '+' exp        { $$ = $1 + $3;    }
;
%%

int yyerror(char *s)
{
	printf("Syntax Error on line %s\n", s);
	return 0;
}

int main()
{
    yyparse();
    return 0;
}

int yywrap()  
{  
  return 1;  
}  
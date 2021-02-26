%{
#include "ejemplo2.tab.h"
%}

NUM [0-9]+
%%

{NUM}           {
		printf("Numero entero %s\n",yytext);
                yylval.entero = atoi(yytext);
                return (ENTERO);
                }

"+"	 	{
		printf("Signo mas\n");
                return (yytext[0]);
                }

"\n"            {
		printf("Salto de linea\n");
                return (yytext[0]);
                }
.               ;
%%

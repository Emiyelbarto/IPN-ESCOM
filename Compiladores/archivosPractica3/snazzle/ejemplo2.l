%{
#include "ejemplo2.tab.h"
%}

NUM [0-9]+
SIGN [+,-]
INTEGER {SIGN}?{NUM}+
FLOAT {SIGN}?{NUM}*\.{NUM}+
REAL {INTEGER}|{FLOAT}
SUM {REAL}\+{REAL}
REST {REAL}\-{REAL}
PRODUCT {REAL}\*{REAL}
DIV {REAL}\/{REAL}
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

%{

#include <stdio.h>
#include <string.h>
#include "practica3.tab.h"
void showError();
%}


NUM ([0-9])+
SIGN ([+,-])
INTEGER ({SIGN}?{NUM})+
FLOTANTE ({SIGN}?{NUM}+\.{NUM}+)+
REAL ({INTEGER}|{FLOTANTE})
SUM ({REAL}\+{REAL})
RESTA ({REAL}\-{REAL})
PRODUCTO ({REAL}\*{REAL})
DIV ({REAL}\/{REAL})

%%


{NUM}   {
		printf("Numero entero %s\n",yytext);
                yylval.entero = atoi(yytext);
                return (NUM);        
        }
[Mm][Oo][Dd]?[(]?({INTEGER}|{REAL})?[,]?({INTEGER}|{REAL})?[)] {
    printf(" Mod %s\n",yytext);
}

{SIGN}?{NUM}+ {
    printf(" Numero Entero '%s'\n",yytext);
    yylval.entero = atoi(yytext);
    return (NUM);
}
{SIGN}?{NUM}*\.{NUM}+ {
    printf(" Numero Decimal '%s'\n",yytext);
    yylval.entero = atoi(yytext);
    return (NUM);
    }
{REAL}\^{REAL}     {
    printf(" Potencia '%s'\n",yytext);
    yylval.entero = atoi(yytext);
    return (NUM);
    }
{SUM} { 
    printf(" Suma '%s'\n",yytext); 
    yylval.entero = atoi(yytext);
    return (NUM);
    }
{RESTA} { 
    printf(" Resta '%s'\n",yytext); 
    yylval.entero = atoi(yytext);
    return (NUM);
    }
{PRODUCTO} { 
    printf(" Producto '%s'\n",yytext); 
    yylval.entero = atoi(yytext);
    return (NUM);
    }
{DIV} { 
    printf(" Division '%s'\n",yytext); 
    yylval.entero = atoi(yytext);
    return (NUM);
    }

%%


void showError(){
    printf("Valor no identificado");
}
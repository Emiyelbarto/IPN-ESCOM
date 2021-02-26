signo [+,-]
digito [0-9]
numeroEntero {signo}?{digito}+
numeroDecimal {signo}?{digito}*\.{digito}+
numeroReal {numeroEntero}|{numeroDecimal}
suma {numeroReal}\+{numeroReal}
resta {numeroReal}\-{numeroReal}
producto {numeroReal}\*{numeroReal}
division {numeroReal}\/{numeroReal}
modulo {numeroReal}\%{numeroReal}

%%
[,] {
    printf(" Comma \n");
}

[Mm][Oo][Dd]?[(]?({numeroEntero}|{numeroReal})?[,]?({numeroEntero}|{numeroReal})?[)] {
    printf(" Mod %s\n",yytext);
}

[A-Z,a-z,_][A-Z,a-z,_,0-9]* {
    printf(" Variable '%s'\n",yytext);
    }
{signo}?{digito}+ {
    printf(" Numero Entero '%s'\n",yytext);
}
{signo}?{digito}*\.{digito}+ {
    printf(" Numero Decimal '%s'\n",yytext);
    }
{numeroReal}\^{numeroReal}     {
    printf(" Potencia '%s'\n",yytext);
    }
{suma} { 
    printf(" Suma '%s'\n",yytext); 
    }
{resta} { 
    printf(" Resta '%s'\n",yytext); 
    }
{producto} { 
    printf(" Producto '%s'\n",yytext); 
    }
{division} { 
    printf(" Division '%s'\n",yytext); 
    }
{modulo} { 
    printf(" Modulo '%s'\n",yytext); 
    }

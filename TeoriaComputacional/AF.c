/***************************************************
Descripcion:
Programa que modela el AF=(E,Q,f,q0,F) donde:
E={a,b}, Q={q0, q1, q2, q3}, F={q1, q2}
f:ExQ->Q
f(q0,a)=q1
f(q0,b)=q3
f(q1,a)=q1
f(q1,b)=q2
f(q2,a)=q3
f(q2,b)=q2
f(q3,a)=q3
f(q3,b)=q3
AF que describe el lenguaje dado por la expresión 
regular a+b*. "L(AF)=L(a+b*)"
***************************************************/
//LIBRERIAS Y DEFINICIONES DE CONSTANTES
#include <stdio.h>
#define FIN_CADENA '\n'

//Modelado de los estados
enum{q0,q1,q2,q3};

//PROGRAMA PRINCIPAL
int main (void)
{
	int estado=q0; 	//Estado = Estado inicial q0
	char entrada;	//Caracter de entrada
	
	entrada=getchar();				//Leer la primer entrada
	
	//Ciclo que modela transicin del automata conforme avanza el cabezal de lectura
	while(entrada!=FIN_CADENA) 	//Mientras la entrada no sea el final de la cadena
	{
		switch(estado)
		{
			case q0: //Modelado de las transiciones del estado q0
				if(entrada=='a') estado=q1;
				else if(entrada=='b')estado=q3;
				break;
			case q1: //Modelado de las transiciones del estado q1
				if(entrada=='a') estado=q1;
				else if(entrada=='b')estado=q2;
				break;
			case q2: //Modelado de las transiciones del estado q2
				if(entrada=='a') estado=q3;
				else if(entrada=='b')estado=q2;
				break;
			case q3: //Modelado de las transiciones del estado q3
				if(entrada=='a') estado=q3;
				else if(entrada=='b')estado=q3;
				break;
			default:
				break;					
		}		
		entrada=getchar();	//Leer de la segunda a más entradas
	}
	
	//Comprobar si al alcanzar la configuración final el automata alcanzo un estado final
	if(estado==q1||estado==q2) printf("\nCadena VALIDA en el lenguaje L(a+b*)");
	else printf("\nCadena NO VALIDA en el lenguaje L(a+b*)");

	return 0; //Fin de programa
}

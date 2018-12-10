#include <stdio.h>
#include <stdlib.h>
/*
	En este programa se observa el uso de los arreglos
*/
int size(char *); //tamaño de una cadena
void imprimir(char *,int);//No se usa
char * leerCadena(char *);
void copiarString(char *, char *);
void restar(char *, char *);

int main()
{
	char *buffer;
	buffer=(char *)malloc(255);
	char *s1,*s2;
	printf("\nIntroduce la cadena s1:\n");
	s1=leerCadena(buffer);
	printf("\nIntroduce la cadena s2:\n");
	s2=leerCadena(buffer);
	restar(s2,s1);
	/*
	int sizeOfS1=0,sizeOfS2=0;
	printf("Introduce la cadena s1:\n");
	s1=(char *)malloc(100);
	scanf("%[^\n]",s1);
	fflush(stdin);
	printf("sizeofS1=%d\n",sizeOfS1);
	printf("Introduce la cadena s2:\n");
	s2=(char *)malloc(100);
	scanf("%[^\n]",s2);
	fflush(stdin);
	
	
	*/
	return 0;
}
char * leerCadena(char *buffer){
	char *string;
	scanf("%[^\n]",buffer);
	fflush(stdin);
	string=(char *)malloc((size(buffer)+1));
	copiarString(string,buffer);
	//printf("\n%s",string);//copia correcta
	return string;
}

void copiarString(char *s1, char *s2){
	int iterador=0;
	while(*(s2+iterador)!='\0'){
		*(s1+iterador)=s2[iterador];
		iterador++;
	}
	s1[iterador]='\0';
}

void imprimir(char *string,int size)
{
	int i;
	printf("string = { ");
	for(i=0;i<size;i++)
	{
		printf("%c",string[i]);
	}
	printf("}");
}

int size(char *string){
	int iterador=0;
	while(string[iterador]!='\0'){
		iterador++;
	}
	return iterador;
}

void restar(char *s2, char *s1){
	char *resultado=(char *)malloc(size(s2));
	int flag=0;
	int restado=0;
	int iterador1=0,iterador2=0,iteradorResultado=0;
	while(s2[iterador1]!='\0'){
		//printf("\n%c == %c",s2[iterador1],s1[iterador2]);
		if(s2[iterador1]==s1[iterador2]){
			flag=1;
			while(s1[iterador2]!='\0' && flag == 1 && restado==0){
				//printf("\n-->%c == %c",s2[(iterador1+iterador2)],s1[iterador2]);
				if(s2[(iterador1+iterador2)]==s1[iterador2]){
					flag=1;
				}else{
					flag=0;
				}
				iterador2++;
			}
		}
		if(flag==1){
			iterador1=iterador1+iterador2;
			flag=0;
			restado=1;
		}
		resultado[iteradorResultado]=s2[iterador1];
		iteradorResultado++;
		iterador1++;
	}
	resultado[iteradorResultado]='\0';
	printf("\n%s",resultado);
}
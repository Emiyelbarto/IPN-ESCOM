#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char *cad;
	int *longcad;
}Cadena;

int size(Cadena *);
char * leerCadena(Cadena *);
void copiarString(Cadena *, Cadena *);
void restar(Cadena *, Cadena *);

int main()
{
	Cadena *cad1,*cad2,*buffer;
	
	cad1=(Cadena *)malloc(sizeof(Cadena));
	cad2=(Cadena *)malloc(sizeof(Cadena));
	buffer=(Cadena *)malloc(sizeof(Cadena));
	
	buffer->cad=(char*)malloc(255);
	
	buffer->longcad=(int*)malloc(sizeof(int));
	cad1->longcad=(int*)malloc(sizeof(int));
	cad2->longcad=(int*)malloc(sizeof(int));
		
	printf("\nIntroduce la cadena s1:\n");
	cad1->cad=leerCadena(buffer);
	*(cad1->longcad)=*(buffer->longcad);
	printf("\nIntroduce la cadena s2:\n");
	cad2->cad=leerCadena(buffer);
	*(cad2->longcad)=*(buffer->longcad);
	restar(cad2,cad1);
	return 0;
}
char * leerCadena(Cadena *buffer){
	Cadena *string;
	string=(Cadena *)malloc(sizeof(Cadena));
	scanf("%[^\n]",(buffer->cad));
	fflush(stdin);
	
	string->cad=(char *)malloc((size(buffer)+1));
	copiarString(string,buffer);
	return string->cad;
}

int size(Cadena *string){
	*(string->longcad)=0;
	
	while(string->cad[*(string->longcad)]!='\0'){
		*(string->longcad) = *(string->longcad) + 1;
	}
	return *(string->longcad);
}

void copiarString(Cadena *s1, Cadena *s2){
	int iterador=0;
	while(*(s2->cad+iterador)!='\0'){
		*(s1->cad+iterador)=s2->cad[iterador];
		iterador++;
	}
	s1->cad[iterador]='\0';
}

void restar(Cadena *s2, Cadena *s1){
	char *resultado=(char *)malloc(*s2->longcad);
	int flag=0;
	int restado=0;
	int iterador1=0,iterador2=0,iteradorResultado=0;
	while(s2->cad[iterador1]!='\0'){
		if(s2->cad[iterador1]==s1->cad[iterador2]){
			flag=1;
			while(s1->cad[iterador2]!='\0' && flag == 1 && restado==0){
				if(s2->cad[(iterador1+iterador2)]==s1->cad[iterador2]){
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
		resultado[iteradorResultado]=s2->cad[iterador1];
		iteradorResultado++;
		iterador1++;
	}
	resultado[iteradorResultado]='\0';
	printf("\n%s",resultado);
}

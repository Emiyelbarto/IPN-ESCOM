#include <stdio.h>
#include <stdlib.h>
 
int fxFactorial(int Num){
   if(Num==0)
     return 1;
   else
     return (fxFactorial(Num-1)*Num);
}
 
int main(){
  int Num;
  printf("Ingresa un numero para calcular su factorial : ");
  scanf("%d",&Num);
  printf("El factorial de %d es %d\n",Num,fxFactorial(Num));
}
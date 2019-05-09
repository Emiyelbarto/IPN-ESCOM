//Autor: José Emiliano Pérez Garduño 3CV3

#include  <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int *a, i, n, x, val=1, opc=1;
    while(opc == 1)
	{
	    while(val == 1)
		{
		    printf("Escribir el numero n \n");
		    scanf("%d",&n);
		    if(n < 1 || n > 999)
			{
	        	printf("Escribir un numero n entre 1 y 1000\n");
		    	val = 1;
			}
			else{
				break;
			}    	
		}
	    a = (int*)malloc(sizeof(int) * n);
	    for(i = 0; i < n; i++)
	    {
	        x = rand();
	        if(i == 0)
	        {
	            a[i] = x;
	        }
	        else
	        {
	            if(a[i-1])
	            {
	                a[i] = rand();
	            }
	            else
	            {
	                a[i] = x;
	            }
	        }
	        printf("%d\t",a[i]);
	    }
	    printf("Imprimir de nuevo?\n1.-Si\n2.-No\n");
	    scanf("%d",&opc);
	    if(opc == 1)
		{
	    	opc = 1;
		}
		else
		{
			break;
		}
	}
    return 0;
}

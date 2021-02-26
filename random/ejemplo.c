#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    int N = 10;
    int arreglo[N];

    for (int i = 0; i < N; i++)
    {
        arreglo[i] = i;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d, ", arreglo[i]);
    }

    printf("\n");
    return 0;
}

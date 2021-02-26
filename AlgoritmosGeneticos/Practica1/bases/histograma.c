#include <stdio.h>
//Muestra desde un numero maximo hasta minimo un histograma
int main()
{
    int c, i, j, max;
    int ndigit[10];

    for (i = 0; i < 10; i++)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];

    max = ndigit[0];
    for (i = 1; i < 10; ++i)        /* for Y-axis */
        if (max < ndigit[i])
            max = ndigit[i];

    printf("--------------------------------------------------\n");
    for (i = max; i > 0; --i) {
        printf("%.3d|", i);
        for (j = 0; j < 10; ++j)
            (ndigit[j] >= i) ? printf(" X ") : printf("   ");
        printf("\n");
    }
    printf("   ");
    for (i = 0; i < 10; ++i)        /* for X-axis */
        printf("%3d", i);
    printf("\n--------------------------------------------------\n");
    return 0;
}
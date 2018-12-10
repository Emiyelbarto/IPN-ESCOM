#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct nodo {
    char simbolo;
    struct nodo *sig;
};

struct nodo *raiz=NULL;

void insertar(char x)
{
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->simbolo = x;
    if (raiz == NULL)
    {
        raiz = nuevo;
        nuevo->sig = NULL;
    }
    else
    {
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}


char extraer()
{
    if (raiz != NULL)
    {
        //int char = raiz->simbolo;
        struct nodo *bor = raiz;
        raiz = raiz->sig;
        free(bor);
        return bor;
    }
    else
    {
        return -1;
    }
}

void liberar()
{
    struct nodo *reco = raiz;
    struct nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
}

int vacia()
{
    if (raiz == NULL)
        return 1;
    else
        return 0;
}

void cargarFormula(char *formula)
{
    printf("Ingrese la formula:");
    gets(formula);
}

int verificarBalanceada(char *formula)
{
    int f;
    for (f=0;f<strlen(formula);f++)
    {
        if (formula[f]=='(' || formula[f]=='[' || formula[f]=='{')
        {
            insertar(formula[f]);
        }
        else
        {
            if (formula[f]==')')
            {
                if (extraer()!='(')
                {
                    return 0;
                }
            }
            else
            {
                if (formula[f]==']')
                {
                    if (extraer()!='[')
                    {
                        return 0;
                    }
                }
                else
                {
                    if (formula[f]=='}')
                    {
                        if (extraer()!='{')
                        {
                            return 0;
                        }
                    }
                }
            }
        }
    }
    if (vacia())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    char formula[100];
    cargarFormula(formula);
    if (verificarBalanceada(formula))
    {
        printf("La formula esta correctamente balanceada");
    }
    else
    {
        printf("La formula no esta correctamente balanceada");
    }
    liberar();
    getch();
    return 0;
}

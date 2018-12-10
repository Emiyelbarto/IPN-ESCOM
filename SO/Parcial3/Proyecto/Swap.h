#include"Ram.h"
//void CrearEnSwap(int tam, int Pags);
void MostrarSwap();
//struct Segmento Swap[4];
//void Swapping(int idP);
int Swapear(int tam,int idP, void *D);

int Swapping(int idP)
{
        for(int i=0;i<6;i++)
        {
                for(int j=0;j<6;j++)
                {
                        if(Ram[i].Pag[j].idProceso==idP)
                        {
                                if(Swapear(Ram[i].Pag[j].Tam,idP,Ram[i].Pag[j].Dir))
                                {
                                        printf("\nNo hay espacio en swap\n");
                                        EliminarSwap(idP);
                                        return 0;
                                }
                                else
                                {
                                        Ram[i].Pag[j].idProceso=0;
                                        Ram[i].Pag[j].Tam=0;
                                        Ram[i].Pag[j].Dir=NULL;
                                }
                        }
                }
        }
        return 1;
}


int ValidarSwap(int idP)
{
	int Pags=0;
	for(int i=0;i<6;i++)
        {
                for(int j=0;j<6;j++)
                {
			if(Ram[i].Pag[j].idProceso==idP)
			{
				Pags++;
			}

                }
        }
	for(int i=0;i<4;i++)
        {
                for(int j=0;j<6;j++)
		{
			if(Swap[i].Pag[j].Tam==0)
			{
				Pags--;
				if(Pags==0)
				{
					return 1;
				}
			}
		}
	}

	return 0;

}

int Swapear(int tam,int idP,void *D)
{
	for(int i=0;i<4;i++)
        {
                for(int j=0;j<6;j++)
                {
			if(Swap[i].Pag[j].Tam==0)
			{
				Swap[i].Pag[j].Tam=tam;
                                Swap[i].Pag[j].idProceso=idP;
				Swap[i].Pag[j].Dir=D;
				return 0;
			}
                }

        }
	return 1;
}

void MostrarSwap()
{
	for(int i=0;i<4;i++)
        {
                printf("\n\nSegmento %d:",i+1);
                for(int j=0;j<6;j++)
                {
			printf("\n\tPag %d:\n\t\tid:%d\t%dKB\t%p",j+1,Swap[i].Pag[j].idProceso,Swap[i].Pag[j].Tam,Swap[i].Pag[j].Dir);

                }
        }

}

void CrearEnSwap(int tam, int Pags)
{
	for(int i=0;i<4;i++)
        {
                for(int j=0;j<6;j++)
                {
                        if(Swap[i].Pag[j].Tam==0)
                        {
                                if(Pags==1 && tam%4>0)
                                {
                                        Swap[i].Pag[j].Tam=tam%4;
                                        Swap[i].Pag[j].idProceso=id;
					Swap[i].Pag[j].Dir=&Swap[i].Pag[j].Tam;
                                        Pags--;
                                }
                                else
                                {
                                        Swap[i].Pag[j].Tam=4;
                                        Swap[i].Pag[j].idProceso=id;
					Swap[i].Pag[j].Dir=&Swap[i].Pag[j].Tam;
                                        Pags--;
                                }
                        }

                        if(Pags==0)
                        {
                                break;
                        }
                }

                if(Pags==0)
                {
                        break;
                }
        }
	if(Pags>0)
	{
		printf("\nEspacio insuficiente, borre algún proceso");
		sleep(1);
		EliminarProceso(id);
		id--;
		system("clear");
	}

}

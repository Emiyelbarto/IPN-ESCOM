#include<unistd.h>
void CrearProceso(int tam);
void InitSeg();//Inicializa segmentos en cero
void MostrarRam();
void EliminarProceso(int idP);
void CrearEnSwap(int tam, int Pags);
int EliminarSwap(int idP);
void Intercambiar(int Pags);
int Swapping(int idP);
void Recuperar(int idP);
int Cambiar(int tam,int idP,void *D);
void MostrarSegmentos();
void AlmacenTemporal();

struct Pagina{
	int Tam;
	int idProceso;
	int *Dir;
};
struct Segmento{
	void *DirSeg;
	struct Pagina Pag[6];
	//Tabla Dir virtual
};
int id=0;
struct Segmento Swap[4];
struct Segmento Ram[6];

void MostrarSegmentos()
{
	int validador=0;
	printf("\nRAM\n");
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(Ram[i].Pag[j].Tam>0)
				validador++;
		}
		if(validador)
		{
			Ram[i].DirSeg=&Ram[i].DirSeg;
		}
		printf("\nSegmento %d: %p",i+1,Ram[i].DirSeg);
		validador=0;
	}

	printf("\nSwap\n");
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(Swap[i].Pag[j].Tam>0)
				validador++;
		}
		if(validador)
		{
			Swap[i].DirSeg=&Swap[i].DirSeg;
		}
		printf("\nSegmento %d: %p",i+1,Swap[i].DirSeg);
		validador=0;
	}
}

void InitSeg()
{
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			Ram[i].Pag[j].Tam=0;
		}
	}
}

int ValidarRecuperacion(int idP)
{
        int Pags=0;
        for(int i=0;i<4;i++)
        {
                for(int j=0;j<6;j++)
                {
                        if(Swap[i].Pag[j].idProceso==idP)
                        {
                                Pags++;
                        }

                }
        }
        for(int i=0;i<6;i++)
        {
                for(int j=0;j<6;j++)
                {
                        if(Ram[i].Pag[j].Tam==0)
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

void Recuperar(int idP)
{
	for(int i=0;i<4;i++)
        {
                for(int j=0;j<6;j++)
                {
                        if(Swap[i].Pag[j].idProceso==idP)
                        {
                                if(Cambiar(Swap[i].Pag[j].Tam,idP,Swap[i].Pag[j].Dir))
                                {
                                        printf("\nNo hay espacio en RAM\n"); 
                                }
                                else
                                {
                                        Swap[i].Pag[j].idProceso=0;
                                        Swap[i].Pag[j].Tam=0;
                                        Swap[i].Pag[j].Dir=NULL;
                                }
                        }
                }
        }


}

int Cambiar(int tam,int idP,void *D)
{
        for(int i=0;i<6;i++)
        {
                for(int j=0;j<6;j++)
                {
                        if(Ram[i].Pag[j].Tam==0)
                        {
                                Ram[i].Pag[j].Tam=tam;
                                Ram[i].Pag[j].idProceso=idP;
                                Ram[i].Pag[j].Dir=D;
                                return 0;
                        }
                }

        }
        return 1;
}


void EliminarProceso(int idP)
{
	int E=1;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(idP==Ram[i].Pag[j].idProceso)
			{
				Ram[i].Pag[j].Tam=0;
				Ram[i].Pag[j].idProceso=0;
				Ram[i].Pag[j].Dir=0;
				E=0;
			}
		}
	}
	system("clear");
	if(E)
	{
		if(EliminarSwap(idP))
		{

		}
		printf("\nProceso no encontrado");
	}
	else
		printf("\nProceso borrado satisfactoriamente");
}

int EliminarSwap(int idP)
{
	int Pags=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(idP==Swap[i].Pag[j].idProceso)
			{
				Swap[i].Pag[j].Tam=0;
				Swap[i].Pag[j].idProceso=0;
				Swap[i].Pag[j].Dir=0;
				Pags++;
			}
		}
	}
	if(Pags>0)
	{
		return 0;
	}
}

void MostrarRam()
{
	for(int i=0;i<6;i++)
	{
		printf("\n\nSegmento %d:",i+1);
		for(int j=0;j<6;j++)
		{

			printf("\n\tPag %d:\n\t\tid:%d\t%dKB\t%p",j+1,Ram[i].Pag[j].idProceso,Ram[i].Pag[j].Tam,Ram[i].Pag[j].Dir);
		}
	}
}

void CrearProceso(int tam)
{
	int Pags=0;
	//Cada Pagina es de 4kB
	Pags=tam/4;
	if(tam%4>0)
		Pags++;
	id++;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(Ram[i].Pag[j].Tam==0)
			{
				if(Pags==1 && tam%4>0)
				{
					Ram[i].Pag[j].Tam=tam%4;
					Ram[i].Pag[j].idProceso=id;
					Ram[i].Pag[j].Dir=&Ram[i].Pag[j].Tam;
					Pags--;
				}
				else
				{
					Ram[i].Pag[j].Tam=4;
					Ram[i].Pag[j].idProceso=id;
					Ram[i].Pag[j].Dir=&Ram[i].Pag[j].Tam;
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
		Pags=tam/4;
		if(tam%4>0)
			Pags++;
		EliminarProceso(id);
		system("clear");
		CrearEnSwap(tam,Pags);
	}
	else
	{
		system("clear");
		printf("\nProceso creado con exito\n");
		printf("Se le ha asignado el id: %d\n",id);
		sleep(1);
	}
}
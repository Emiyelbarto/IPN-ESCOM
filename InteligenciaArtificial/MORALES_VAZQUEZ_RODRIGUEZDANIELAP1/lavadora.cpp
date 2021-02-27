#include<stdio.h>// printf
#include<stdbool.h>// booleanos
#include <iostream>// cadenas
#include <cstring> //funciones con cadenas
using namespace std;//default
class lavadora		//implementacion de la clase Lavadora
{
	private: 
		int t_actual=0;		//temperatura actual
		int n_awa=0	// nivel de agua a lograr segun seleccion, los niveles de agua en litros fueron asignados a nuestra conciencia pues el manual no lo especifica:(
		int n_actual=0; //nivel de agua actual, proveido por la manguera
		bool awa = false; //indica si se debe seguir agregando agua de la manguera o no
		int t_deseada=0;
		bool lavado=true;
		bool enjuague=true;
		bool e_adicional=true;
		bool rocio=false;
		bool girar=true; //indica al motor que debe girar 
		bool detener=false; //si se abre la tapa, se detiene el ciclo de lavado o enjuague.
		bool jalado=false;	//si el botón de ciclos de lavado está "halado" empieza el ciclo de lavado, de lo contrario
							//nunca lo hará 0:
		bool desawa=false:	
		bool exprime=false;
		
		int t_lavado=0;
		int t_enjuague=10;
		int n_enjuagues=1;
		string lav1="Lavado Intenso";
		string lav2="Lavado Normal";
		string lav3="Lavado Casual/Planchado Permanente";
		string lav4="Lavado Delicado";
		string lav5="Lavado a Manita";
		string lav6="Lavado Rápido";
		string car1="Carga Pequeña";
		string car2="Carga Regular";
		string car3="Carga Super Plus++";
	public:
		lavadora(void){};
		void ciclos_lavado(bool*, bool*, string*);
		int tamano_carga(string*);
		int enjugue_adicional(bool*, int*);
		int temperatura_perfecta(int*, int*);
		void lavar(bool*);
		void enjuagar(bool*, int*);
		void llenar(bool*)		//llenar la tina segun el tipo de carga 
		
};		

void lavadora::ciclos_lavado(string* t_carga, int* t_actual, bool* e_adicional, int* t_lavado)
{
	while(jalado)
	{
		while(!detener)
		{
			if(strcmp(lavado, lav1)==0)
			{
				temperatura_perfecta(t_actual, 44);
				tamano_carga(t_carga);
				n_enjuagues = enjuague_adicional(e_adicional)
				lavar(true, &t_lavado);
				enjuagar(true, &n_enjuagues);
				jalado=false;
				
			}
			else
			{
				if (strcmp(lavado, lav2)==0)
				{
					temperatura_perfecta(t_actual, 32);
					tamano_carga(t_carga);
					n_enjuagues = enjuague_adicional(e_adicional)
					lavar(true, &t_lavado);
					enjuagar(true, &n_enjuagues);
					jalado=false;
				}
				else
				{
					if (strcmp(lavado, lav3)==0)
					{
						temperatura_perfecta(t_actual, 32);
						tamano_carga(t_carga);
						n_enjuagues = enjuague_adicional(e_adicional)
						lavar(true, &t_lavado);
						enjuagar(true, &n_enjuagues);
						jalado=false;
					}
					else
					{	
						if(strcmp(lavado, lav4)==0)
						{
							temperatura_perfecta(t_actual, 32);
							tamano_carga(t_carga);
							n_enjuagues = enjuague_adicional(e_adicional)
							lavar(true, &t_lavado);
							enjuagar(true, &n_enjuagues);
							jalado=false;
						}
						else
						{
							if(strcmp(lavado, lav5)==0)
							{
								temperatura_perfecta(t_actual, 21);
								tamano_carga(t_carga);
								n_enjuagues = enjuague_adicional(e_adicional)
								lavar(true, &t_lavado);
								enjuagar(true, &n_enjuagues);
								jalado=false;
							}
							else
							{	
								if(strcmp(lavado, lav6)==0)
								{
									temperatura_perfecta(t_actual, 21);
									tamano_carga(t_carga);
									n_enjuagues = enjuague_adicional(e_adicional)
									lavar(true, &t_lavado);
									enjuagar(true, &n_enjuagues);
									jalado=false;
								}
								else
								{
									print("Por favor, seleccione un ciclo de lavado");
									jalado=false;
								}
							}
						}
					}
				}		
			}
		}
	}
};

int lavadora::tamano_carga(string* tamaño)
{
	if(strcmp(tamaño, car1)==0)
		n_awa =  5;
	else
	{
		if (strcmp(tamaño, car2)==0)
			n_awa = 7;
		else
			if (strcmp(tamaño, car3)==0)
				n_awa = 11;
	}
	return n_awa;
};

int lavadora::enjuague_adicional(bool* e_adicional, int* n_enjuagues)
{
	if(e_adicional)
		n_enjuagues++;
	return n_enjuagues;
};

int lavadora::temperatura_perfecta(int* t_actual,int* t_deseada)
{
	if(t_actual<t_deseada)
		t_actual++;
	else 
	{
		if(t_actual>t_deseada)
			t_actual--;
	}
	
	return t_actual;
};

void lavadora::lavar(bool* lavar, int* t_lavado)
{
	llenar(true);
	while(t_lavado!=0)
	{
		girar = true;
	}
	desawa = true;
	exprime = true;
	
};

void lavadora::enjuagar(bool* lavar, int* n_enjuagues)
{
	llenar(true);
	while(t_enjuague)
	{
		girar = true;
	}
	desawa = true;
	exprime = true;
	rocio = true;
	exprime = true;
};

void lavadora::llenar(int* n_awa)
{
	while(n_actual<n_awa)
	{
		awa = true;
	}
	awa = false;
};		

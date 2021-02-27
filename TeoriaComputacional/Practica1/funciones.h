//Autor: José Emiliano Pérez Garduño/Teoría Computacional/2CV3
#include <stdio.h>
int MenuPrincipal(int menu);
int TamArreglo(char *palabra);
void ImpPalabra(char *palabra, int length);
int SubMenu(int submenu, char **Lista, int NumWords);
void ImpLongitud(char *palabra);
void MostrarLista(char **Lista);
char *IgualarAux(char * aux, char * palabra, int length);
void GuardarPalabra(char **Lista, char *palabra);
void Concatenacion(char *Palabra1, char *Palabra2, char **Lista);
void Invertir(char * palabra, char **Lista);
int LongArreglo(char * palabra);
int GetNumWordsFile();
void VerificarArchivo(FILE *archivo);
void Sufijos(char *palabra);
void Prefijos(char *palabra);
void SubCadenas(char *palabra);
void SubSecuencias(char *palabraA, char *palabraB);
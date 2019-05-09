//AUTORES: OMAR APARICIO QUIRÓZ, EDUARDO DAVID RAMIREZ OSORIO, JOSÉ EMILIANO PÉREZ GARDUÑO
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int lenght(char *array){
    int i = 0;
    while(array[i] != '\0'){
        i++;
    }

    return i;
}

int main(int argc, char const *argv[]){
    printf("AUTORES: OMAR APARICIO QUIRÓZ, EDUARDO DAVID RAMIREZ OSORIO, JOSÉ EMILIANO PÉREZ GARDUÑO\n");
    FILE *fp, *auxfp;
    fp = fopen("datos.csv","r");
    auxfp = fopen("datos.csv","r");

    if(!fp){
        printf("Error leyendo archivo\n");
        return 1;
    }

    int sizeUsb, sizeLine;
    printf("Tamano del USB (Mb): ");
    scanf("%d",&sizeUsb);

    if(sizeUsb <= 0){
        printf("Tamano incorrecto!\n");
        return 1;
    }

    int lines = 0;
    size_t line_size = 1024;
    char *line = (char *) malloc(line_size);

    while(fgets(line,line_size,auxfp) != NULL){
        lines++;
    }

    int *values = malloc(sizeof(int) * lines);
    
    int *mb = malloc(sizeof(int) * lines);

    int index = 0;

    int auxIndex = index + 2;
     
    lines = 0;

    char * lineAux = malloc(sizeof(int) * 1024);

    while(fgets(line,line_size,fp) != NULL){
        while(line[index] != ',')
            index++;

        for (int i = 0; i < index; i++){
            lineAux[i] = line[i];

            if(index < 2){
                lineAux[1] = '\0';
                break;
            }
        }

        values[lines] = atoi(lineAux);       

        for (int i = 0; i < index; i++){
            lineAux[i] = 0;
        }

        while(line[auxIndex] != '\0')
            auxIndex++;

        int cc = index;

        for (int i = index; i < auxIndex; ++i){
            lineAux[i-index-1] = line[i];
            cc++;

            if (auxIndex < 2){
                lineAux[1] = 0;
            }
        }

        mb[lines] = atoi(lineAux);

        sizeLine = lenght(line);

        line[sizeLine - 1] = '\0';

        lines++;

        index = 0;
    }
   
    float *cost = malloc(sizeof(float) * lines);

    int arrayPosition = 0;

    printf("\nValores en el archivo.\n");

    while(arrayPosition != lines){
        cost[arrayPosition] = (float) values[arrayPosition] / (float) mb[arrayPosition];
        printf("\nArchivo: %d - valor: %d - mb: %d - costo: %.2f", arrayPosition,values[arrayPosition], mb[arrayPosition], cost[arrayPosition]);
        arrayPosition++;
    }
    printf("\n");

    int position;

    float largest;

    int sizeUsed = 0;

    int sizeMB = 0;
    int contValue = 0;
    int contZeros = 0;

    while(sizeUsed <= sizeUsb){
        
        largest = cost[0];
        sizeMB = mb[0];
        position = 0;

        for (int i = 1; i < lines; i++){            
            if(largest <= cost[i]){
                largest = cost[i];
                position = i;
                sizeMB = mb[i];
            }
        }

        for (int i = 0; i < lines; i++){            
            if(cost[i] == 0){
                contZeros++;
            }
        }

        if(contZeros < lines)
            contZeros = 0;   
        else
            break;

        if(sizeMB <= (sizeUsb - sizeUsed)){
            printf("\nArchivo seleccionado: %d - valor: %d - mb: %d - costo: %.2f", position, values[position], mb[position], cost[position]);
            contValue += values[position];
            cost[position] = 0;
            //printf("\n¡¡Cost updated: %d - value: %d - mb: %d - cost: %.2f", position, values[position], mb[position], cost[position]);
            sizeUsed = sizeUsed + sizeMB;
            printf("\nTamano usado: %d - Espacio disponible: %d", sizeUsed, sizeUsb - sizeUsed);
        }else
            cost[position] = 0;
        
    }

    printf("\n\nArchivos copiados!");
    printf("\nTamano usado: %d - Espacio disponible: %d", sizeUsed, sizeUsb - sizeUsed);
    printf("\nValor Total: %d", contValue);
    printf("\n");
    return 0;
}
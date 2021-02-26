#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

int numHilos = 0;
int columnas_A = 0;
int filas_A = 0;
int columnas_B = 0;
int filas_B = 0;
int **A, **B, **C;
int verificarInput(int input);
int verificarHilos(int n, int col, int row);
int verificarMatrices(int col, int row);
int **crearMatriz(int row, int col);
int **poblarMatriz(int row, int col, int **Matriz);
void imprimirMatriz(int row, int col, int **Matriz);
void *multiplication(void *argHilo);

int main(int argc, char *argv[]) {
  if (verificarInput(argc) == -1)
    return -1;
  if (verificarHilos(atoi(argv[5]), atoi(argv[1]), atoi(argv[2])) == -1)
    return -1;
  if (verificarMatrices(atoi(argv[1]), atoi(argv[4])) == -1)
    return -1;
  srand(time(0));
  numHilos = atoi(argv[5]);
  columnas_A = atoi(argv[2]);
  filas_A = atoi(argv[1]);
  columnas_B = atoi(argv[4]);
  filas_B = atoi(argv[3]);
  int rc = 0;
  A = crearMatriz(filas_A, columnas_A);
  B = crearMatriz(filas_B, columnas_B);
  C = crearMatriz(filas_A, columnas_B);
  int ***Matrices[3];
  pthread_t hilo[numHilos];
  printf("[+] - Se realizara la multiplicacion de matrices con los valores:\n");
  printf("[-] - Columnas de A: %d\n[-] - Filas de A: %d\n", columnas_A,
         filas_A);
  printf("[-] - Columnas de B: %d\n[-] - Filas de B: %d\n", columnas_B,
         filas_B);
  printf("[-] - Numero de hilos: %d\n\n", numHilos);
  printf("\n[*] - Matriz A poblada\n\n");
  A = poblarMatriz(filas_A, columnas_A, A);
  printf("\n[*] - Matriz B poblada\n\n");
  B = poblarMatriz(filas_B, columnas_B, B);
  for (int i = 0; i < numHilos; i++) {
    rc = pthread_create(&hilo[i], NULL, multiplication, (void *) i);
    if (rc != 0) {
      printf("[ERROR] - Error al crear el hilo.\nCodigo de error: %d\n", rc);
      exit(-1);
    }
  }
  for (int i = 0; i < numHilos; i++) {
    pthread_join(hilo[i], NULL);
  }
  printf("Resultado: \n");
  imprimirMatriz(filas_A, columnas_B, C);
  free(A);
  free(B);
  free(C);
}

int verificarInput(int input) {
  if (input < 5) {
    printf("[ERROR] - Error al introducir datos\n");
    printf("[ERROR] - Numero de parametros incorrecto\n");
    printf("Uso correcto: ./programa <colA> <filA> <colB> <filB> <numHilos>\n");
    return -1;
  }
  return 0;
}

int verificarHilos(int n, int col, int row) {
  if (n > col || n > row) {
    printf("[ERROR] - El numero de hilos no puede ser mayor que el numero de "
           "filas y columnas de la matriz A\n");
    printf("[ERROR] - Valor introducido: %d\n", n);
    return -1;
  }
  return 0;
}

int verificarMatrices(int col, int row) {
  if (col != row) {
    printf("[ERROR] - La multiplicacion de matrices no puede llevarse a cabo "
           "con esos valores.\n");
    printf("[ERROR] - Valores introducidos: columnas de A = %d, filas de B = "
           "%d.\n",
           col, row);
    return -1;
  }
  return 0;
}

int **crearMatriz(int row, int col) {
  int **Matriz = (int **)malloc(row * sizeof(int *));
  for (int i = 0; i < row; i++) {
    Matriz[i] = (int *)malloc(col * sizeof(int));
  }
  return Matriz;
}

int **poblarMatriz(int row, int col, int **Matriz) {
  int max_rand = 5;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      Matriz[i][j] = rand() % max_rand + 1;
    }
  }
  imprimirMatriz(row, col, Matriz);
  return Matriz;
}

void imprimirMatriz(int row, int col, int **Matriz) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%d\t", Matriz[i][j]);
      if (j == col - 1) {
        printf("\n");
      }
    }
  }
  printf("\n");
}

void *multiplication(void *argHilo) {
  int id = (int) argHilo;
  printf("id: %d\n\n", id);
  int sum = 0;
  for (int a = 0; a < columnas_B; a++) {
    for (int i = 0; i < filas_A; i++) {
      sum = 0;
      for (int j = 0; j < columnas_A; j++) {
        sum += A[i][j] * B[j][a];
      }
      C[i][a] = sum;
    }
  }
  pthread_exit(C);
}
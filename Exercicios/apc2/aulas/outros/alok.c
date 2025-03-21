#include <stdio.h>
#include <stdlib.h>

struct pessoa {
  char nome[101];
  unsigned idade;
  float salario;
};

void mallocs() { /*questao malloc*/
  puts("malloc:");
  int *num = malloc(sizeof(int)); /*item a*/
  printf("num: %p\n", num); free(num);

  char *str = malloc(101 * sizeof(char)); /*item b*/
  printf("str: %p\n", str); free(str);

  char *floats = malloc(15 * sizeof(float)); /*item c*/
  printf("floats: %p\n", floats); free(floats);

  struct pessoa *pessoas = malloc(20 * sizeof(struct pessoa)); /*item d*/
  printf("pessoas: %p\n", pessoas); free(pessoas);

  int *matriz = malloc(5*5 * sizeof(int)); /*item e*/
  printf("matriz: %p\n\n", matriz); free(matriz);
}

void callocs() { /*questao calloc*/
  puts("calloc:");
  int *num = calloc(1, sizeof(int)); /*item a*/
  printf("num: %p\n", num); free(num);

  char *str = calloc(101, sizeof(char)); /*item b*/
  printf("str: %p\n", str); free(str);

  struct pessoa *pessoas = calloc(20, sizeof(struct pessoa)); /*item c*/
  printf("pessoas: %p\n", pessoas); free(pessoas);

  int *matriz = calloc(5*5, sizeof(int)); /*item d*/
  printf("matriz: %p\n\n", matriz); free(matriz);
}

void reallocs() { /*questao realloc*/
  puts("realloc:");
  char *str = calloc(101, sizeof(char)); /*item a*/
  str = realloc(str, sizeof(str) + 50 * sizeof(char));
  printf("str: %p\n", str); free(str);

  struct pessoa *pessoas = calloc(20, sizeof(struct pessoa)); /*item b*/
  pessoas = realloc(pessoas, sizeof(pessoas) + 20 * sizeof(struct pessoa));
  printf("pessoas: %p\n\n", pessoas); free(pessoas);
}

/*exercicio*/
int *build_int_array(unsigned int size) {
  return (int *)calloc(size, sizeof(int));
}

float *medias_das_notas(int m, int n, float matriz[m][n]) {
  float *medias = calloc(m, sizeof(float));
  for (int i = 0; i < m; i++) {
    int media = 0;
    for (int j = 0; j < n; j++)
      media += matriz[i][j];
    media /= n;
    *(medias + i) = media;
  }
  return medias;
}

char *repete_string(char str[], int n) {
  int len = 0;
  for (int i = 0; *(str + i) != '\0'; i++) len++;
  char *repeticoes = calloc(len * n + 1, sizeof(char));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < len; j++)
      *(repeticoes + (i * len) + j) = str[j];
  return repeticoes;
}

int main() {
  mallocs();
  callocs();
  reallocs();

  int *arr = build_int_array(3);
  printf("arr em %p de tamanho %lu\n", arr, sizeof(arr)); free(arr);

  float notas[2][3] = {{1, 2, 3}, {4, 5, 6}};
  float *medias = medias_das_notas(2, 3, notas);
  printf("medias: aluno 1: %.2f; aluno 2: %.2f\n", medias[0], medias[1]);

  puts(repete_string("aopa fi", 4));

  return 0;
}
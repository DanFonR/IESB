// frase 30 char, matriz 6x5, print coluna a coluna
#include <stdio.h>
int main(){
  char frase[30];
  printf("entre com frase: ");
  int ok = scanf("%[^\n]30s", frase);
  char matriz[6][5];
  int k = 0;
  for (int i = 0; i < 6; i++){
    for (int j = 0; j < 5; j++){
      matriz[i][j] = frase[k++];
    }
  }
  for (int j = 0; j < 5; j++){
    for (int i = 0; i < 6; i++){
      printf("%c", matriz[i][j]);
    }
  }
  printf("\n");
  return 0;
}
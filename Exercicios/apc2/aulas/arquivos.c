#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fptr = fopen("teste.txt", "w");
  
  if (!fptr) {
    fprintf(stderr, "Erro ao abrir o arquivo\n");
    exit(EXIT_FAILURE);
  }
  
  printf("ola (normal)\n");
  fprintf(stdout, "ola (stdout)\n");
  fprintf(stderr, "ola (stderr)\n");
  fprintf(fptr, "ola (teste.txt)\n");
  
  FILE *temp = stdout;
  stdout = fptr;
  
  printf("printf, mas em teste.txt\n");
  fclose(fptr);

  stdout = temp;
  
  printf("retorno para normal\n");
  return 0;
}
#include <stdio.h>

int var_global = 7; /*modificavel em escopo de funcao*/

void linha(int n, char c) {
  for (int i = 0; i < n; i++)
    putchar(c);
  puts("");
}

void alterarX(int *x, int y) {
  /*C so tem passagem por valor; no caso, valor do ponteiro*/
  *x = y;
  // em C++, func(int &x, int y) {x = y} passa x por referencia e o altera
}

int main(int argc, char *argv[]) {
  linha(10, '*');
  printf("antes de modificar var_global: %d\n", var_global);
  var_global++;
  printf("depois de modificar var_global: %d\n", var_global);
  
  {
    int var_global = 19;
    printf("dentro de escopo local: %d\n", var_global);
  }
  
  printf("fora de escopo local: %d\n", var_global);
  linha(10, '*');
  switch (argc) {
    case 2:
    case 3:
    case 4:
      for (int var_global = 0; var_global < argc; var_global++)
        printf("argumento: %s; dentro do loop: %d\n", argv[var_global], var_global);
      printf("fora do loop: %d\n", var_global);
    default:
      break;
  }
  return 0;
}
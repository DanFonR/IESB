#include <stdio.h>
int main() {
  char *imutavel = "imutavel";
  printf("%s\n", imutavel);
  char mutavel[] = "mutavel";
  printf("antes: %s; ", mutavel);
  mutavel[1] = 'U';
  printf("depois: %s\n", mutavel);
  char mutavel2[8] = "mutavel";
  printf("%s\n", mutavel2);
  char *string = "Hello World";
  int i = 0;
  while (string[++i] != '\0');
  printf("string \"%s\" com comprimento %d\n", string, i);
  return 0;
}
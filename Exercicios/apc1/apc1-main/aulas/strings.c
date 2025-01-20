#include <stdio.h>
#include <string.h>
int main(){
  char str[50] = "uma string";
  memset(str, 'a', 10);
  printf("memset: %s\n", str);
  strcpy(str, "uma string");
  printf("%s\n", str);
  strcat(str, " outra string");
  printf("concat: %s\n", str);
  printf("iguais? %d\n", strcmp(str, "uma string"));
  printf("tamanho: %ld\n", strlen(str));
  return 0;
}
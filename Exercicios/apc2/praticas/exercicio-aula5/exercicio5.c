#include <stdio.h>

int comprimento(char *string) {
  char *ptr = string;
  while (*(++ptr) != '\0');
  return ptr - string;
}

char *ultimavogal(char *string) {
  char *ptr = string + comprimento(string) - 1;
  while (ptr != string) {
    char carac = *(ptr--);
    if ('a' <= carac && carac <= 'z')
      carac -= 32;
    switch (carac) {
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        return ++ptr;
      default:
        continue;
    }
  }
  return NULL;
}

char *inversor(char string[]) {
  int len = comprimento(string);
  char *p1 = string;
  char *p2 = string + len - 1;
  for (int i = 0; i < (len / 2); i++) {
    char temp = *p1;
    *(p1++) = *p2;
    *(p2--) = temp;
  }
  return string;
}

char *concatenar(char destino[], char *origem) {
  char *ptr = destino + comprimento(destino);
  while ((*(ptr++) = *(origem++)) != '\0');
  return (ptr = destino);
}

char *copiar(char destino[], char *origem) {
  char *ptr = destino;
  for (int i = 0; (*(ptr + i) = *(origem++)) != '\0'; i++);
  return ptr;
}

char *concatreverso(char destino[], char *origem) {
  int len1 = comprimento(destino), len2 = comprimento(origem);
  char *ptr = destino + len2;
  for (int i = 0; i < len1; i++) 
    *(ptr + i) = *(destino + i);
  for (int i = 0; i < len2; i++)
    *(destino + i) = *(origem + i);
  return destino;
}

int main() {
  char base[12] = "Hello World";
  // Algoritmo 1:
  puts("Algoritmo 1:");
  printf("a string \"%s\" tem comprimento de %d caracteres.\n\n", base, comprimento(base));
  
  // Algoritmo 2:
  puts("Algoritmo 2:");
  char *vogal = ultimavogal(base);
  if (vogal)
    printf("a ultima vogal da string \"%s\" foi '%c' no endereco %p.\n\n", base, *vogal, vogal);
  else
    printf("nao ha vogal; valor de retorno: %p.\n\n", vogal);
  
  // Algoritmo 3:
  puts("Algoritmo 3:");
  printf("a string \"%s\" invertida fica ", base);
  inversor(base);
  printf("\"%s\".\n\n", base);
  
  // Algoritmo 4:
  puts("Algoritmo 4:");
  char hello[12] = "Hello";
  char world[6] = "World";
  printf("a string \"%s\" concatenada com a string \"%s\" fica ", hello, world);
  concatenar(hello, world);
  printf("\"%s\".\n\n", hello);

  // Algoritmo 5:
  puts("Algoritmo 5:");
  char destino1[8];
  char origem1[] = "bom dia";
  copiar(destino1, origem1);
  printf("string destino1 agora fala \"%s\".\n\n", destino1);

  // Algoritmo 6:
  puts("Algoritmo 6:");
  char destino2[100] = "Autonoma";
  char origem2[100] = "Universidade";
  concatreverso(destino2, origem2);
  printf("string destino2 com concatenacao reversa fala \"%s\".\n", destino2);
  return 0;
}
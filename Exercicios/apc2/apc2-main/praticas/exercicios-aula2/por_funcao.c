#include <stdio.h>

int main() {
  int rgba = 0X010203FF;
  unsigned char *c = (unsigned char *) &rgba;
  
  char *canais[] = {"Alfa", "B", "G", "R"};
  for (int i = 3; i >= 0; i--)
    printf("%s: %02X (%d em decimal)\n", canais[i], *(c + i), *(c + i));
  return 0;
}
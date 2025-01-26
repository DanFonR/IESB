#include <stdio.h>
int main(){
  int v[10] = {3, 5, 6, 2, 8, 9, 1, 5, 0, 7};
  int lim = 10;
  puts("Valores");
  for (int i = 0; i < lim; i++)
    printf("v[%d] = %d, *(v + 0) = %d\n", i, v[i], *(v + i));
  puts("Endereços");
  for (int i = 0; i < lim; i++)
    printf("&v[%d] = %p, v + %d = %p\n", i, &v[i], i, v + i);
  return 0;
}
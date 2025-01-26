#include <stdio.h>
long long fatorial(unsigned int n) {
  return (n >= 2)? n * fatorial(n - 1) : 1;
}

int p(unsigned int n) {
  if (n < 0)
    return -1;
  return (n == 0)? 0 : p(n - 1) + 1;
}

int produtorio(int n) {
  return (n == 1 || n == 0)? n : n * produtorio(n - 1);
}

int main() {
  int i = 0;
  long long fac;
  while ((fac = fatorial(i)) > 0)
    printf("%d! == %lld\n", i++, fatorial(i));
  printf("%d! is too big to be computed by recursion\n", i);
  printf("\np(%d) makes %d\n", 3, p(3));
  return 0;
}
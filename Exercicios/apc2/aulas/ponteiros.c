#include <stdio.h>
int main() {
  int x = 5;
  float pi = 3.1415926;
  int *ptr_x = &x;
  float *ptr_pi = &pi;
  printf("&x: %p (x: %d)\n", &x, x);
  printf("ptr_x: %p (*ptr_x: %d)\n", ptr_x, *ptr_x);
  printf("&pi: %p (pi: %f)\n", &pi, pi);
  printf("ptr_pi: %p (*ptr_pi: %f)\n", ptr_pi, *ptr_pi);
  printf("a pilha cresce para %s\n", ((float *) ptr_x > ptr_pi)? "baixo" : "cima");
  return 0;
}
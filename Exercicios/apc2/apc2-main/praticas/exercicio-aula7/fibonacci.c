#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fibs[BUFSIZ] = {0, 1};
int i = 2;

int fib_iter(int n) {
  if (n < 1 || n > BUFSIZ)
    return -1;
  while (n > i) {
    fibs[i] = fibs[i - 1] + fibs[i - 2];
    i++;
  }
  return fibs[n - 1];
}

int fib_rec1(int n) {
  if (n < 1)
    return -1;
  return (n == 1 || n == 2)? n - 1 : fib_rec1(n - 1) + fib_rec1(n - 2);
}

int fib_rec2(int n) {
  if (n == 0 || n == 1) return n;
  if (fibs[n]) return fibs[n];
  if (n > 1) {
    if (!fibs[n - 1]) fibs[n - 1] = fib_rec2(n - 1);
    if (!fibs[n - 2]) fibs[n - 2] = fib_rec2(n - 2);
    return fibs[n - 1] + fibs[n - 2];
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3)
    return 1;
  
  int n = atoi(argv[2]);
  
  if (!strcmp(argv[1], "rec1"))
    printf("%d\n", fib_rec1(n));
  else if (!strcmp(argv[1], "rec2"))
    printf("%d\n", fib_rec2(n));
  else if (!strcmp(argv[1], "iter"))
    printf("%d\n", fib_iter(n));
  
  return 0;
}
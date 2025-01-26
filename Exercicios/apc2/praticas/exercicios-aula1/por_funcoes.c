#include <stdio.h>

void exercicio1(void) {
  int i = 5;
  int *p;
  p = &i;
  printf("&p: %p\n", &p);
  printf("p (&i - endereço de i): %p\n", p);
  printf("*p (i - valor de i): %d\n", *p);

  *p = 7; /*atribuição direta*/
  printf("*p (i - valor de i): %d\n", *p);

  printf("valor para *p: ");
  (void) scanf("%d", p); /*usando scanf*/
  printf("*p (i - valor de i): %d\n", *p);
}


void exercicio2(void) {
  int numero;

  int *ptr = &numero;
  *ptr = 5;
  printf("valor de numero: %d\n", numero);
}

void exercicio3(void) {
  int n1 = 3, n2 = 5;

  printf("n1: %d, n2: %d\n", n1, n2);
  int temp;
  int *n1_ptr = &n1, *n2_ptr = &n2, *temp_ptr = &temp;
  *temp_ptr = *n1_ptr;
  *n1_ptr = *n2_ptr;
  *n2_ptr = *temp_ptr;

  printf("n1: %d, n2: %d\n", n1, n2);
}

int main() {
  printf("exercicio 1\n");
  exercicio1();

  printf("\nexercicio 2\n");
  exercicio2();

  printf("\nexercicio 3\n");
  exercicio3();
  
  return 0;
}
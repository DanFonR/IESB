# Dannyel Fontenele Ribeiro – 2322130061

- 1 

Considerando pilha com direção de crescimento crescente e inteiro de 2 bytes:
  
  &i = 0x100, ocupa os endereços 0x100 e 0x101
  
  &j = 0x102, ocupa os endereços 0x102 e 0x103
  
  &k = 0x104, ocupa os endereços 0x104 e 0x105
  
  &l = 0x106, ocupa os endereços 0x106 e 0x107

---
---

- 1
```
#include <stdio.h>

int main(void) {
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
  return 0;
}
```

---

- 2
```
#include <stdio.h>

int main(void) {
  int numero;

  int *ptr = &numero;
  *ptr = 5;
  printf("valor de numero: %d\n", numero);
  return 0;
}
```
---

- 3
```
#include <stdio.h>

int main(void) {
  int n1 = 3, n2 = 5;

  printf("n1: %d, n2: %d\n", n1, n2);
  int temp;
  int *n1_ptr = &n1, *n2_ptr = &n2, *temp_ptr = &temp;
  *temp_ptr = *n1_ptr;
  *n1_ptr = *n2_ptr;
  *n2_ptr = *temp_ptr;

  printf("n1: %d, n2: %d\n", n1, n2);
  return 0;
}
```
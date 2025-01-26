#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int x, y, z;
  int local = 5;
  int *p_local = NULL;
  int *p_mem_din = NULL;
  /* Variáveis na stack são organizadas de forma, contígua, sequencial */
  
  printf("enderecos: x (size %lu) em %p, y (size %lu) em %p, "
         "z (size %lu) em %p\n", sizeof(x), &x, sizeof(y), &y, sizeof(z), &z);

  p_local = &local;
  p_mem_din = malloc(sizeof(int)); /* alocação de 1 inteiro */

  *p_local = 10;
  *p_mem_din = 7;

  printf("*p_local: %d (%p)\n", *p_local, p_local);
  printf("*p_mem_din: %d (%p)\n", *p_mem_din, p_mem_din);

  free(p_mem_din); /* liberação de memória */
  printf("\npos-liberacao:\n*p_mem_din: %d (%p)\n", *p_mem_din, p_mem_din);
  printf("p_mem_din[0]: %d (%p)\n", p_mem_din[0], &p_mem_din[0]);

  int *vet_din = malloc(sizeof(int)*50);
  vet_din[0] = 3;
  vet_din[1] = 9;
  printf("*vet_din: %d (%p)\n", *vet_din, vet_din);
  printf("vet_din[0]: %d (%p)\n", vet_din[0], &vet_din[0]);

  printf("*(vet_din+1): %d (%p)\n", *(vet_din+1), vet_din+1);
  printf("vet_din[0]: %d (%p)\n", vet_din[1], &vet_din[1]);

  return 0;
}

int main1() {
  int stack1 = 0;
  int *stack2 = NULL;
  int *test = calloc(4, sizeof(int));

  for (int i = 0; i < 4; i++)
    *(test + i) = i * 2;
  
  printf("values of calloced test: {");
  
  for (int i = 0; i < 4; i++)
    printf("%d, ", *(test + i));
  
  printf("\b\b} @ starting addr %p\nnotice addr difference "
         "from stack1 (%d @ addr %p) and stack2 (%p @ addr %p)\n",
         test, stack1, &stack1, stack2, &stack2);
  free(test);

  test = malloc(4);
  *test = 44;
  
  printf("freed then malloced test (%d @ addr %p)\n"
         "val 4 bytes after: %d @ addr %p\n",
         *test, test, test[1], &test[1]);
  
  return 0;
}

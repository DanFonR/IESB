#include <stdio.h>
#define printv(vec, len) for (int i = 0; i < 6; i++) \
                           printf("%d\n", vet[i]);

void zerarvetor(int arg[], size_t len); /* pode ser *arg: *arg ==  arg[]*/
/* prototipo de funcao */
void somarvetor(int arg[], size_t len) {
  int soma = 0;
  for (int i = 0; i < len; i++) {
    soma += arg[i];
    printf("\nsoma: %d", soma);
    if (soma > 10) {
      puts("\nexcedeu 10!");
      return;
    }
  }
}
int main(int argc, char *argv[], char *envp[]) {
  /* argc = argument count
     argv = argument vector 
     envp = environment parameters
     backslash para escapar espacos */
  int vet[6] = {6, 7, 9, 2, 4, 1};
  puts("antes:");
  printv(vet, 6);
  somarvetor(vet, 6);
  
  zerarvetor(vet, 6);
  
  puts("\ndepois:");
  printv(vet, 6);
  /*for (int i = 0; i < argc; i++)
    printf("arg %d: %s\n", i, argv[i]);
  while (*envp != NULL)
    printf("variavel de ambiente: %s\n", *(envp++));*/
  return 0;
}

void zerarvetor(int arg[], size_t len) { /* pode ser *arg: *arg ==  arg[]*/
  while (len-- > 0) arg[len] = 0;
}
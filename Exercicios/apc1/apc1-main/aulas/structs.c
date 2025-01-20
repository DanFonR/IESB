#include <stdio.h>
#include <string.h>
int main(){
  struct contato_t {
  char nome[61];
  long int telefone;
  };
  struct contato_t contato;
  strcpy(contato.nome, "JOSE");
  contato.telefone = 40028922;
  printf("%s - %ld\n", contato.nome, contato.telefone);
  struct contato_t outro;
  outro = contato;
  printf("%s - %ld\n", outro.nome, outro.telefone);
  strcpy(contato.nome, "MARIA");
  contato.telefone = 35521719;
  printf("%s - %ld\n", contato.nome, contato.telefone);
  printf("%s - %ld\n", outro.nome, outro.telefone);
  struct contato_t contatos[10];
  for (int i = 0; i < 5; i++){
    printf("nome do %do contato: ", i+1);
    int ok = scanf("%[^\n]s", contatos[i].nome);
    printf("telefone do %do contato: ", i+1);
    ok = scanf("%ld", &contatos[i].telefone);
    getchar();
  }
  printf("LISTA DE CONTATOS\n");
  for (int i = 0; i < 5; i++){
    printf("%-10s - (%11ld)\n", contatos[i].nome, contatos[i].telefone);
  }
  return 0;
}
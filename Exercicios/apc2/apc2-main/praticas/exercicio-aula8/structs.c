#include <stdio.h>

struct data {
  unsigned int dia;
  unsigned int mes;
  unsigned int ano;
};

struct pessoa {
  char nome[100];
  char genero;
  struct data data_nasc;
};

/* preencher pessoa */
void preencher_pessoa(struct pessoa *pessoa) {
  printf("nome completo: ");
  (void) scanf("%99[^\n]", pessoa->nome);
  getchar();
  printf("genero: ");
  pessoa->genero = getchar();
  printf("data de nascimento (formato DD/MM/YYYY): ");
  (void) scanf("%2u/%2u/%4u", &pessoa->data_nasc.dia, &pessoa->data_nasc.mes,
  &pessoa->data_nasc.ano);
}

/* exibir pessoa */
void exibir_pessoa(const struct pessoa pessoa) {
  printf("Nome: %s; Genero: %c; Data de nascimento: %02u/%02u/%04u\n",
  pessoa.nome, pessoa.genero, pessoa.data_nasc.dia, pessoa.data_nasc.mes,
  pessoa.data_nasc.ano);
}

int main(void) {
  struct pessoa monterlei;

  preencher_pessoa(&monterlei);
  exibir_pessoa(monterlei);

  return 0;
}

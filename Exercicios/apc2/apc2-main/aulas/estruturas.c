#include <stdio.h>

// Estruturação de dados
// declarar 10 inteiros
/*int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10; // não estruturado
int numeros[10];*/ // estruturado

// Declaração de uma pessoa
// não estruturado
/*char nome[100];
char genero;
unsigned int dia, mes, ano;*/

// estruturado
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

// preencher pessoa
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

// exibir pessoa
void exibir_pessoa(const struct pessoa pessoa) {
  printf("Nome: %s; Genero: %c; Data de nascimento: %02u/%02u/%04u\n",
  pessoa.nome, pessoa.genero, pessoa.data_nasc.dia, pessoa.data_nasc.mes,
    pessoa.data_nasc.ano);
}

int main(void) {
  struct pessoa monterlei;
  preencher_pessoa(&monterlei);
  exibir_pessoa(monterlei);

  struct data data, *pdata;
  // acessar propriedades de uma estrutura sem ponteiro
  data.dia = 15;
  data.mes = 6;
  data.ano = 2024;
  printf("data: %02d/%02d/%02d\n", data.dia, data.mes, data.ano);
  // acessar propriedades de uma estrutura com ponteiro
  pdata = &data;
  printf("dia: %d\n", pdata->dia);
  printf("dia: %d\n", (*pdata).dia);
  pdata->dia = 20;
  pdata->mes = 04;
  pdata->ano = 2003;
  printf("data: %02d/%02d/%02d\n", data.dia, data.mes, data.ano);

  return 0;
}
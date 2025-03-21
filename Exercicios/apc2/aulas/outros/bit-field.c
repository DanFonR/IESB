#include <stdio.h>
enum {M, F};

typedef struct {
 char *nome;
 int genero : 1;

 struct { /*bit-field*/
  unsigned dia : 5; /*2^5 = 32; 0...31*/
  unsigned mes : 4; /*2^4 = 16; 0...15*/
  unsigned ano : 12; /*2^12 = 4096; 0...4095*/
 } nascimento;

 struct {
  char *pais;
  char *estado;
  char *cidade;
  char *logradouro;
  char *codigo_postal;
 } endereco;

} pessoa_t;

int main() {
 pessoa_t jean = {
  .nome = "jean fontenelle",
  .genero = M,
  .nascimento = {
   .dia = 12,
   .mes = 4,
   .ano = 1995
  },
  .endereco = {
   .pais = "franca",
   .estado = "aveyron",
   .cidade = "millau",
   .logradouro = "21 boulevard sadi carnot",
   .codigo_postal = "12100"
  }
 };

 printf("o campo nascimento de pessoa_t ocupa %dB\n",
       sizeof(jean.nascimento));
 puts("soma dos bits: 21; diferenca causada por padding\n");
 printf("sem bit-field: %dB\n",
       sizeof(struct {int dia; int mes; int ano}));
 return 0;
}
#include <stdio.h>
int main() {
  enum meses {jan, fev, mar, abr, mai, jun, jul, ago, set, out, nov, dez} mes;
  char full_meses[12][11] = {"janeiro", "fevereiro", "março", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};
  int mes_ent = 0;
  printf("entre com o mês (1 a 12): ");
  int ok = scanf("%d", &mes_ent);
  switch (mes_ent-1){
    case jan:
    case fev:
    case mar:
    case abr:
    case mai:
    case jun:
    case jul:
    case ago:
    case set:
    case out:
    case nov:
    case dez: printf("O mês é %s\n", full_meses[mes_ent-1]); break;
    default: printf("Mês inválido\n");
  }
  return 0;
}
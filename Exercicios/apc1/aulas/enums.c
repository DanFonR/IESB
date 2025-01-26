#include <stdio.h>
int main(){
  enum dias {dom=1, seg, ter, qua, qui, sex, sab} dia;
  printf("Entre com o dia da semana (1 a 7): ");
  int ok = scanf("%d", &dia);
  switch (dia) {
    case seg:
    case ter:
    case qua:
    case qui:
    case sex: printf("Dia útil\n"); break;
    case sab:
    case dom: printf("Dia inútil\n"); break;
    default: printf("vtnc\n");
  }
  return 0;
}
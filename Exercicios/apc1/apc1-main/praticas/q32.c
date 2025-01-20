#include <stdio.h>
int main(){
  float total_nota = 0;
  float total_prod[10];
  for (int i = 0; i < 10; i++){
    int qtd = 0;
    float preco = 0;
    printf("Insira a quantidade e o valor do %dº produto: ", i+1);
    int test = scanf("%d %f", &qtd, &preco);
    total_prod[i] = qtd * preco;
    total_nota += total_prod[i];
  }
  for (int j = 0; j < 10; j++){
    printf("Total do %dº produto: %.2f\n", j+1, total_prod[j]);
  }
  printf("Valor total: %.2f\n", total_nota);
  return 0;
}
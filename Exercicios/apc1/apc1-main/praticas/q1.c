#include <stdio.h>
int main(){
  int nums[10];
  for (int i = 0; i < 10; i++){
    printf("Digite o %do número: ", i+1);
    int test = scanf("%d", &nums[i]);
  }
  printf("digite um numero para encontrar na matriz: ");
  int achar = 0;
  int test = scanf("%d", &achar);
  int success = 0;
  for (int i = 0; i < 10; i++){
    if (nums[i] == achar){
      printf("O número %d está na posição %d\n", achar, i);
      success = 1;
      break;
    }
  }
  if (!success){
    printf("O número %d não está na matriz.\n", achar);
  }
  return 0;
}
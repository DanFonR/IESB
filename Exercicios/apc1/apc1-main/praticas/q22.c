#include <stdio.h>
int main(){
  float notas[10];
  for (int i = 0; i < 10; i++){
    int teste = scanf("%f", &notas[i]);
  }
  float media = 0;
  for (int i = 0; i < 10; i++){
    media += notas[i];
  }
  media /= 10.0f;
  int acima_media = 0;
  for (int i = 0; i < 10; i++){
    if (notas[i] > media){
      acima_media++;
    }
  }
  printf("Há %d alunos acima da média (média: %.2f).\n", acima_media, media);

  return 0;
}
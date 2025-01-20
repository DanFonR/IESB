#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
  char pronomes[6][5] = {"EU", "TU", "ELE", "NOS", "VOS", "ELES"};
  char conjugacoes[6][5] = {"O", "AS", "A", "AMOS", "AIS", "AM"};
  char verbo[21];
  printf("entre com verbo terminado em ar: ");
  int ok = scanf("%s", verbo);
  for (int i = 0; i < strlen(verbo); i++){
    verbo[i] = toupper(verbo[i]);
  }
  int last_pos = strlen(verbo) - 1;
  if (verbo[last_pos] == 'R' && verbo[last_pos-1] == 'A') {
    verbo[last_pos] = '\0';
    verbo[last_pos-1] = '\0';
    for (int i = 0; i < 6; i++){
      char temp[21];
      strcpy(temp, verbo);
      strcat(temp, conjugacoes[i]);
      printf("%s %s\n", pronomes[i], temp);
    }
  }
  else {
    printf("o verbo %s não termina em AR\n", verbo);
  }
  return 0;
}
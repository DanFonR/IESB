#include <stdio.h>

int main() {
  int n = 0;
  char buffin[100] = "85 7 9 15 30";
  char buffout[100];
  int pos = 0;
  
  FILE *output = fopen("out.txt", "w");
  
  if (!output) {
    fprintf(stderr, "\aerro ao abrir o arquivo\n");
    return 1;
  }
  
  while (sscanf(buffin + pos, "%d", &n) != EOF) {
    pos += sprintf(buffout, "inteiro %d\n", n) - 9;
    if (buffin[pos] == ' ') pos++;
    fputs(buffout, output);
    fputs(buffout, stdout);
  }

  
  /*FILE *fptr = fopen("out.txt", "w");*/
}
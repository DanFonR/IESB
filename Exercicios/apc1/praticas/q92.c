#include <stdio.h>
int main() {
  struct aluno_t {
    int matricula;
    char email[61];
  } alunos[10];
  for (int i = 0; i < 10; i++) {
    printf("Aluno %i\nEntre com a matrícula: ", i+1);
    int ok = scanf("%i", &alunos[i].matricula);
    printf("Entre com o email: ");
    ok = scanf("%s", alunos[i].email);
    getchar();
  }
  printf("Entre com matrícula a ser encontrada: ");
  int matricula = 0;
  int ok = scanf("%d", &matricula);
  for (int i = 0; i < 10; i++) {
    if (matricula == alunos[i].matricula) {
      printf("O email do aluno é %s\n", alunos[i].email);
      break;
    }
    else if (i == 9) {
      printf("Aluno não encontrado\n");
    }
  }
  return 0;
}
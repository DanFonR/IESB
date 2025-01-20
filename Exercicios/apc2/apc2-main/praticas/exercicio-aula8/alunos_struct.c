#include <stdio.h>
#define len(arr) sizeof(arr) / sizeof(arr[0])

typedef struct aluno Aluno;

struct aluno {
  char nome[50];
  char genero;
  float notas[3];
  int aprovado : 1;
};

Aluno alunos[] = {
  {"Maria", 'F', {7.0, 3.0, 9.0}},
  {"Joao", 'M', {5.0, 6.0, 2.0}},
  {"Ana", 'F', {8.0, 9.0, 10.0}},
  {"Pedro", 'M', {6.0, 1.0, 8.0}},
  {"Carla", 'F', {9.0, 10.0, 10.0}},
  {"Paulo", 'M', {7.0, 8.0, 9.0}},
  {"Mariana", 'F', {5.0, 1.0, 7.0}},
  {"Marcos", 'M', {8.0, 9.0, 10.0}},
  {"Julia", 'F', {6.0, 7.0, 0.0}},
  {"Lucas", 'M', {9.0, 10.0, 10.0}},
};

float media(int n, float arr[n]) {
  float res = 0;

  for (int i = 0; i < n; i++)
    res += arr[i];

  return res / n;
}

void listarAlunos(int n, Aluno alunos[n]) {
  for (int i = 0; i < n; i++) {
    printf("Aluno(a): %s; Genero: %c; Notas: ",
      alunos[i].nome, alunos[i].genero);
    printf("1a: %.1f, 2a: %.1f, 3a: %.1f; Media: %.2f\n",
      alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2],
      media(len(alunos[i].notas), alunos[i].notas));
  }
}

void listarPorGenero(int n, Aluno alunos[n], char genero) {
  if (!(genero == 'M' || genero == 'F')) return;

  for (int i = 0; i < n; i++) {
    if (alunos[i].genero != genero) continue;
    printf("Aluno(a): %s; Genero: %c; Notas: ",
      alunos[i].nome, alunos[i].genero);
    printf("1a: %.1f, 2a: %.1f, 3a: %.1f; Media: %.2f\n",
      alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2],
      media(len(alunos[i].notas), alunos[i].notas));
  }
}

void exibirAlunosAprovados(int n, Aluno alunos[n]) {
  for (int i = 0; i < n; i++) {
    float avg = media(len(alunos[i].notas), alunos[i].notas);

    if (avg < 5) continue;
    
    printf("Aluno(a): %s; Genero: %c; Notas: ",
      alunos[i].nome, alunos[i].genero);
    printf("1a: %.1f, 2a: %.1f, 3a: %.1f; Media: %.2f\n",
      alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2], avg);
  }
}

Aluno melhorAluno(int n, Aluno alunos[n]) {
  float max = 0;

  for (int i = 0; i < n; i++) {
    float avg = media(len(alunos[i].notas), alunos[i].notas);

    if (avg > max) max = avg;
  }

  for (int i = 0; i < n; i++) {
    if (media(len(alunos[i].notas), alunos[i].notas) == max)
      return alunos[i];
  }
}

void avaliarAluno(Aluno *aluno) {
  if (media(len(aluno->notas), aluno->notas) >= 5) aluno->aprovado = 1;
  else aluno->aprovado = 0;
}

int main() {
  for (int i = 0; i < len(alunos); i++)
    avaliarAluno(&alunos[i]);

  puts("Lista de Alunos:");
  listarAlunos(10, alunos);
  puts("");

  puts("Lista por Genero:");
  puts("Masculino:");
  listarPorGenero(10, alunos, 'M');
  puts("");

  puts("Feminino:");
  listarPorGenero(10, alunos, 'F');
  puts("");

  puts("Alunos Aprovados:");
  exibirAlunosAprovados(10, alunos);

  Aluno melhor = melhorAluno(10, alunos);

  puts("\nMelhor Aluno:");
  printf("Aluno(a): %s; Genero: %c; Notas: ",
    melhor.nome, melhor.genero);
  printf("1a: %.1f, 2a: %.1f, 3a: %.1f; Media: %.2f\n",
    melhor.notas[0], melhor.notas[1], melhor.notas[2], media(3, melhor.notas));
  return 0;
}
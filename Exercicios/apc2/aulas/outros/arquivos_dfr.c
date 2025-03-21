#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[50];
	float notas[3];
} Aluno;

float media(size_t n, float arr[n]) {
	float res = 0;
	for (int i = 0; i < n; i++)
		res += arr[i];
	return res / n;
}

int aprovado(Aluno a) {
	return media(3, a.notas) >= 5;
}

int salvar_aluno_txt(char *nome_arquivo, int n, Aluno alunos[n]) {
	FILE *fptr = fopen(nome_arquivo, "w");
	
	for (int i = 0; i < n; i++) {
		Aluno curr = alunos[i];
		
		if (fprintf(fptr, "%s\t%.2f\t%s\n", curr.nome, media(3, curr.notas),
		aprovado(curr)? "Aprovado" : "Reprovado") <= 0) {
			fclose(fptr);
			
			return -1;
		}
	}
	
	fclose(fptr);
	
	return 0;
}

int ler_aluno_txt(char *nome_arquivo) {
	FILE *fptr = fopen(nome_arquivo, "r");
	char nome[50];
	float media;
	char situacao[10];
	
	while (!feof(fptr)) {
		if (fscanf(fptr, "%[^\t]\t%f\t%s\n", nome, &media, situacao) != 3) {
			fclose(fptr);
			
			return -1;
		}
		
		printf("%s\t%.2f\t%s\n", nome, media, situacao);
	}
	
	fclose(fptr);
	
	return 0;
}

int salvar_aluno_bin(char *nome_arquivo, int n, Aluno alunos[n]) {
	FILE *fptr = fopen(nome_arquivo, "wb");
	int ret_val = 0;
	
	if (fwrite(alunos, sizeof(Aluno), n, fptr) != n)
		ret_val = -1;
	
	fclose(fptr);
	
	return ret_val;
}

Aluno *ler_aluno_bin(char *nome_arquivo, int n) {
	FILE *fptr = fopen(nome_arquivo, "rb");
	Aluno *alunos = malloc(n * sizeof(Aluno));
	
	if (!alunos) fclose(fptr);
	if (!fptr) free(alunos);
	if (!fptr || !alunos) return NULL;
	if (fread(alunos, sizeof(Aluno), n, fptr) != n) {
		fclose(fptr);
		free(alunos);
		return NULL;
	}
	
	return alunos;
	
}

int main() {
	Aluno alunos[10] = {
		{"Ana", {5.3, 8.7, 6.5}},
		{"Beto", {2, 2.5, 7.5}},
		{"Caio", {5.3, 8.7, 8.5}},
		{"Davi", {5.3, 4.7, 2.5}},
		{"Edu", {5.3, 8.7, 6.5}},
		{"Fabio", {5.3, 8.7, 6.5}},
		{"Gabi", {5.3, 8.7, 6.5}},
		{"Hellen", {3.3, 2.7, 6.5}},
		{"Iev", {5.3, 3.7, 6.5}},
		{"Julia", {4.3, 8.7, 9.5}}
	};
	int sat = salvar_aluno_txt("alunos.txt", 10, alunos);
	int sab = salvar_aluno_bin("alunos.bin", 10, alunos);
	
	fprintf(stderr, ".txt escrito %s sucesso\n", (sat == 0)? "com" : "sem");
	fprintf(stderr, ".bin escrito %s sucesso\n", (sab == 0)? "com" : "sem");
	
	if (sat == 0) {
		int lat = ler_aluno_txt("alunos.txt");
		
		fprintf(stderr,
		"\n%stodas as linhas do .txt lidas com sucesso\n", (lat == 0)? "" : "nem ");
	}
	if (sab == 0) {
		Aluno *lab = ler_aluno_bin("alunos.bin", 10);
		
		if (lab != NULL) {
			fprintf(stderr, ".bin lido com sucesso\n");
			free(lab);
		}
		else fprintf(stderr, "erro de leitura do .bin\n");
	}
	
	return 0;
}

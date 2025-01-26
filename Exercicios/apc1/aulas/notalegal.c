#include <stdio.h>
int main(){
	char item1[30];
	int qtd1;
	float valor1;
	scanf("%s", item1);
	scanf("%d", &qtd1);
	scanf("%f", &valor1);

	char item2[30];
	int qtd2;
	float valor2;
	scanf("%s", item2);
	scanf("%d", &qtd2);
	scanf("%f", &valor2);

	char item3[30];
	int qtd3;
	float valor3;
	scanf("%s\n", item3);
	scanf("%d", &qtd3);
	scanf("%f", &valor3);
	
	for (int i = 0; i < 26; i++){
		printf("-");
	}
	printf("\n	N O T A  L E G A L\n");
	for (int i = 0; i < 26; i++){
		printf("-");
	}
	printf("\nItem		Qtd		Valor\n");
	printf("%s", item1);
	printf("......%d", qtd1);
	printf("......%.2f\n", valor1);
	
	printf("%s", item2);
	printf("......%d", qtd2);
	printf("......%.2f\n", valor2);

	printf("%s", item3);
	printf("......%d", qtd3);
	printf("......%.2f\n", valor3);
	float total = (valor1 + valor2 + valor3);
	for (int i = 0; i < 26; i++){
		printf("-");
	}
	printf("\nTotal				%.2f\n", total);
	for (int i = 0; i < 26; i++){
		printf("-");
	}
	printf("\n");

	return 0;
}

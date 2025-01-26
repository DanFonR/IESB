#include <stdio.h>
int main(){
	int ano;
	printf("Insira um ano: ");
	if (scanf("%d", &ano) != 1){
		printf("Digite um ano válido\n");
		return 1;
	}
	if ((!(ano % 4) && (ano % 100)) || !(ano % 400)){
		printf("O ano é bissexto\n");
	}
	else{
		printf("O ano não é bissexto\n");
	}
	return 0;
}

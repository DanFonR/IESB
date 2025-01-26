#include <stdio.h>
int main(){
	printf("digite um numero inteiro: ");
	int numero;
	unsigned long long fatorial = 1;
	if (!(scanf("%d", &numero)) || (numero < 0)){
		printf("digite um numero valido\n");
		return 1;
	}
	for (int i = 1; i <= numero; i++){
		if (numero == 0 || numero == 1){
			printf("1\n");
			break;
		}
		fatorial *= i;

	}
	printf("%lu\n", fatorial);
	return 0;
}

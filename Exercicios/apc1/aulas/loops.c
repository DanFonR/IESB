#include <stdio.h>
int main(){
	printf("Entre com um numero inteiro: ");
	int numero = 1;
	if (!(scanf("%d", &numero))){
		printf("Entre com um numero valido\n");
		return 1;
	}
	for (int i = 1; i <= 10; i++){
		printf("%d * %d = %d\n", numero, i, numero*i);
	} //for (;;) = loop infinito
	return 0;
}

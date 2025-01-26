#include <stdio.h> //menor e maior num entre 10
int main(){
	int numeros[10];

	for (int i = 0; i < 10; i++){
		printf("Digite o %do numero: ", i+1);
		if (!(scanf("%d", &numeros[i]))){
			printf("Digite um numero valido\n");
			return 1;
		}
	}
	int min = numeros[0];
	int max = numeros[0];
	for (int j = 1; j < 10; j++){
		if (numeros[j] > max){
			max = numeros[j];
		}
		else if (numeros[j] < min){
			min = numeros[j];
		}
	}
	printf("o maior é %d e o menor é %d\n", max, min);
	return 0;
}

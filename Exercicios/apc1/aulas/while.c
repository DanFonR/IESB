#include <stdio.h>
int main(){
	int num = 0;
	printf("digite um numero entre 1 e 10: ");
	int input = scanf("%i", &num);
	getchar();
	while (!input){
		printf("digite um numero valido: ");
		input = scanf("%i", &num);
		getchar();
	}
	int i = 1;
	while (i <= 10){
		printf("%d x %d = %d\n", num, i, num*i);
		i++;
	}
	return 0;
}

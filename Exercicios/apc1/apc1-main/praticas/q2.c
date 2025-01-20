#include <stdio.h>
int main(){
	float valor;
	printf("insira um valor: ");
	scanf("%f", &valor);
	printf("o valor do desconto é de ");
	if ((0 <= valor) && (valor <= 100)){
		printf("%.2f\n", valor*(.01));
	}
	else if ((100.01 <= valor) && (valor <= 500)){
		printf("%.2f\n", valor*(.05));
	}
	else if (valor > 500){
		printf("%.2f\n", valor*(.1));
	}
	return 0;
}

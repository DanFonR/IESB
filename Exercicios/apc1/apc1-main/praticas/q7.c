#include <stdio.h>
int main(){
	int ant = 1;
	int prox = 1;
	printf("%d\n", ant);
	for (int i = 0; i < 9; i++){
		printf("%d\n", prox);
		int temp = prox+ant;
		ant = prox;
		prox = temp;
	}
	return 0;
}

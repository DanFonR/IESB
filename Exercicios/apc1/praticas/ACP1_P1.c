// o seguinte codigo inclui todos
// os exercicios da pratica 1
#include <stdio.h>
#include <math.h>

// exercicio 1
float mediafinal(float A1, float A2){
	float res = 0.4 * A1 + 0.6 * A2;
	return res;
}

// exercicio 2
float areatriangulo(unsigned int base, unsigned int altura){
	float res = ((float)base * altura) / 2;
	return res;
}

// exercicio 3
float circunferencia(int raio){
	float res = 2 * raio * 3.1416;
	return res;
}

// exercicio 4
float precofinal(float preco){
	float res = preco*(1 + 0.17 + 0.076 + 0.0165);
	return res;
}

// exercicio 5
double gigaparabyte(float gigabytes){
	double res = gigabytes * pow(1024, 3);
	return res;
}

// parte do exercicio 6, calculo do delta
float delta(float a, float b, float c){
	float res = pow(b, 2) - 4 * a * c;
	return res;
}

// exercicio 7 dentro da funcao main

// exercicio 8
void conversortempo(int segundos){
	int h = segundos / 3600;
	int m = (segundos / 60) % 60;
	int s = segundos % 60;
	printf("\n%d segundos sao %dh %dm %ds.", segundos, h, m, s);
	return;
}

// exercicio 9
int conversoridade(int anos, int meses, int dias){
	int res = 365 * anos + 30 * meses + dias;
	return res;
}

// exercicio 10
void decompor(int num){
	int m, c, d, u;
	m = num / 1000;
	c = (num / 100) % 10;
	d = (num / 10) % 10;
	u = num % 10;
	printf("\no numero %d se decompoe em %d unidades, %d dezenas, %d centenas, e %d milhares.", num, u, d, c, m);
	return;
}

int main(){
	int escolha;
	printf("escolha uma das opcoes para demonstrar o codigo dos exercicios\n\
1. media final;\n\
2. area do triangulo;\n\
3. perimetro de uma pizza;\n\
4. produto mais impostos;\n\
5. gigabytes para bytes;\n\
6. bhaskara;\n\
7. altura de um aviao;\n\
8. segundos para horas, minutos e segundos;\n\
9. idade em anos, meses e dias em dias; ou\n\
10. decomposicao de um numero.\n\n");
	
  if (scanf("%d", &escolha) != 1){
    printf("insira um numero valido");
    return 1;
  }
  printf("\nvoce escolheu a %da opcao.\n\n", escolha);
	switch (escolha){
		case 1:;
			float A1, A2;
			printf("insira os valores da A1 e A2, nessa ordem.\n\n");
			if (scanf("%f %f", &A1, &A2) != 2){
        printf("insira 2 valores validos");
        return 1;
      }
			printf("\npara A1 nota %.2f e A2 nota %.2f, sua media final sera %.2f.", A1, A2, mediafinal(A1, A2));
			break;
		case 2:;
			unsigned int base, altura;
			printf("insira os valores da base e da altura, nessa ordem.\n\n");
			if (scanf("%u %u", &base, &altura) != 2){
        printf("insira 2 valores validos");
        return 1;
      }
			printf("\no triangulo possui area de %.1fu^2", areatriangulo(base, altura));
			break;

		case 3:;
			int raio;
			printf("insira o valor do raio da pizza.\n\n");
			if (scanf("%d", &raio) != 1){
        printf("insira um valor valido");
        return 1;
      }
			printf("\na pizza possui perimetro de %.4fcm.", circunferencia(raio));
			break;

		case 4:;
			float preco;
			printf("insira o preco do produto antes dos tributos.\n\n");
			if (scanf("%f", &preco) != 1){
        printf("insira um valor valido");
        return 1;
      }
			printf("\no preco final sera de R$%.2f.", precofinal(preco));
			break;

		case 5:;
			float gigabytes;
			printf("insira o valor em gigabytes a ser convertido para bytes.\n\n");
			if (scanf("%f", &gigabytes) != 1){
        printf("insira um valor valido");
        return 1;
      }
			printf("\n%.2fGB sao %.2lf bytes.", gigabytes, gigaparabyte(gigabytes));
			break;

		case 6:;
			float a, b, c;
			printf("seja ax^2+bx+c=0. insira os valores de a, b, e c, nessa ordem.\n\n");
			if (scanf("%f %f %f", &a, &b, &c) != 3){
        printf("insira 3 valores validos");
        return 1;
      }
			if (a == 0){
				printf("\nequacao de 1o grau, nao de 2o.");
				break;
			}
			else if (delta(a, b, c) < 0){
				printf("\nnao ha solucoes reais.");
				break;
			}
			else{
				float res1 = (-b + sqrt(delta(a, b, c))) / (2 * a);
				float res2 = (-b - sqrt(delta(a, b, c))) / (2 * a);
				if (res1 == res2){
					printf("\na solucao para a equacao possui valor %.2f.", res1);
					break;
				}
				else{
					printf("\nas solucoes para a equacao sao %.2f e %.2f.", res1, res2);
					break;
				}
			}

		case 7:;
			float distancia;
			printf("insira a distancia percorrida pelo aviao em quilometros.\n\n");
			if (scanf("%f", &distancia) != 1){
        printf("insira um valor valido");
        return 1;
      }
			printf("\no aviao esta a no maximo %.2fkm acima do chao.", sin(M_PI/4)*distancia);
			break;

		case 8:;
			int segundos;
			printf("insira quantos segundos.\n\n");
			if (scanf("%d", &segundos) != 1){
        printf("insira um valor valido");
        return 1;
      }
			conversortempo(segundos);
			break;

		case 9:;
			int anos, meses, dias;
			printf("insira sua idade em anos, meses, e dias, nessa ordem.\n\n");
			if (scanf("%d %d %d", &anos, &meses, &dias) != 3){
        printf("insira 3 valores validos");
        return 1;
      }
			printf("\n%d anos %d meses e %d dias sao %d dias", anos, meses, dias, conversoridade(anos, meses, dias));
			break;

		case 10:;
			int numero;
			printf("insira o numero a ser decomposto.\n\n");
			if (scanf("%d", &numero) != 1){
        printf("insira um valor valido");
        return 1;
      }
			decompor(numero);
			break;

		default:
			printf("\nvoce inseriu um numero invalido");
			break;
}
	return 0;
}

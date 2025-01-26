#include <stdio.h>
#include <math.h>

float media(float num1, float num2, float num3){
	float media = (num1 + num2 + num3) / 3;
	return media;
}

void quociente_resto(int num1, int num2){
	printf("\nNa divisão entre %d e %d, o quociente é %d e o resto %d.\n", num1, num2, num1 / num2, num1 % num2);
}

float conversor_temp(float celsius){
	float fahrenheit = 1.8 * celsius + 32;
	return fahrenheit;
}

float area_hectare(float comprimento, float largura){
	float hectares = comprimento * largura / 10000;
	return hectares;
}

float imc(float peso, float altura){
	float imc = peso / pow(altura, 2);
	return imc;
}

float depreciacao(float valor, int ano_compra, int ano_consulta){
	float depreciado = (ano_consulta - ano_compra) * .01 * valor;
	return depreciado;
}

void trabalho(float valor_hora, int horas_mes){
	float salario_bruto = valor_hora * horas_mes;
	float descontos = salario_bruto * (.25 + .11);
	float salario_liquido = salario_bruto - descontos;
	printf("\nO salário bruto será de R$%.2f, e, descontando IR e INSS de R$%.2f, o salário líquido será de R$%.2f por mes.\n", salario_bruto, descontos, salario_liquido);
}

float distancia(float x1, float y1, float x2, float y2){
	float dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return dist;
}

char ascii(unsigned int num){
	return (char)num;
}

void tabuada(int num){
	printf("A tabuada do número %d é:\n\n", num);
	for (int i = 1; i <= 10; i++){
		printf("%d * %d = %d\n", num, i, num * i);
	}
}

int main(){
	printf("Escolha dentre as opções:\n\
1. Média entre 3 valores;\n\
2. Quociente e resto de divisão;\n\
3. Celsius para Fahrenheit;\n\
4. Área em hectares;\n\
5. Índice de Massa Corporal (IMC);\n\
6. Valor depreciado de veículo;\n\
7. Salário bruto, líquido, e impostos;\n\
8. Distancia entre 2 coordenadas;\n\
9. Tabela ASCII; ou\n\
10. Tabuada.\n\n");

	int escolha;
	if (scanf("%d", &escolha) != 1){
		printf("Opção inválida.\n");
		return 1;
	}

	switch (escolha){

		case 1:
			printf("\nDigite os 3 valores, 1 de cada vez.\n\n");
			float num1, num2, num3;
			if (scanf("%f %f %f", &num1, &num2, &num3) != 3){
				printf("\nDigite 3 valores validos.\n");
				return 1;
			}
			printf("\nA média dos valores é %.3f.\n", media(num1, num2, num3));
			break;

		case 2:
			printf("\nDigite o dividendo e o divisor, nessa ordem.\n\n");
			int dividendo, divisor;
			if (scanf("%d %d", &dividendo, &divisor) != 2){
				printf("\nDigite 2 valores válidos.\n");
				return 1;
			}
			quociente_resto(dividendo, divisor);
			break;

		case 3:
			printf("\nDigite a temperatura em graus Celsius.\n\n");
			float celsius;
			if (scanf("%f", &celsius) != 1){
				printf("\nDigite um valor válido.\n");
				return 1;
			}
			printf("\nA temperatura de %.3f graus Celsius é igual a %.3f graus Fahrenheit.\n", celsius, conversor_temp(celsius));
			break;

		case 4:
			printf("\nDigite os valores do comprimento e largura do terreno, em metros.\n\n");
			float comprimento, largura;
			if (scanf("%f %f", &comprimento, &largura) != 2){
				printf("\nDigite 2 valores válidos.\n");
				return 1;
			}
			printf("\nA área do terreno vale %.3fha.\n", area_hectare(comprimento, largura));
			break;

		case 5:
			printf("\nDigite seu peso em kg e sua altura em m, nessa ordem.\n\n");
			float peso, altura;
			if (scanf("%f %f", &peso, &altura) != 2){
				printf("\nDigite 2 valores válidos.\n");
				return 1;
			}
			printf("\nSeu IMC vale %.2f.\n", imc(peso, altura));
			break;

		case 6:
			printf("\nDigite, na seguinte ordem: valor do veículo, ano de compra, e ano de consulta.\n\n");
			float valor;
			int ano_compra, ano_consulta;
			if (scanf("%f %d %d", &valor, &ano_compra, &ano_consulta) != 3){
				printf("\nDigite 3 valores válidos.\n");
				return 1;
			}
			printf("O veículo depreciou R$%.2f.\n", depreciacao(valor, ano_compra, ano_consulta));
			break;
		
		case 7:
			printf("\nDigite, nessa ordem, valor da hora de trabalho, e horas trabalhadas no mes.\n\n");
			float valor_hora;
			int horas_mes;
			if (scanf("%f %d", &valor_hora, &horas_mes) != 2){
				printf("\nDigite 2 valores válidos.\n");
				return 1;
			}
			trabalho(valor_hora, horas_mes);
			break;

		case 8:
			printf("\nDigite, na seguinte ordem: valor de x1 e y1, depois x2 e y2.\n\n");
			float x1, y1, x2, y2;
			if (scanf("%f %f %f %f", &x1, &y1, &x2, &y2) != 4){
				printf("\nDigite 4 valores válidos.\n");
				return 1;
			}
			printf("A distancia entre os pontos (%.2f, %.2f) e (%.2f, %.2f) é de %.4f\n", x1, y1, x2, y2, distancia(x1, y1, x2, y2));
			break;

		case 9:
			printf("\nDigite um número para ser convertido em um caractere ASCII.\n\n");
			unsigned int num;
			if (scanf("%u", &num) != 1){
				printf("\nDigite um valor válido.\n");
				return 1;
			}
			printf("%u na tabela ASCII é o caractere: %c\n", num, ascii(num));
			break;

		case 10:
			printf("\nDigite um número para exibir sua tabuada.\n\n");
			int numero;
			if (scanf("%d", &numero) != 1){
				printf("\nDigite um valor válido.\n");
				return 1;
			}
			tabuada(numero);
			break;
		default:
			printf("\nDigite um numero valido\n");
			return 1;
	}
	return 0;
}

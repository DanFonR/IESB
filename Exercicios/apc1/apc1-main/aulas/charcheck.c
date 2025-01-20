#include <stdio.h>
int main(){printf("Entre um caractere: "); int ch = (int)getchar(); if (ch >= 48 && ch <= 57){printf("O caractere é um dígito\n");} else if ((65 <= ch && ch <= 90) || (97 <= ch && ch <= 122)) {printf("O caractere é uma letra\n");} else{printf("O caractere é um caractere especial\n");} return 0;}

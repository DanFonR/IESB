#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

#define clear_cin() \
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

typedef struct {
    double x1;
    double x2;
    long floor_soma;
} dados_bhaskara;

dados_bhaskara bhaskara(double a, double b, double c) {
    dados_bhaskara resultado = {0.0, 0.0, 0L};
    double delta = b * b - 4 * a * c;
    double x1;
    double x2;

    if (delta < 0 || a == 0)
        return resultado;

    #pragma omp parallel
    {
        x1 = (-b + std::sqrt(delta)) / (2 * a);
        x2 = (-b - std::sqrt(delta)) / (2 * a);
    }

    resultado.x1 = x1;
    resultado.x2 = x2;
    resultado.floor_soma = static_cast<long>(x1 + x2);

    return resultado;
}

omp_lock_t lock_pares;
omp_lock_t lock_impares;

void testa_bhaskara(size_t size) {
    std::vector<dados_bhaskara> valores(size);
    size_t pares = 0;
    size_t impares = 0;

    std::cout << "Preenchendo valores..." << std::endl;

    #pragma omp parallel for
    for (size_t i = 0; i < valores.size(); i++)
        valores[i] = bhaskara(rand() % 100 + 1, rand() % 100, rand() % 100);

    std::cout << "Valores preenchidos" << std::endl
    << "Checando floor(soma) dos pares..." << std::endl;

    #pragma omp parallel for
    for (dados_bhaskara valor : valores) {
        if (valor.floor_soma % 2 == 0) {
            omp_set_lock(&lock_pares);
            pares++;
            omp_unset_lock(&lock_pares);
        }
        else {
            omp_set_lock(&lock_impares);
            impares++;
            omp_unset_lock(&lock_impares);
        }
    }

    std::cout << "Das " << valores.size() << " equações, " << pares
    << " tiveram floor(soma) par e " << impares << " floor(soma) impar"
    << std::endl;
}

/* 
    Explicação:
        A função `teste_bhaskara` testa N equações de bháskara quanto ao
    floor da soma das suas soluções e, com base na sua paridade, incrementa con-
    tadores em paralelo, usando locks próprios para evitar condições de corrida.
    Os dados do vetor contém o valor de retorno da função `bhaskara`, que retor-
    na as 2 soluções da equação de bháskara, dado 3 doubles como fatores, e o
    floor da soma deles. Caso a equação não seja válida, os 3 valores da estru-
    tura são 0. Para o cálculo, as 2 raízes são calculadas em paralelo. A função
    de teste usa termos aleatórios para os cálculos. Na função `main`, seta-se a
    seed para a função `rand`, usada na função de teste, inicializam-se os
    locks, chama-se a função de teste, e, por fim, os locks são destruídos.
*/

int main() {
    const size_t tamanho = 100000;

    std::srand(std::time(NULL));

    omp_init_lock(&lock_pares);
    omp_init_lock(&lock_impares);

    testa_bhaskara(tamanho);

    omp_destroy_lock(&lock_pares);
    omp_destroy_lock(&lock_impares);
    return 0;
}

#include <iostream>
#include <vector>
#include <omp.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

// Macro que limpa buffer do cin
#define clear_cin() \
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

// Estrutura que armazena o resultado da equação e se ela é válida
typedef struct {
    double resultado;
    bool valido_ok;
} resultados;

typedef struct {
    int validas;
    int invalidas;
} validez;

resultados bhaskara_raiz_delta_pos(double a, double b, double c) {
    resultados resultado = {0.0, true};

    double delta = std::pow(b, 2) - 4 * a * c;

    if (delta < 0 || a == 0) {
        resultado.valido_ok = false;
        return resultado;
    }

    double raiz_1 = (-b + std::sqrt(delta)) / (2 * a);
    resultado.resultado = raiz_1;

    return resultado;
}

void teste_bhaskara() {
    std::srand(std::time(NULL));

    int qtd = 0;

    std::cout << "Quantidade de equações a serem resolvidas: ";
    std::cin >> qtd;
    clear_cin();
    std::cout << std::endl;

    if (qtd < 1) {
        std::cout << "Quantidade inválida de equações" << std::endl;
        return;
    }

    std::vector<resultados> equacoes(qtd);
    std::vector<validez> sucesso_threads;

    #pragma omp parallel
    {
        sucesso_threads = std::vector<validez>(omp_get_num_threads(), {0, 0});

        #pragma omp barrier

        #pragma omp for schedule(dynamic)
        for (int i = 0; i < qtd; i++) {
            double a = std::rand() % 100;
            double b = std::rand() % 100;
            double c = std::rand() % 100;

            equacoes[i] = bhaskara_raiz_delta_pos(a, b, c);
            if (equacoes[i].valido_ok)
                sucesso_threads[omp_get_thread_num()].validas++;
            else
                sucesso_threads[omp_get_thread_num()].invalidas++;
        }

        #pragma omp barrier

        #pragma omp for ordered
        for (int i = 0; i < omp_get_num_threads(); i++) {
            #pragma omp ordered
            {
                validez eq_thread = sucesso_threads[i];
                int total = eq_thread.invalidas + eq_thread.validas;

                std::cout << "Thread " << i << " resolveu "
                << total << " equacoes, das quais " << eq_thread.validas
                << " eram válidas e " << eq_thread.invalidas << " não"
                << std::endl;
            }
        }

        #pragma omp barrier

        #pragma omp single
        std::cout << std::endl;

        #pragma omp barrier

        #pragma omp for ordered
        for (int i = 0; i < qtd; i++) {
            #pragma omp ordered
            {
                std::cout << "Equação " << i + 1;
                if (equacoes[i].valido_ok) {
                    std::cout << " tem como resultado "
                    << equacoes[i].resultado << std::endl;
                }
                else {
                    std::cout << " não é válida" << std::endl;
                }
            }
        }
    }
}

/* 
 * Explicação:
 *     O objetivo da função `bhaskara_raiz_delta_pos` é resolver uma equação de
 * segundo grau dados os seus termos, determinar se a equação é válida, e retor-
 * nar uma estrutura com o resultado e um booleano, que indica a validez da e-
 * quação. Caso a equação não seja válida, a estrutura retornada tem valor
 * `{0.0, false}`. Já a função `teste_bhaskara` testa a função anterior, usando
 * entrada de usuário para determinar a quantidade de equações a serem resolvi-
 * das e preenchendo um vetor de estruturas com os resultados de equações com
 * termos aleatórios. Além disso, com um vetor de inteiros com a quantidade de
 * threads usadas, soma-se o booleano obtido da operação, tratado como inteiro.
 * Após uma sincronização das threads com a diretiva `barrier`, realiza-se orde-
 * nadamente com a diretiva `ordered`, a impressão das threads, a quantidade de
 * equações que resolveu, a quantidade de equações válida e inválidas, e após
 * outra sincronização, imprime-se, também em ordem, o resultado das equações
 * (caso tenham).
*/

int main() {
    teste_bhaskara();
    
    return 0;
}

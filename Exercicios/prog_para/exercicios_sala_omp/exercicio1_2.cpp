#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <limits>
#include <omp.h>
#include <cstdlib>
#include <ctime>

#define clear_cin() \
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n')

typedef std::tuple<double, double, double> termos;
typedef std::pair<double, double> resultado;

typedef struct {
    termos termos_equacao;
    resultado resultado_equacao;
    double tempo;

} resultados_agg;

/* 1. Faça um programa que utilize OpenMP para paralelizar a resolução das
 * equações do segundo grau com a formula de Bhaskara. */
resultado resolver_bhaskara(double a, double b, double c) {
    if (a == 0)
        return {0.0, 0.0};

    double delta = 0.0;
    double x1 = 0.0;
    double x2 = 0.0;
    bool invalid = false;

    #pragma omp parallel num_threads(2)
    {
        double x1_numer = 0.0;
        double x2_numer = 0.0;
        double b2 = 0.0;
        double ac = 0.0;
        double delta_sqrt = 0.0;
        double denom = 0.0;

        #pragma omp single
            b2 = b * b;

        #pragma omp single
            ac = 4 * a * c;

        #pragma omp barrier

        delta = b2 - ac;

        #pragma omp master
        {
            if (delta < 0) {
                invalid = true;
                delta = 0;
            }
        }

        #pragma omp single
            delta_sqrt = std::sqrt(delta);

        #pragma omp single
            denom = 2 * a;

        #pragma omp barrier

        #pragma omp single
            x1_numer = -b + delta_sqrt;

        #pragma omp single
            x2_numer = -b - delta_sqrt;

        #pragma omp barrier

        #pragma omp single
            x1 = x1_numer / denom;

        #pragma omp single
            x2 = x2_numer / denom;

        #pragma omp barrier
    }

    if (invalid)
        return {0.0, 0.0};

    return {x1, x2};
}
/*
 * Explicação:
 *       O objetivo da função resolver_bhaskara é a resolução em paralelo de uma 
 *  equação de 2º grau. Primeiramente, se a for igual a 0, retorna-se um par de
 *  zeros. Depois, declaram-se o delta, os resultados x1 e x2, e um booleano pa-
 *  ra determinar se a equação é válida. Depois, entra-se em uma região de para-
 *  lelismo, com duas threads. Nela, declaram-se os numeradores dos resultados
 *  x1 e x2, e, em threads separadas, calculam-se o quadrado de b e o produto
 *  entre 4, a, e c. Após isso, as duas threads são sincronizadas com uma
 *  barrier, e calcula-se o resultado de delta. Caso ele seja menor que zero,
 *  delta se torna 0 e o booleano se torna verdadeiro, na thread principal. Se
 *  não, calculam-se a raiz de delta e o denominador comum, em threads
 *  separadas, que depois são sincronizadas. Logo depois, novamente em threads
 *  separadas que são sincronizadas posteriormente, determinam-se os numeradores
 *  das duas soluções. Depois, usando o mesmo método, faz-se o cálculo das duas
 *  soluções. Por fim, fora da região de paralelismo, retorna-se o resultado:
 *  caso o booleano seja verdadeiro, retorna-se um par de zeros. Caso contrário,
 *  retorna-se o par de resultados corretos.
*/

/* 2. crie uma entrada de dados onde o usuário decicirá a quantidade de equações
 * a serem resolvidas. Ao final, mostre o tempo gasto para resolver as equações,
 * e o número de equações que possuem raízes reais e quantas não possuem. */
void resolver_equacoes() {
    srand(time(NULL));

    int quantidade = 0;
    double tempo_total = 0.0;
    int qtd_raizes_reais = 0;
    int qtd_raizes_complexas = 0;

    std::vector<resultados_agg> resultados = std::vector<resultados_agg>();

    std::cout << "Digite a quantidade de equações a serem resolvidas: ";
    std::cin >> quantidade;
    clear_cin();

    if (quantidade == 0) {
        std::cout << "Quantidade 0 de equações" << std::endl;
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        double a = rand() % 100 + 1;
        double b = rand() % 101;
        double c = rand() % 101;

        termos termos_eq = termos{a, b, c};

        resultados_agg agg = {termos_eq, resultado(), 0.0};
        resultados.push_back(agg);
    }

    #pragma omp parallel for reduction(+: tempo_total, qtd_raizes_reais)
    for (int i = 0; i < quantidade; i++) {
        double t0 = omp_get_wtime();

        resultados_agg agg = resultados[i];
        termos termos_eq = agg.termos_equacao;
        double a = std::get<0>(termos_eq);
        double b = std::get<1>(termos_eq);
        double c = std::get<2>(termos_eq);

        agg.resultado_equacao = resolver_bhaskara(a, b, c);

        double t1 = omp_get_wtime();
        double tempo = t1 - t0;
        double delta = b * b - 4 * a * c;

        agg.tempo = tempo;
        resultados[i] = agg;

        tempo_total += tempo;

        if (delta >= 0)
            qtd_raizes_reais++;
    }

    for (int i = 0; i < quantidade; i++) {
        resultados_agg agg = resultados[i];

        std::cout << "Tempo para executar equação " << i + 1 << ": "
        << agg.tempo << std::endl;
    }

    qtd_raizes_complexas = quantidade - qtd_raizes_reais;

    std::cout << "Tempo total: " << tempo_total << std::endl;
    std::cout << "Total de equações com raízes reais: "
    << qtd_raizes_reais
    << " (Sem raízes reais: " << (qtd_raizes_complexas) << ")" << std::endl;
}

/* 
 * Explicação:
 *      O objetivo da função resolver_equacoes é aplicar a fórmula de Bhaskara
 *  usando os valores dos termos armazenados em um vetor de tamanho especificado
 *  pelo usuário, anotar o tempo de execução, e determinar se a equação possui
 *  raízes reais. Primeiro, declaram-se a quantidade de itens no vetor, o tempo
 *  total de execução, a quantidade de equações com raízes reais, e um vetor com
 *  estruturas que contêm os termos da equação, o resultado dela, e o tempo de
 *  execução. Depois, pedem-se a entrada de usuário para a quantidade de equa-
 *  ções a serem resolvidas, e limpa-se o buffer da entrada de caracteres. Caso
 *  a quantidade de equações seja zero, imprime-se que não há equações a serem
 *  resolvidas e a função retorna. Se não, entra-se num loop, que preenche o ve-
 *  tor com os termos da equação: declaram-se os termos a, b, e c, que são pre-
 *  enchidos com valores aleatórios entre 0 e 100, cria-se uma tupla com os val-
 *  ores de a, b, e c, cria-se a estrutura, inicializada com os valores da
 *  tupla, um par vazio, e tempo de execução 0, e armazena-se a estrutura no ve-
 *  tor. Depois, cria-se uma região de execuação em paralelo com loop for de re-
 *  dução, que será usado para incrementar o tempo total de execução e a quanti-
 *  dade de equações com raízes reais. Então, registra-se um timestamp, reúnem-
 *  -se os termos da equação, realiza-se a operação da fórmula, registra-se um 
 *  segundo timestamp, a diferença entre os dois timestamps, e armazena na es-
 *  trutura o resultado da fórmula e o tempo de execução, além de atualizar o
 *  tempo total de execução e, caso o delta obtido com a, b, e c seja maior que
 *  zero, incrementa-se a quantidade de equações com raízes reais. Fora da área
 *  de paralelismo, imprimem-se os dados de cada estrutura no vetor, o tempo
 *  total de execução e a quantidade de equações com ou sem raízes reais.
*/

int main() {
    resolver_equacoes();

    return 0;
}

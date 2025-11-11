#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>
#include <vector>

/* Exercício 4 — Medindo tempo por thread
Adapte o código do exercício anterior para:
a) Medir e exibir o tempo total de execução.
b) Medir e exibir o tempo gasto por cada thread.
c) Mostrar quantas threads foram utilizadas no cálculo. */

// Define uma macro que é expandida durante a compilação para 1 milhão
#define TAMANHO_VETOR 1000000

/* Define um tipo de ponteiro para função que descreve as funções de soma de
quadrados usadas para o exercício 4. */
typedef void (*func_soma)(double *, double *, double *, double *, size_t);

void soma_quadrados_sequencial(double x[], double y[], double z[],
    double a[], size_t tamanho) {
    /* Declara e define a função `soma_quadrados_sequencial`, que não retorna
    valor, e leva como parâmetros quatro arrays de tipo double, com o último
    para armazenar o resultado de uma operação de soma de quadrados dos valores
    em índices iguais em cada array, e o tamanho dos arrays, que devem ter o
    mesmo tamanho. */

    /* Para cada índice, adiciona o quadrado dos valores em x, y, e z,
    e armazena essa soma de quadrados em a */
    for (size_t i = 0; i < tamanho; i++)
        a[i] = (x[i] * x[i]) + (y[i] * y[i]) + (z[i] * z[i]);
}

void soma_quadrados_paralelo(double x[], double y[], double z[],
    double a[], size_t tamanho) {
    // Similar à função anterior, mas adaptada para paralelismo.

    // Declara a quantidade de threads
    int qtd_threads;

    // Declara e inicializa um vetor de 100 doubles, todos inicializados com 0.
    std::vector<double> tempo_threads = std::vector<double>(100, 0.0);

    #pragma omp parallel
    {
        // c) Mostrar quantas threads foram utilizadas no cálculo.
        /* `omp_get_num_threads`: obtém a quantidade de threads usadas na
        região de paralelismo.
        `#pragma omp single`: faz com que apenas uma das threads execute
        o bloco. Isso evita múltiplos acessos ao mesmo recurso. */
        #pragma omp single
        qtd_threads = omp_get_num_threads();

        /* for schedule(static) realiza o mesmo que somente for. A diretiva
        `schedule` indica distribuição da iteração em diferentes threads, e
        `static` indica que as iterações serão distribuídas em ordem entre as
        threads, com cada thread trabalhando com
        `(iterações / tamanho_do_chunk) / quantidade_de_threads` chunks, tal
        que, caso não seja indicado, `tamanho_do_chunk` vale 1. Caso fosse indi-
        cado, a sintaxe do pragma seria
        `#pragma omp for schedule(static,tamanho_do_chunk)` */
        #pragma omp for schedule(static)
        for (size_t i = 0; i < tamanho; i++) {

            // Obtém o ID da thread
            int thread_id = omp_get_thread_num();

            // Obtém o tempo atual UNIX.
            double t0 = omp_get_wtime();

            a[i] = (x[i] * x[i]) + (y[i] * y[i]) + (z[i] * z[i]);

            // Obtém novamente o tempo atual.
            double t1 = omp_get_wtime();

            double tempo = t1 - t0;

            // b) Medir e exibir o tempo gasto por cada thread.
            /* Mede o tempo total para cada thread. Como nenhum elemento do ve-
            tor poderá ser acessado por mais de uma thread ao mesmo tempo, não
            há necessidade de usar a diretiva `critical`. */
            tempo_threads[thread_id] += tempo;

        }
    }

        // c) Mostrar quantas threads foram utilizadas no cálculo.
        std::cout << "Quantidade de threads utilizadas: "
                  << qtd_threads << std::endl << std::endl;

        // b) Medir e exibir o tempo gasto por cada thread.
        for (int i = 0; i < qtd_threads; i++) {
            std::cout << "Thread " << i << " gastou " << tempo_threads[i]
            << " segundos" << std::endl;
        }

        std::cout << std::endl;
}

void testa_soma_quadrados(func_soma func) {
    /* Declara e define a função `testa_soma_quadrados`, que não retorna valor,
    e cujo parâmetro é um ponteiro para uma função que retorna void e com parâ-
    metros de quatro ponteiros para double e uma variável de tipo size_t, nessa
    ordem. Ou seja, essa função espera as funções `soma_quadrados_sequencial` e
    `soma_quadrados_paralelo`, e as testa com dados aleatórios. */

    /* `srand`: define a seed para a função `rand`. Não há retorno de valor,
    e leva como parâmetro um inteiro, provido pela função `time`.
    `time`: retorna a hora UNIX do sistema, e leva como parâmetro um ponteiro
    para um inteiro.
    Esse método de definir a seed é muito usado. */
    srand(time(NULL));

    /* Declara arrays de double: o primeiro contém os resultados das operações,
    e o restante os operandos. Foi usada alocação dinâmica com `new` pois a
    alocação estática não foi permitida devido ao tamanho de 1 milhão de elemen-
    tos. */
    double *a = new double[TAMANHO_VETOR];
    double *x = new double[TAMANHO_VETOR];
    double *y = new double[TAMANHO_VETOR];
    double *z = new double[TAMANHO_VETOR];

    // Preenche os arrays de operandos com valores aleatórios de 0 a 99.
    for (size_t i = 0; i < TAMANHO_VETOR; i++) {
        x[i] = rand() % 100;
        y[i] = rand() % 100;
        z[i] = rand() % 100;
    }

    // a) Medir e exibir o tempo total de execução.
    // Obtém a hora atual em tipo double
    double t0 = omp_get_wtime();

    /* Desreferencia o ponteiro de função, e a chama com os arrays de double e
    a macro `TAMANHO_VETOR` como argumentos. */
    (*func)(x, y, z, a, TAMANHO_VETOR);
    double t1 = omp_get_wtime();

    // Obtém o tempo total de execução da soma de quadrados
    double tempo = t1 - t0;

    // Desaloca todos os ponteiros e libera a memória da heap
    delete[] a;
    delete[] x;
    delete[] y;
    delete[] z;

    // a) Medir e exibir o tempo total de execução.
    /* Exibe o tempo total de execução da função de soma de quadrados. */
    std::cout << "Tempo de execução: " << tempo << " segundos" << std::endl;
}

// Ponto de entrada para compilação. Deve se chamar `main` e retornar um inteiro
int main() {

    /* Para cada função de soma de quadrados imprime um header e chama a função
    de teste, com a função a ser testada como argumento. Nomes de funções, assim
    como nomes de arrays, agem como ponteiros, não precisando do operador `&`
    para obter seu endereço. */
    std::cout << "Soma sequencial" << std::endl;
    testa_soma_quadrados(soma_quadrados_sequencial);

    std::cout << std::endl << "Soma paralela" << std::endl;
    testa_soma_quadrados(soma_quadrados_paralelo);

    // Retorno padrão da função. 0 em caso de sucesso, 1 em caso de falha.
    return 0;
}

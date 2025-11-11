#include <iostream>
#include <vector>
#include <omp.h>

/* Exercício 5 — Escalonamento
Use novamente o cálculo de a[i] = x[i]^2 + y[i]^2 + z[i]^2, mas:
a) Execute com schedule(static) e schedule(dynamic, 1000).
b) Compare os tempos em diferentes quantidades de threads (2, 4, 8).
c) Explique em quais situações static e dynamic são mais adequados. */

// Define uma macro que é expandida durante a compilação para 1 milhão
#define TAMANHO_VETOR 1000000

/* Define um tipo de ponteiro para função que descreve as funções de soma de
quadrados usadas para o exercício 4. */
typedef void (*func_soma)(double *, double *, double *, double *, size_t);

void soma_quadrados_static(double x[], double y[], double z[],
    double a[], size_t tamanho) {
    /* Declara e define a função `soma_quadrados_static`, que não retorna
    valor, e leva como parâmetros quatro arrays de tipo double, com o último
    para armazenar o resultado de uma operação de soma de quadrados dos valores
    em índices iguais em cada array, e o tamanho dos arrays, que devem ter o
    mesmo tamanho. */

    // a) Execute com schedule(static) e schedule(dynamic, 1000)
    /* for schedule(static) realiza o mesmo que somente for. A diretiva
    `schedule` indica distribuição da iteração em diferentes threads, e
    `static` indica que as iterações serão distribuídas em ordem entre as
    threads, com cada thread trabalhando com
    `(iterações / tamanho_do_chunk) / quantidade_de_threads` chunks, tal
    que, caso não seja indicado, `tamanho_do_chunk` vale 1. Caso fosse indi-
    cado, a sintaxe do pragma seria
    `#pragma omp for schedule(static,tamanho_do_chunk)` */
    #pragma omp parallel for schedule(static)
        for (size_t i = 0; i < tamanho; i++) {
            /* Para cada índice, adiciona o quadrado dos valores em x, y, e z,
            e armazena essa soma de quadrados em a */
            a[i] = (x[i] * x[i]) + (y[i] * y[i]) + (z[i] * z[i]);
        }

}

void soma_quadrados_dynamic(double x[], double y[], double z[],
    double a[], size_t tamanho) {
    // Similar à função anterior, mas 

    // a) Execute com schedule(static) e schedule(dynamic, 1000)
    /* for schedule(dynamic) também divide as iterações em chunks, mas a aloca-
    ção de chunks por thread é dinâmica, sem seguir uma ordem específica */
    #pragma omp parallel for schedule(dynamic, 1000)
        for (size_t i = 0; i < tamanho; i++) {
            a[i] = (x[i] * x[i]) + (y[i] * y[i]) + (z[i] * z[i]);
        }
}

void testa_soma_quadrados(func_soma func, int qtd_threads) {
    /* Declara e define a função `testa_soma_quadrados`, que não retorna valor,
    e cujos parâmetros são um ponteiro para uma função que retorna void e com
    parâmetros de quatro ponteiros para double e uma variável de tipo size_t,
    nessa ordem, e um inteiro, indicando a quantidade de threads a executarem
    cada função. Ou seja, essa função espera as funções `soma_quadrados_static`
    e `soma_quadrados_paralelo`, e as testa com dados aleatórios. */

    /* `srand`: define a seed para a função `rand`. Não há retorno de valor,
    e leva como parâmetro um inteiro, provido pela função `time`.
    `time`: retorna a hora UNIX do sistema, e leva como parâmetro um ponteiro
    para um inteiro.
    Esse método de definir a seed é muito usado. */
    srand(time(NULL));

    /* Define a quantidade de threads que executarão os cálculos */
    omp_set_num_threads(qtd_threads);

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

    /* Exibe o tempo total de execução da função de soma de quadrados. */
    std::cout << "Tempo de execução: " << tempo << " segundos" << std::endl;
}

// Ponto de entrada para compilação. Deve se chamar `main` e retornar um inteiro
int main() {

    // b) Compare os tempos em diferentes quantidades de threads (2, 4, 8).
    /* Define um array de inteiros, que guarda as quantidades teste de threads
    para executarem as funções de soma de quadrados. No caso, 2, 4, e 8
    threads */
    int qtd_threads[3] = {2, 4, 8};

    for (int i = 0; i < 3; i++) {
        std::cout << "Número de threads: " << qtd_threads[i] << std::endl;

        /* Para cada função de soma de quadrados imprime um header e chama a
        função de teste, com a função a ser testada e a quantidade de threads
        como argumentos. Nomes de funções, assim como nomes de arrays, agem como
        ponteiros, não precisando do operador `&` para obter seu endereço. */
        std::cout << "Soma static" << std::endl;
        testa_soma_quadrados(soma_quadrados_static, qtd_threads[i]);

        std::cout << std::endl << "Soma dynamic" << std::endl;
        testa_soma_quadrados(soma_quadrados_dynamic, qtd_threads[i]);

        // c) Explique em quais situações static e dynamic são mais adequados.
        /* No geral, a partir de 4 threads, `dynamic` se torna mais rápido que 
        `static`. `dynamic` é mais adequado quando o custo computacional das o-
        perações é variável, enquanto `static` é mais adequado quando esse custo
        é semelhante em cada iteração, e é necessário menos overhead, pois a
        distribuição de iterações entre threads é estática, e não em tempo de e-
        xecução. */

        // Evita impressão desnecessária
        if (i < 2)
            std::cout << std::endl << "---" << std::endl << std::endl;
    }

    // Retorno padrão da função. 0 em caso de sucesso, 1 em caso de falha.
    return 0;
}

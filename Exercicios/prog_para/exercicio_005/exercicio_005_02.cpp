#include <iostream>
#include <vector>
#include <omp.h>

/* Exercício 2 — Paralelizando um for simples
a) Crie um vetor v de tamanho 100 e inicialize todos os elementos com o valor 1.
b) Escreva um loop sequencial que soma todos os elementos.
c) Refaça o loop com #pragma omp parallel for reduction(+:soma).
d) Compare os resultados e explique por que a diretiva reduction
é necessária. */

void sequential_for() {
    /* Declara e define a função `sequential_for`, que nem leva parâmetros nem
    retorna valor, e que itera sobre um vetor de 100 inteiros de valor 1, soman-
    do seus valores e imprimindo a soma. */
    /* Imprime (std::cout) um header, e depois um newline que limpa o buffer de
    saída (std::endl). */
    std::cout << "For sequencial" << std::endl;

    /* declara um inteiro de valor zero, que será o valor da soma. */
    int soma = 0;

    /* a) Crie um vetor v de tamanho 100 e inicialize todos os elementos
    com o valor 1. */
    /* declara um vetor de inteiros, de tamanho 100, com todos os elementos com
    valor 1. */
    std::vector<int> vetor = std::vector<int>(100, 1);

    /* `omp_get_wtime`: retorna, em formato de double, a hora UNIX atual; arma-
    zena o resultado em uma variável double, `t0` que é o timestamp inicial,
    antes do início do loop. */
    double t0 = omp_get_wtime();

    /* b) Escreva um loop sequencial que soma todos os elementos. */
    /* Entra em um loop forEach: declara uma variável de tipo inteiro, e a usa
    para cada item no vetor */
    for (int item : vetor)
        /* Para cada iteração do loop, soma-se à soma o valor do item. */
        soma += item;
    
    /* Obtém-se o segundo timestamp, logo após o fim do loop. */
    double t1 = omp_get_wtime();

    /* Obtém-se o tempo total de execução do loop, que é a diferença entre os
    dois timestamps */
    double tempo = t1 - t0;

    /* Imprime-se o total da soma, além do tempo de execução do loop. */
    std::cout << "Soma: " << soma << "; Tempo de execução: "
    << tempo << std::endl;
}

void parallel_for() {
    // Similar à função anterior, mas adaptado para realizar a soma em paralelo
    // Diferenças estão na impressão do header e o nome da função.

    std::cout << "For paralelizado" << std::endl;

    int soma = 0;
    std::vector<int> vetor = std::vector<int>(100, 1);

    double t0 = omp_get_wtime();

    /* c) Refaça o loop com #pragma omp parallel for reduction(+:soma). */
    /* Entra em uma região de paralelismo para operação com loop for. A diretiva
    reduction faz uma operação de redução do resultado final com o operador es-
    pecificado, no caso o +, na variável especificada, no caso `soma`. */
    #pragma omp parallel for reduction(+:soma)
        for (int item : vetor) soma += item;

    double t1 = omp_get_wtime();

    double tempo = t1 - t0;

    std::cout << "Soma: " << soma << "; Tempo de execução: "
    << tempo << " segundos" << std::endl;
}

// Ponto de entrada para compilação. Deve se chamar `main` e retornar um inteiro
int main() {
    /* d) Compare os resultados e explique por que a diretiva reduction
    é necessária. */
    // Chama as funções definidas anteriormente
    sequential_for();
    parallel_for();
    /* Como o vetor tem tamanho pequeno, o overhead de criação, coordenação, e
    redução de resultado, o custo da paralelização é maior, o que torna o loop
    sequencial mais rápido. A diretiva `reduction` é necessária no loop parale-
    lizado pois agrega o resultado das somas parciais realizadas por cada
    thread. Como cada thread possui uma cópia privada de `soma`, as operações
    podem ser feitas em paralelo sem risco de condições de corrida ou perda de
    eficiência. Caso contrário, ou haveria condições de corrida, ou perda de e-
    ficiência, pois haveria um lock para cada acesso à variável. */

    // Retorno padrão da função. 0 em caso de sucesso, 1 em caso de falha.
    return 0;
}

#include <iostream>
#include <omp.h>

/* Exercício 1 — “Hello World” Paralelo
a) Crie uma região paralela com #pragma omp parallel.
b) Cada thread deve imprimir uma mensagem indicando seu número 
   (omp_get_thread_num()) e o total de threads (omp_get_num_threads()).
c) Configure o programa para rodar com 4 threads. */

void parallel_hello_world() {
    /* Declara e define a função `parallel_hello_world`, que não leva parâmetros
    e não retorna valor, e que imprime "Hello World" e o ID thread, junto com
    a quantidade de threads, no formato "Hello World da Thread número n de N" */

    // c) Configure o programa para rodar com 4 threads.
    /* `omp_set_num_threads`: determina a quantidade de threads a serem
    utilizadas no bloco de paralelismo. Têm como parâmetro um inteiro: o número
    de threads desejado, e não retorna valor */
    omp_set_num_threads(4);

    // a) Crie uma região paralela com #pragma omp parallel.
    /* pragma omp parallel:
     * pragma: determina o uso de uma regra
     * omp: biblioteca OpenMP
     * parallel: determina que o próximo bloco será executado em paralelo
    */
    #pragma omp parallel
    {
        /* b) Cada thread deve imprimir uma mensagem indicando seu número 
        (omp_get_thread_num()) e o total de threads (omp_get_num_threads()). */
        /* `omp_get_thread_num`: obtém o ID da thread relativo à quantidade de
        threads, tal que o primeiro índice é 0. Não possui parâmetros, e retorna
        um inteiro, que é o ID da thread; Soma-se 1 para que os índices
        começem em 1 */
        int id = omp_get_thread_num() + 1;
        /* `omp_get_num_threads`: obtém o total de threads usadas no bloco de
        paralelismo. Não possui parâmetros, e retorna um inteiro, que é o total
        de threads usadas no bloco; Como `omp_set_num_threads` foi usado com
        argumento 4, a função retornará 4 */
        int total = omp_get_num_threads();

        /* pragma omp critical: entra em um bloco crítico, que evita que threads
        acessem um recurso ao mesmo tempo. Assim, o bloco é executado uma vez
        por thread, o que evita condições de corrida; Foi usado para evitar
        erros de impressão */
        #pragma omp critical
        {
            /* Imprime (std::cout) "Hello World", junto com o ID da thread e o
            total de threads, além de um newline que limpa o buffer de saída
            (std::endl) */
            std::cout << "Hello World da Thread número "
                      << id << "de " << total << std::endl;
        }
    }
}

// Ponto de entrada para compilação. Deve se chamar `main` e retornar um inteiro
int main() {

    // Chama a função definida anteriormente
    parallel_hello_world();

    // Retorno padrão da função. 0 em caso de sucesso, 1 em caso de falha.
    return 0;
}


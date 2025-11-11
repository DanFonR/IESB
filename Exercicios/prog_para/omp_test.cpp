#include <iostream>
#include <format>
#include <omp.h>

int main(int argc, char const *argv[]) {
    int num_procs = omp_get_num_procs();
    int num_max_threads = omp_get_max_threads();

    std::cout << 
        "numero de processadores logicos: " << num_procs
        << std::endl
        << "numero de threads usaveis pelo openmp: " << num_max_threads
        << std::endl << std::endl;

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int total = omp_get_num_threads();

        #pragma omp critical
        std::cout << "thread " << thread_id << " de " << total << std::endl;
    }
    return 0;
}

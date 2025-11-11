#include <iostream>
#include <mpi.h>

#define NUM_TROCAS 10
#define P0_P1_TAG 0
#define P0 0
#define P1 1

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 2) {
        if (rank == 0)
            std::cerr << "Use exatamente 2 processos" << std::endl;

        MPI_Finalize();
        return 1;
    }

    int contador = 0;
    int count = 1;

    while (contador < 9) {
        if (rank == 0) {
            if (contador == 0)
                MPI_Send(&contador, count, MPI_INT, P1, P0_P1_TAG, MPI_COMM_WORLD);

            MPI_Recv(&contador, count, MPI_INT, P1, P0_P1_TAG,
                MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            std::cout << "Processo 0 recebeu " << contador++ << ", ";

            if (contador != 10) std::cout << "enviando " << contador;
            else std::cout << "finalizando";

            std::cout << std::endl;
            MPI_Send(&contador, count, MPI_INT, P1, P0_P1_TAG, MPI_COMM_WORLD);
        }
        else {
            MPI_Recv(&contador, count, MPI_INT, P0, P0_P1_TAG,
                     MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            std::cout << "Processo 1 recebeu " << contador++
            << ", enviando " << contador << std::endl;
            MPI_Send(&contador, count, MPI_INT, P0, P0_P1_TAG, MPI_COMM_WORLD);

        }
    }

    MPI_Finalize();
    return 0;
}
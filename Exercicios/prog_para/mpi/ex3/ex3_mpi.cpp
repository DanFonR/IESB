#include <iostream>
#include <mpi.h>

#define ERR_SUCC 0
#define ERR_FAIL 1

#define TOK_PASS 0

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        if (rank == 0)
            std::cerr << "Requer ao menos 2 processos" << std::endl;

        MPI_Finalize();
        return ERR_FAIL;
    }

    if (rank == 0) {
        int token = 100;

        std::cout << "Processo 0 inicia o anel com o token = "
        << token << std::endl;

        MPI_Send(&token, 1, MPI_INT, rank + 1, TOK_PASS, MPI_COMM_WORLD);

        MPI_Recv(&token, 1, MPI_INT, size - 1, TOK_PASS,
            MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        std::cout << "Processo 0 recebeu o token de volta do processo "
        << size - 1 << ". Anel completo" << std::endl;
    }
    else {
        int tok_princ = 0;
        int orig = (rank - 1 + size) % size;
        int dest = (rank + 1) % size;

        MPI_Recv(&tok_princ, 1, MPI_INT, orig, TOK_PASS,
            MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        std::cout << "Processo " << rank << " recebeu o token = "
        << tok_princ << std::endl;

        MPI_Send(&tok_princ, 1, MPI_INT, dest, TOK_PASS, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return ERR_SUCC;
}

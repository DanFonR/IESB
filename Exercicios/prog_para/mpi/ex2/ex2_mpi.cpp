#include <iostream>
#include <mpi.h>
#include <vector>

#define ERR_SUCC 0
#define ERR_FAIL 1

#define SUM_PARC_PARC_TAG 0
#define SUM_PARC_RES_TAG 1

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

    const int TAMANHO_TOTAL = 1200;
    int parcela = TAMANHO_TOTAL / (size - 1);

    if (rank == 0) {
        if (TAMANHO_TOTAL % (size - 1) != 0) {
            std::cerr << "O vetor de tamanho " << TAMANHO_TOTAL
            << " nao eh divisivel entre " << size << "processos" << std::endl;
            MPI_Abort(MPI_COMM_WORLD, ERR_FAIL);
        }

        std::vector<int> vetor_mestre(TAMANHO_TOTAL, 1);

        int soma = 0;

        std::cout << "P0: Dividindo trabalho entre " << size - 1 << " processos"
        << std::endl;

        for (int i = 1; i < size; i++) {
            int indice = (i - 1) * parcela;
            std::cout << "P" << rank << ": Enviando para P" << i << std::endl;
            MPI_Send(&vetor_mestre[indice], parcela, MPI_INT, i,
            SUM_PARC_PARC_TAG, MPI_COMM_WORLD);
            std::cout << "P" << rank << ": Dados do vetor enviado a P" << i << std::endl;
        }

        std::cout << "P0: Enviado, esperando somas..." << std::endl;

        for (int i = 1; i < size; i++) {
            int parcial = 0;
            MPI_Recv(&parcial, 1, MPI_INT, i,
            SUM_PARC_RES_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            soma += parcial;
        }

        std::cout << "P0: Somas recebidas; Resultado: " << soma << std::endl;
    }
    else {
        int parc_soma = 0;
        std::vector<int> vec_worker(parcela, 0);

        std::cout << "P" << rank << ": Esperando vetor..."
        << std::endl;

        MPI_Recv(vec_worker.data(), parcela, MPI_INT, 0,
        SUM_PARC_PARC_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        std::cout << "P" << rank << ": Vetor recebido. Somando..."
        << std::endl;

        for (int dado : vec_worker)
            parc_soma += dado;

        std::cout << "P" << rank << ": Vetor somado. Enviando soma parcial..."
        << std::endl;

        MPI_Send(&parc_soma, 1, MPI_INT, 0, SUM_PARC_RES_TAG, MPI_COMM_WORLD);

        std::cout << "P" << rank << ": Soma parcial enviada..."
        << std::endl;
    }

    MPI_Finalize();
    return ERR_SUCC;
}

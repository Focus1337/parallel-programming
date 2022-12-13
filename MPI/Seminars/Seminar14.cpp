#include "Seminars.h"
#include "mpi.h"
#include <stdio.h>
#include <cstdlib>

#define SIZE 100

namespace Seminars {
    void DataInit(int *x, int N) {
        for (auto i = 0; i < N; ++i) {
            x[i] = (rand() % 1000);
        }
    }

    void Seminar14::Task42(int argc, char **argv) {
        // Initialize the MPI environment
        MPI_Init(&argc, &argv);

        // Get the number of processes
        int world_size;
        MPI_Comm_size(MPI_COMM_WORLD, &world_size);

        // Get the rank of the process
        int world_rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

        int gsize, sendarray[SIZE];
        int root = 0, *recvbuf;

        DataInit(sendarray, SIZE);

        MPI_Comm_size(MPI_COMM_WORLD, &gsize);
        recvbuf = (int *) malloc(gsize * SIZE * sizeof(int));
        MPI_Gather(sendarray, SIZE, MPI_INT, recvbuf, SIZE, MPI_INT, root, MPI_COMM_WORLD);

        if (world_rank == 0)
            for (int i = 0; i < SIZE; ++i)
                printf("%i\n", recvbuf[i]);

        // Finalize the MPI environment.
        MPI_Finalize();
    }

    void Seminar14::Task411(int argc, char **argv) {
        // Initialize the MPI environment
        MPI_Init(&argc, &argv);

        // Get the number of processes
        int world_size;
        MPI_Comm_size(MPI_COMM_WORLD, &world_size);

        // Get the rank of the process
        int world_rank;
        MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

        int gsize, sendarray[100];
        int root = 0, *recvbuf;

        int size = 100 / world_size;

        DataInit(sendarray, 100);

        MPI_Comm_size(MPI_COMM_WORLD, &gsize);
        recvbuf = (int *) malloc(gsize * size * sizeof(int));

        MPI_Scatter(sendarray, size, MPI_INT, recvbuf, size, MPI_INT, root, MPI_COMM_WORLD);

        for (int i = 0; i < size; ++i)
            printf("[CPU%i]: %i\n", world_rank, recvbuf[i]);

        // Finalize the MPI environment.
        MPI_Finalize();
    }
}
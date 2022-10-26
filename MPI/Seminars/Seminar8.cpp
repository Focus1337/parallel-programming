#include "Seminars.h"
#include <stdio.h>
#include "mpi.h"

using namespace std;

namespace Seminars {

    void Seminar8::Example1(int *argc, char **argv) {
        int numtask, rank;

        MPI_Init(argc, &argv);

        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &numtask);

        printf("Hello", rank, numtask);

        MPI_Finalize();
    }
}
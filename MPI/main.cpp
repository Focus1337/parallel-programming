#include "Homeworks/Homeworks.h"
#include "Seminars/Seminars.h"

#include "mpi.h"
#include <stdio.h>

using namespace Homeworks;
using namespace Seminars;

//int main(int *argc, char **argv) {
//    Seminar8::Example1(argc, argv);
//}

int main(int *argc, char **argv) {
    int numtask, rank;

    MPI_Init(argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &numtask);

    printf("Hello", rank, numtask);

    MPI_Finalize();
}
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
    int rank;
    MPI_Status status;
    MPI_Init(argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int a[5];
    a[0] = 10;
    a[1] = rank;
    if (rank == 1)
        MPI_Send(&a[1], 1, MPI_INT, 0, 99, MPI_COMM_WORLD);
    else {
        MPI_Recv(&a[0], 1, MPI_INT, 1, 99, MPI_COMM_WORLD, &status);
        printf("%i", a[0]);
    }
    MPI_Finalize();
}
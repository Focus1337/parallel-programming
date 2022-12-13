#include "mpi.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>

#include "Seminars.h"

using namespace Seminars;
using namespace std;

namespace Seminars {

    double fRand(double fMin, double fMax) {
        double f = (double) rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }

    void DataInitialization(double *x, int N) {
        for (int i = 0; i < N; i++) {
            x[i] = fRand(1, 100);
        }
    }


    void Seminar13::Execute(int argc, char *argv[]) {
        double x[100], TotalSum, ProcSum = 0.0;
        int ProcRank, ProcNum, N = 10;
        MPI_Status Status;
//  инициализация
        MPI_Init(&argc, &argv);
        MPI_Comm_size(MPI_COMM_WORLD, &ProcNum);
        MPI_Comm_rank(MPI_COMM_WORLD, &ProcRank);
// подготовка данных
        if (ProcRank == 0)
            DataInitialization(x, N);

        cout << "Array: ";
        for (int i = 0; i < N; i++)
            cout << x[i] << " ";

// рассылка данных на все процессы
        MPI_Bcast(x, N, MPI_DOUBLE, 0, MPI_COMM_WORLD);
// вычисление частичной суммы на каждом из процессов
// на каждом процессе суммируются элементы вектора x от i1 до i2
        int k = N / ProcNum;
        int i1 = k * ProcRank;
        int i2 = k * (ProcRank + 1);
        if (ProcRank == ProcNum - 1) i2 = N;
        for (int i = i1; i < i2; i++)
            ProcSum = ProcSum + x[i];

        // сборка частичных сумм на процессе с рангом 0
        if (ProcRank == 0) {
            TotalSum = ProcSum;
            for (int i = 1; i < ProcNum; i++) {
                MPI_Recv(&ProcSum, 1, MPI_DOUBLE, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD,
                         &Status);
                TotalSum = TotalSum + ProcSum;
            }
        } else // все процессы отсылают свои частичные суммы
            MPI_Send(&ProcSum, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);

        // вывод результата
        if (ProcRank == 0)
            printf("\nTotal Sum = %10.2f", TotalSum);
        MPI_Finalize();
    }
}
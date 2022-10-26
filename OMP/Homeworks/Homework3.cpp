#include <chrono>
#include <iostream>
#include <omp.h>
#include <vector>
#include <random>
#include <iterator>
#include "Homeworks.h"

using namespace std;
using namespace chrono;

namespace Homeworks {
    // Функция параллельного матричного умножения
    void Homework3::ParallelCalculationBasic(double *pAMatrix, double *pBMatrix, double *pCMatrix, int Size) {
        int i, j, k;
#pragma omp parallel for private (j, k)
        for (i = 0; i < Size; i++)
            for (j = 0; j < Size; j++)
                for (k = 0; k < Size; k++) {
//                    printf("Iteration k: %d \n", k);
                    pCMatrix[i * Size + j] += pAMatrix[i * Size + k] * pBMatrix[k * Size + j];
                }
    }

    // Функция параллельного матричного умножения
    void Homework3::ParallelCalculationTapeSeparation(double *pAMatrix, double *pBMatrix, double *pCMatrix, int Size) {
        int i, j, k;
        int NestedThreadsNum = 2;
        omp_set_nested(true);
        omp_set_num_threads(NestedThreadsNum);
#pragma omp parallel for private (j, k)
        for (i = 0; i < Size; i++)
#pragma omp parallel for private (k)
                for (j = 0; j < Size; j++)
                    for (k = 0; k < Size; k++)
                        pCMatrix[i * Size + j] += pAMatrix[i * Size + k] * pBMatrix[k * Size + j];
    }

// Функция параллельного блочного умножения матриц
    void Homework3::ParallelCalculationBlock(double *pAMatrix, double *pBMatrix, double *pCMatrix, int Size) {
        int BlockSize = 250;
        int GridSize = int(Size / double(BlockSize));
#pragma omp parallel for
        for (int n = 0; n < GridSize; n++)
            for (int m = 0; m < GridSize; m++)
                for (int iter = 0; iter < GridSize; iter++)
                    for (int i = n * BlockSize; i < (n + 1) * BlockSize; i++)
                        for (int j = m * BlockSize; j < (m + 1) * BlockSize; j++)
                            for (int k = iter * BlockSize; k < (iter + 1) * BlockSize; k++)
                                pCMatrix[i * Size + j] += pAMatrix[i * Size + k] * pBMatrix[k * Size + j];
    }


// Функция выделения памяти и инициализации данных
    void ProcessInitialization(double *&pAMatrix, double *&pBMatrix, double *&pCMatrix, int &Size) {
        int i, j;
        do {
//            printf("\nВведите размер матриц: ");
            scanf("%d", &Size);
            if (Size <= 0) { printf("Размер должен быть больше 0! \n "); }
        } while (Size <= 0);
        pAMatrix = new double[Size * Size];
        pBMatrix = new double[Size * Size];
        pCMatrix = new double[Size * Size];
        for (i = 0; i < Size; i++) for (j = 0; j < Size; j++) pCMatrix[i * Size + j] = 0;
//    RandomDataInitialization(pAMatrix, pBMatrix, Size);

        random_device rd;
        default_random_engine eng(rd());
        uniform_int_distribution<int> dist(0, 100);

        for (int r = 0; r < Size; r++)
            pAMatrix[r] = dist(eng);

        for (int k = 0; k < Size; k++)
            pBMatrix[k] = dist(eng);
    }

    void Homework3::SequentiallyCalculation(double *pAMatrix, double *pBMatrix, double *pCMatrix, int Size) {
        int i, j, k;
        for (i = 0; i < Size; i++)
            for (j = 0; j < Size; j++)
                for (k = 0; k < Size; k++)
                    pCMatrix[i * Size + j] += pAMatrix[i * Size + k] * pBMatrix[k * Size + j];
    }

    void Homework3::Execute() {
        int size = 0;
        double *pAMatrix; // Матрица А
        double *pBMatrix; // Матрица B
        double *pCMatrix; // Матрица С

        ProcessInitialization(pAMatrix, pBMatrix, pCMatrix, size);

        auto t1 = high_resolution_clock::now();
        SequentiallyCalculation(pAMatrix, pBMatrix, pCMatrix, size);
        auto t2 = high_resolution_clock::now();
        duration<double, milli> ms_double1 = t2 - t1;
        printf("\nSequentially: %f ms \n", ms_double1.count());


        auto t3 = high_resolution_clock::now();
        ParallelCalculationBasic(pAMatrix, pBMatrix, pCMatrix, size);
        auto t4 = high_resolution_clock::now();
        duration<double, milli> ms_double2 = t4 - t3;
        printf("N: %d. First. Time: %f ms. Boost: %f\n", size, ms_double2.count(), (ms_double1.count() / ms_double2.count()));

        auto t5 = high_resolution_clock::now();
        ParallelCalculationTapeSeparation(pAMatrix, pBMatrix, pCMatrix, size);
        auto t6 = high_resolution_clock::now();
        duration<double, milli> ms_double3 = t6 - t5;
        printf("N: %d. Second. Time: %f ms. Boost: %f\n", size, ms_double3.count(), (ms_double1.count() / ms_double3.count()));

        auto t7 = high_resolution_clock::now();
        ParallelCalculationBlock(pAMatrix, pBMatrix, pCMatrix, size);
        auto t8 = high_resolution_clock::now();
        duration<double, milli> ms_double4 = t8 - t7;
        printf("N: %d. Third. Time: %f ms. Boost: %f\n", size, ms_double4.count(),
               (ms_double1.count() / ms_double4.count()));
    }
}
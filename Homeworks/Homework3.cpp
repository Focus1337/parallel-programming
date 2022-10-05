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
                for (k = 0; k < Size; k++)
                    pCMatrix[i * Size + j] += pAMatrix[i * Size + k] * pBMatrix[k * Size + j];
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
}
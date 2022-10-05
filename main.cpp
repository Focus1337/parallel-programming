#include <cstdio>
#include "Homeworks/Homeworks.h"
#include "Seminars/Seminars.h"

using namespace Homeworks;
using namespace Seminars;

// Функция выделения памяти и инициализации данных
void ProcessInitialization(double *&pAMatrix, double *&pBMatrix, double *&pCMatrix, int &Size) {
    int i, j;
    do {
        printf("\nВведите размер матриц: ");
        scanf("%d", &Size);
        if (Size <= 0) { printf("Размер должен быть больше 0! \n "); }
    } while (Size <= 0);
    pAMatrix = new double[Size * Size];
    pBMatrix = new double[Size * Size];
    pCMatrix = new double[Size * Size];
    for (i = 0; i < Size; i++) for (j = 0; j < Size; j++) pCMatrix[i * Size + j] = 0;
    RandomDataInitialization(pAMatrix, pBMatrix, Size);
}

int main() {
//    Homework1::FirstParallelProgram();
//    Homework2::Execute();

    int size = 10;
    double *pAMatrix; // Матрица А
    double *pBMatrix; // Матрица B
    double *pCMatrix; // Матрица С

    ProcessInitialization(pAMatrix, pBMatrix, pCMatrix, size);

    Homework3::ParallelCalculationBasic(pAMatrix, pBMatrix, pCMatrix, size);
    Homework3::ParallelCalculationTapeSeparation(pAMatrix, pBMatrix, pCMatrix, size);
    Homework3::ParallelCalculationBlock(pAMatrix, pBMatrix, pCMatrix, size);

//    Seminar3::Execute();
//    Seminar4::Execute();

//    Seminar5::Execute();
}
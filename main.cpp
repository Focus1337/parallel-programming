#include <chrono>
#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <omp.h>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;
using namespace chrono;

void Seminar4() {

#pragma omp parallel for collapse(2)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "i: " + to_string(i) + " j: " + to_string(j) + "\n" +
                    "thread num: " + to_string(omp_get_thread_num()) + '\n' +
                    "num threads: " + to_string(omp_get_num_threads()) + '\n' + '\n';
        }
    }
}

void Example() {
    /* Комменты здесь
     *  C+- ПРИМЕРНЫЙ ЯЗЫК ПРОГРАММИРОВАНИЯ
     *  нихуя не понял за пару
     *  во всем виновата алсу
     *  +
     *  а
     *  и tessa violetну иы видишь
     *  что за буллинг такой
     *  там чат есть
     *  посмотри под камерой
     *
     *  что посмотреть?
    */
    int elemCount = 10;
    int A[elemCount], B[elemCount], C[elemCount], i, n;
    for (i = 0; i < elemCount; i++) {
        A[i] = i;
        B[i] = 2 * i;
        C[i] = 0;
    }

#pragma omp parallel shared(A, B, C) private(i, n)
    {
        /* Получим номер текущей нити */
        n = omp_get_thread_num();
#pragma omp for
        for (i = 0; i < elemCount; i++) {
            C[i] = A[i] + B[i];
            printf("Нить %d сложила элементы с номером %d\n", n, i);
        }
    }
}

int main() {
    // сложение векторов
//    VectorsAdditionParallel();
//    VectorsAddition();

    // умножение матриц
//    MatrixCalc();
//    MatrixCalcParallel();

//    Seminar3();
//    Example2();
//    Example4();
//    Example5();

//    Seminar4();
    Example();
}
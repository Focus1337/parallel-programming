#include <chrono>
#include <iostream>
#include <omp.h>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;
using namespace chrono;

const int N = 10;

/// перемножение матриц - последовательно
void MatrixCalc() {
    setlocale(LC_ALL, "Russian");

    int matrixA[N][N];
    int matrixB[N][N];
    int matrixC[N][N];

    auto t1 = high_resolution_clock::now();

    cout << "Sequential matrix multiplication \n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++) {
                matrixC[i][j] = matrixA[i][k] * matrixB[k][j];
            }
    }
    cout << "Done \n";

    auto t2 = high_resolution_clock::now();
    /* Getting number of milliseconds as a double. */
    duration<double, milli> ms_double = t2 - t1;

    cout << ms_double.count() << "ms\n";
}

/// пременожение матриц - параллельно
void MatrixCalcParallel() {
    setlocale(LC_ALL, "Russian");

    int matrixA[N][N];
    int matrixB[N][N];
    int matrixC[N][N];

    auto t1 = high_resolution_clock::now();

    cout << "Параллельное выполнение умножения матриц \n";
    cout << "Кол-во доступных процессоров: " + to_string(omp_get_num_procs()) + "\n";
    cout << "На сколько процессов распаралелился" << "\n";
#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                matrixC[i][j] = matrixA[i][k] * matrixB[k][j];

                auto count = "Номер потока: " + to_string(omp_get_thread_num()) + "\n";
                auto num = "Кол-во потоков в группе: " + to_string(omp_get_num_threads()) + "\n";
                cout << count << num;
            }
        }
    }

    auto t2 = high_resolution_clock::now();
    /* Getting number of milliseconds as a double. */
    duration<double, milli> ms_double = t2 - t1;

    cout << ms_double.count() << "ms\n";
}
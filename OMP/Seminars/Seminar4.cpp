#include <chrono>
#include <iostream>
#include <omp.h>
#include <vector>
#include <iterator>
#include "Seminars.h"

using namespace std;
using namespace chrono;


namespace Seminars {
    void Seminar4::Example1() {

#pragma omp parallel for collapse(2)
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 2; j++) {
                cout << "i: " + to_string(i) + " j: " + to_string(j) + "\n" +
                        "thread num: " + to_string(omp_get_thread_num()) + '\n' +
                        "num threads: " + to_string(omp_get_num_threads()) + '\n' + '\n';
            }
        }
    }

    void Seminar4::Example2() {
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

    void Seminar4::Execute() {
        Example1();
        Example2();
    }
}
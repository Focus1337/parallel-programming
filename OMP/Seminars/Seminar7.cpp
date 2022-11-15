#include <chrono>
#include <iostream>
#include <omp.h>
#include <vector>
#include <iterator>
#include "Seminars.h"

using namespace std;
using namespace chrono;

namespace Seminars {

    void Seminar7::Example1() {
#pragma omp parallel
        {
            printf("Сообщение 1\n");
#pragma omp single nowait
            {
                printf("Одна нить\n");
            }
            printf("Сообщение 2\n");
        }
    }

    void Seminar7::Example2() {
        int n;
#pragma omp parallel private(n)
        {
            n = omp_get_thread_num();
            printf("Значение n (начало): %d\n", n);
#pragma omp single copyprivate(n)
            {
                n = 100;
            }
            printf("Значение n (конец): %d\n", n);
        }
    }

    void Seminar7::Example3() {
        int n;
#pragma omp parallel private(n)
        {
            n = 1;
#pragma omp master
            {
                n = 2;
            }
            printf("Первое значение n: %d\n", n);
#pragma omp barrier
#pragma omp master
            {
                n = 3;
            }
            printf("Второе значение n: %d\n", n);
        }
    }

    void Seminar7::Execute() {
//        Example1();
//        Example2();
        Example3();
    }
}
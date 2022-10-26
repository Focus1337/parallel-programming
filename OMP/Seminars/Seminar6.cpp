#include <chrono>
#include <iostream>
#include <omp.h>
#include <vector>
#include <iterator>
#include "Seminars.h"

using namespace std;
using namespace chrono;

namespace Seminars {

    void Seminar6::Example1() {
        int count = 0;
#pragma omp parallel reduction (+: count)
        {
            count++;
            printf("Текущее значение count: %d\n", count);
        }
        printf("Число нитей: %d\n", count);
    }

    void Seminar6::Example2() {
        int n;
#pragma omp parallel
        {
#pragma omp critical
            {
                n = omp_get_thread_num();
                printf("Нить %d\n", n);
            }
        }
    }

    void Seminar6::Example3() {
        int count = 0;
#pragma omp parallel
        {
#pragma omp atomic
            count++;
        }
        printf("Число нитей: %d\n", count);
    }

    void Seminar6::Execute() {
//        Example1();
//        Example2();
        Example3();
    }
}
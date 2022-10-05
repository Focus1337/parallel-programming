#include <chrono>
#include <iostream>
#include <omp.h>
#include <vector>
#include <iterator>
#include "Seminars.h"

using namespace std;
using namespace chrono;

namespace Seminars {

    void Seminar5::Example1() {
#pragma omp parallel for
        for (int i = 0; i < 4; i++)
            printf("i=%d\n", i);

#pragma omp parallel for
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 2; j++)
                printf("i=%d, j=%d\n", i, j);
    }

    void Seminar5::Example2() {
        printf("Значение OMP_DYNAMIC: %d\n", omp_get_dynamic());
        omp_set_dynamic(1);
        printf("Значение OMP_DYNAMIC: %d\n", omp_get_dynamic());
#pragma omp parallel num_threads(128)
        {
#pragma omp master
            {
                printf("Параллельная область, %d нитей\n",
                       omp_get_num_threads());
            }
        }

    }

    void Seminar5::Example3() {
        int n;
        omp_set_nested(1);
#pragma omp parallel private(n)
        {
            n = omp_get_thread_num();
#pragma omp parallel
            {
                printf("Часть 1, нить %d - %d\n", n,
                       omp_get_thread_num());
            }
        }

        omp_set_nested(0);
#pragma omp parallel private(n)
        {
            n = omp_get_thread_num();
#pragma omp parallel
            {
                printf("Часть 2, нить %d - %d\n", n,
                       omp_get_thread_num());
            }
        }
    }

    void Seminar5::Example4() {
        int n;
#pragma omp parallel private(n)
        {
            n = omp_get_thread_num();
#pragma omp sections
            {
#pragma omp section
                {
                    printf("1 %d\n", n);
                }
#pragma omp section
                {
                    printf("2 %d\n", n);
                }
#pragma omp section
                {
                    printf("3 %d\n", n);
                }
            }
            printf("part %d\n", n);
        }
    }

    void Task1() {
        int power = 10;
        int number = 0;

        for (int i = 0; i < power; i++)
            number *= number;
    }

    void Task2() {
        int n = 1;
        int number = 0;
        while (n < 21) {
            number += number * n;
            n++;
        }
    }

    void Task3() {
        int number = 0;

        while (number < 100)
            number += 5;
    }

    int Function1(int i) {
        int value = 0;

        if(i < 1) return 0;

        if(i == 1) return 1;

        return Function1(i-1) + Function1(i - 2);
    }

    void Seminar5::Example5() {
        int x = 10;
        int n;
#pragma omp for
        for (int i = 0; i < x; i++)
            printf("Fib: %d\n", Function1(i));

#pragma omp sections
        {
#pragma omp section
            {
                Task1();
                printf("thread num: %d\n", omp_get_thread_num());
            }
#pragma omp section
            {
                Task2();
                printf("thread num: %d\n", omp_get_thread_num());
            }
#pragma omp section
            {
                Task3();
                printf("thread num: %d\n", omp_get_thread_num());
            }
        }
    }

    void Seminar5::Execute() {
//        Example1();
//        Example2();
//        Example3();
//        Example4();
        Example5();
    }

}
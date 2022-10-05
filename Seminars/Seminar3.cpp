#include <chrono>
#include <iostream>
#include <omp.h>
#include <vector>
#include <iterator>
#include "Seminars.h"

using namespace std;
using namespace chrono;

namespace Seminars {
    void Seminar3::Example1() {
        printf("posledovatelniy1\n");
#pragma omp parallel
        {
            printf("parallel\n");
        }
        printf("posledovatelniy2\n");
    }


    void Seminar3::Example2() {
//    string hw = "Hello, world\n";
        int hw = 6;
#pragma omp parallel private(hw)
        cout << hw;
    }

    void Seminar3::Example3() {
        int x = 0;
#pragma omp parallel shared(x) num_threads(3000)
        {
            x += 1;
        }
        cout << "x = " << x << endl;
    }

    void Seminar3::Example4() {
        int n = 1;
        printf("n в последовательной области (начало): %d\n", n);
#pragma omp parallel private(n) num_threads(4)
        {
            printf("Значение n в потоке (на входе): %d\n", n);
            n = omp_get_thread_num();
            printf("Значение n в потоке (на выходе): %d\n", n);
        }
        printf("n в последовательной области (конец): %d\n", n);
    }


    void Seminar3::Execute() {
        Example1();
        Example2();
        Example3();
        Example4();
    }
}
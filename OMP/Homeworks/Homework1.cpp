#include <chrono>
#include <iostream>
#include <omp.h>

using namespace std;
using namespace chrono;
#include "Homeworks.h"

namespace Homeworks {
    void Homework1::FirstParallelProgram() {
        cout << "Available processors: " + to_string(omp_get_num_procs()) + "\n";
        int a[100], b[100], c[100], d[100];

        cout << "On how many processes paralleled" << "\n";
#pragma omp parallel for
        for (int i = 0; i < 100; i++)
        {
            a[i] = i;
            b[i] = i;
            d[i] = 2 * i;
            auto iteration = "iteration: " + to_string(i) + "\n";
            auto count = "Thread number: " + to_string(omp_get_thread_num()) + "\n";
            auto num = "Count of threads in group: " + to_string(omp_get_num_threads()) + "\n";
//        cout << count << num;
            cout << iteration.append(count).append(num);// + count + num;
//        cout << omp_get_thread_num();
//        cout << omp_get_num_threads();
        }

#pragma omp parallel for
        for (int i = 0; i < 100; i++)
            c[i] = a[i] + b[i] + d[i];

        cout << a[50] << "\n";
    }
} // Homeworks
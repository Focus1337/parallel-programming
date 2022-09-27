#include <chrono>
#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <omp.h>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
//#include "Seminar3.cpp"
//#include "HW2.cpp"

using namespace std;
using namespace chrono;

/// сложение векторов - параллельно
void VectorsAdditionParallel() {
    // First create an instance of an engine.
    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 mersenne_engine{rnd_device()};  // Generates random integers
    uniform_int_distribution<int> dist{1, 52};

    auto gen = [&dist, &mersenne_engine]() {
        return dist(mersenne_engine);
    };

    vector<int> vector1(100);
    vector<int> vector2(100);
    vector<int> vector3(100);
    vector3.reserve(vector1.size());

    generate(begin(vector1), end(vector1), gen);
    generate(begin(vector2), end(vector2), gen);

    double itime, ftime, exec_time;
    itime = omp_get_wtime();

    cout << "Параллельное выполнение\n";
#pragma omp parallel for
    for (int i = 0; i < vector1.size(); i++) {
        vector3[i] = vector1[i] + vector2[i];

        auto count = "Thread number: " + to_string(omp_get_thread_num()) + "\n";
        auto num = "Count of threads in group: " + to_string(omp_get_num_threads()) + "\n";
        cout << count << num;
    }

    ftime = omp_get_wtime();
    exec_time = ftime - itime;
    printf("\nTime taken is %f ms \n\n", exec_time);


//    cout << "Vector 3 values:\n";
//    for (int i = 0; i < vector3.size(); i++) {
//        cout << to_string(i) + ": " + to_string(vector1[i]) + "\n";
//    }
}

/// сложение векторов - последовательно
void VectorsAddition() {
    // First create an instance of an engine.
    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 mersenne_engine{rnd_device()};  // Generates random integers
    uniform_int_distribution<int> dist{1, 52};

    auto gen = [&dist, &mersenne_engine]() {
        return dist(mersenne_engine);
    };

    vector<int> vector1(100);
    vector<int> vector2(100);
    vector<int> vector3(100);
    vector3.reserve(vector1.size());

    generate(begin(vector1), end(vector1), gen);
    generate(begin(vector2), end(vector2), gen);

    auto t1 = high_resolution_clock::now();

    cout << "Последовательное выполнение\n";
    for (int i = 0; i < vector1.size(); i++) {
        vector3[i] = vector1[i] + vector2[i];
    }

    auto t2 = high_resolution_clock::now();
    /* Getting number of milliseconds as a double. */
    duration<double, milli> ms_double = t2 - t1;
    printf("\nTime taken is %f ms \n\n", ms_double.count());

//    cout << "Vector 3 values:\n";
//    for (int i = 0; i < vector3.size(); i++) {
//        cout << to_string(i) + ": " + to_string(vector1[i]) + "\n";
//    }
}

int main() {
    // сложение векторов
    VectorsAdditionParallel();
    VectorsAddition();
    // последовательное умножение
//    MatrixCalc();
    // параллельное умножение
//    MatrixCalcParallel();

//    Seminar3();
//    Example2();
//    Example4();
//    Example5();
}
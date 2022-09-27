#include <chrono>
#include <iostream>
#include <omp.h>
using namespace std;
using namespace chrono;

void Seminar3() {
    printf("posledovatelniy1\n");
#pragma omp parallel
    {
        printf("parallel\n");
    }
    printf("posledovatelniy2\n");
}


void Example2 () {
//    string hw = "Hello, world\n";
    int hw = 6;
#pragma omp parallel private(hw)
    cout << hw;
}

void Example4()
{
    int x = 0;
#pragma omp parallel shared(x) num_threads(3000)
    {
        x += 1;
    }
    cout << "x = " << x << endl;
}

void Example5()
{
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
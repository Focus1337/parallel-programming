#include <chrono>
#include <iostream>
#include <omp.h>
#include <vector>
#include <iterator>
#include "Seminars.h"

using namespace std;
using namespace chrono;

namespace Seminars {
    template<class T>
    T *Seminar11::QuickSort(T *array, const long lastElementIndex) {
        long i = 0, j = lastElementIndex - 1;
        T pivot = array[lastElementIndex / 2];
        do {
            while (array[i] < pivot) {
                i++;
            }
            while (array[j] > pivot) {
                j--;
            }
            if (i <= j) {
                std::swap(array[i], array[j]);
                i++;
                j--;
            }
        } while (i <= j);
#pragma omp task shared(array)
        {
            if (j > 0) {
                QuickSort(array, j + 1);
            }
        }
#pragma omp task shared(array)
        {
            if (lastElementIndex > i) {
                QuickSort(array + i, lastElementIndex - i);
            }
        }
#pragma omp taskwait

        return array;
    }

    void Seminar11::Execute(int arraySize) {
        int array[arraySize];

        cout << "\nUnsorted array\n";
        for (auto item: array) {
            cout << item << " ";
        }

        auto sortedArray = QuickSort(array, arraySize);

        cout << "\n\nSorted array\n";
        for (int i = 0; i < 10; i++)
            cout << sortedArray[i] << " ";
    }
}
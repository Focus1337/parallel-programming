#include "Homeworks/Homeworks.h"
#include "Seminars/Seminars.h"

#include "mpi.h"
#include <stdio.h>
#include <cstdlib>
#include <iostream>

using namespace Homeworks;
using namespace Seminars;
using namespace std;

void DataInitialization(int *x, int N) {
    for (int i = 0; i < N; i++) {
        x[i] = (rand() % 10);
    }
}

int main(int argc, char *argv[]) {

}


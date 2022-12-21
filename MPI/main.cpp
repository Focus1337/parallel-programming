#include "Homeworks/Homeworks.h"
#include "Seminars/Seminars.h"
#include <windows.h>

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace Homeworks;
using namespace Seminars;
using namespace std;


int main() {
    SetConsoleOutputCP(CP_UTF8);

    // Тестовая СЛУ:
    // A=[3,1,1], B=[5,6,4,-3], C=[3,1,-2],
    // D=[8,10,3,-2] и вектор решения X=[1,1,1,1]

    // B - главная диагональ матрицы (нумеруется: [0;n-1])
    // A - диагональ, лежащая под главной (нумеруется: [1;n-1])
    // C - диагональ, лежащая над главной (нумеруется: [0;n-2])
    // D - правая часть (столбец независимых констант)

    // Размер матрицы (число уравнений, строк матрицы)
    int n;
    cout << "Ввод числа уравнений n" << endl;
    cout << "Введите n: ";
    cin >> n;
    cout << endl;

    // Векторы решения A, B, C, D
    // коэффициенты "P" и "Q"
    // а также вектор решений x
    auto *A = new double[n];
    auto *B = new double[n];
    auto *C = new double[n];
    auto *D = new double[n];
    auto *p = new double[n];
    auto *q = new double[n];
    auto *x = new double[n];

    // Ввод векторов A, B, C, D
    cout << "Ввод векторов A, B, C, D" << endl;
    for (int k = 1; k < n; k++) {
        cout << "Введите А: ";
        cin >> A[k];
    }
    for (int k = 0; k < n; k++) {
        cout << "Введите B: ";
        cin >> B[k];
    }
    for (int k = 0; k < n - 1; k++) {
        cout << "Введите C: ";
        cin >> C[k];
    }
    for (int k = 0; k < n; k++) {
        cout << "Введите D: ";
        cin >> D[k];
    }
    cout << endl;

    // Вывод векторов A, B, C, D для контроля
    cout << "Вектор A" << endl;
    for (int k = 0; k < n; k++) {
        cout << setprecision(5) << A[k] << endl;
    }
    cout << endl;
    cout << "Вектор B" << endl;
    for (int k = 0; k < n; k++) {
        cout << setprecision(5) << B[k] << endl;
    }
    cout << endl;
    cout << "Вектор C" << endl;
    for (int k = 0; k < n; k++) {
        cout << setprecision(5) << C[k] << endl;
    }
    cout << endl;
    cout << "Вектор D" << endl;
    for (int k = 0; k < n; k++) {
        cout << setprecision(5) << D[k] << endl;
    }
    cout << endl;

    // Краевые условия
    p[0] = C[0] / B[0];
    q[0] = D[0] / B[0];
    p[n - 1] = 0.0;
    q[n - 1] = 0.0;

    // Прямой проход
    for (int k = 1; k < n; k++) {
        p[k] = C[k] / (B[k] - A[k] * p[k - 1]);
        q[k] = (D[k] - A[k] * q[k - 1]) / (B[k] - A[k] * p[k - 1]);
    }

    // Обратный проход
    x[n - 1] = q[n - 1];
    for (int k = n - 2; k >= 0; k--) {
        x[k] = q[k] - p[k] * x[k + 1];
    }
    cout << endl;

    // Вывод результатов решения
    cout << "Вектор решения X" << endl;
    for (int k = 0; k < n; k++) {
        cout << setprecision(5) << x[k] << endl;
    }
}
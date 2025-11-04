#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int** Q, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0);
void Print(int** Q, const int rowCount, const int colCount, int i = 0, int j = 0);
void CalcAndReplace(int** Q, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0);
void SortCols(int** Q, const int rowCount, const int colCount, int j1 = 0, int j2 = 0);
void SwapCols(int** Q, const int rowCount, int col1, int col2, int i = 0);

int main() {
    srand((unsigned)time(NULL));

    const int rowCount = 8;
    const int colCount = 6;
    const int Low = -26;
    const int High = 23;

    int** Q = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        Q[i] = new int[colCount];

    // Створення матриці
    Create(Q, rowCount, colCount, Low, High);
    cout << "Initial matrix Q:\n";
    Print(Q, rowCount, colCount);

    // Сортування матриці
    SortCols(Q, rowCount, colCount);
    cout << "Matrix after sorting columns:\n";
    Print(Q, rowCount, colCount);

    // Обчислення та заміна
    int S = 0, k = 0;
    CalcAndReplace(Q, rowCount, colCount, S, k);
    cout << "Modified matrix after applying the criterion:\n";
    Print(Q, rowCount, colCount);
    cout << "Criterion: all except positive even numbers\n";
    cout << "Sum = " << S << endl;
    cout << "Count = " << k << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] Q[i];
    delete[] Q;

    return 0;
}

// створення
void Create(int** Q, const int rowCount, const int colCount, const int Low, const int High, int i, int j) {
    if (i >= rowCount) return;
    Q[i][j] = Low + rand() % (High - Low + 1);
    if (j < colCount - 1) Create(Q, rowCount, colCount, Low, High, i, j + 1);
    else Create(Q, rowCount, colCount, Low, High, i + 1, 0);
}

// виведення
void Print(int** Q, const int rowCount, const int colCount, int i, int j) {
    if (i >= rowCount) {
        cout << endl;
        return;
    }
    cout << setw(6) << Q[i][j];
    if (j < colCount - 1) Print(Q, rowCount, colCount, i, j + 1);
    else {
        cout << endl;
        Print(Q, rowCount, colCount, i + 1, 0);
    }
}

// обчислення і заміна 
void CalcAndReplace(int** Q, const int rowCount, const int colCount, int& S, int& k, int i, int j) {
    if (i >= rowCount) return;
    if (!(Q[i][j] > 0 && Q[i][j] % 2 == 0)) {
        S += Q[i][j];
        k++;
        Q[i][j] = 0;
    }
    if (j < colCount - 1) CalcAndReplace(Q, rowCount, colCount, S, k, i, j + 1);
    else CalcAndReplace(Q, rowCount, colCount, S, k, i + 1, 0);
}

// сортування за ключами (→ ← →)
void SortCols(int** Q, const int rowCount, const int colCount, int j1, int j2) {
    if (j1 >= colCount - 1) return;
    if (j2 < colCount - j1 - 1) {
        if (
            (Q[0][j2] > Q[0][j2 + 1]) ||
            (Q[0][j2] == Q[0][j2 + 1] && Q[1][j2] < Q[1][j2 + 1]) ||
            (Q[0][j2] == Q[0][j2 + 1] &&
                Q[1][j2] == Q[1][j2 + 1] &&
                Q[2][j2] > Q[2][j2 + 1])
            )
            SwapCols(Q, rowCount, j2, j2 + 1);
        SortCols(Q, rowCount, colCount, j1, j2 + 1);
    }
    else {
        SortCols(Q, rowCount, colCount, j1 + 1, 0);
    }
}

// обмін стовпців
void SwapCols(int** Q, const int rowCount, int col1, int col2, int i) {
    if (i >= rowCount) return;
    int tmp = Q[i][col1];
    Q[i][col1] = Q[i][col2];
    Q[i][col2] = tmp;
    SwapCols(Q, rowCount, col1, col2, i + 1);
}

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;


void Create(int** Q, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** Q, const int rowCount, const int colCount);
void CalcAndReplace(int** Q, const int rowCount, const int colCount, int& S, int& k);
void SortCols(int** Q, const int rowCount, const int colCount);
void SwapCols(int** Q, const int rowCount, int col1, int col2);

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

    // сортуємо матрицю
    SortCols(Q, rowCount, colCount);
    cout << "\nMatrix after sorting columns:\n";
    Print(Q, rowCount, colCount);

    // застосовуємо критерій (заміна на нулі)
    int S = 0, k = 0;
    CalcAndReplace(Q, rowCount, colCount, S, k);

    cout << "Modified matrix after applying the criterion:\n";
    Print(Q, rowCount, colCount);
    cout << "Criterion: all except positive even numbers\n";
    cout << "Sum = " << S << endl;
    cout << "Count = " << k << endl;

    // Очищення пам’яті
    for (int i = 0; i < rowCount; i++)
        delete[] Q[i];
    delete[] Q;

    return 0;
}

// Формування матриці 
void Create(int** Q, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            Q[i][j] = Low + rand() % (High - Low + 1);
}

// Виведення матриці
void Print(int** Q, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(6) << Q[i][j];
        cout << endl;
    }
    cout << endl;
}

// Обчислення суми і кількості, заміна елементів 
void CalcAndReplace(int** Q, const int rowCount, const int colCount, int& S, int& k) {
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            // Критерій: всі, крім додатних парних
            if (!(Q[i][j] > 0 && Q[i][j] % 2 == 0)) {
                S += Q[i][j];
                k++;
                Q[i][j] = 0;
            }
        }
    }
}

// Сортування стовпців за ключами (→ ← →) 
void SortCols(int** Q, const int rowCount, const int colCount) {
    for (int j1 = 0; j1 < colCount - 1; j1++)
        for (int j2 = 0; j2 < colCount - j1 - 1; j2++)
            if (
                (Q[0][j2] > Q[0][j2 + 1]) || // перший ключ — за зростанням (→)
                (Q[0][j2] == Q[0][j2 + 1] && Q[1][j2] < Q[1][j2 + 1]) || // другий — за спаданням (←)
                (Q[0][j2] == Q[0][j2 + 1] &&
                    Q[1][j2] == Q[1][j2 + 1] &&
                    Q[2][j2] > Q[2][j2 + 1]) // третій — за зростанням (→)
                )
                SwapCols(Q, rowCount, j2, j2 + 1);
}


// Обмін стовпців місцями
void SwapCols(int** Q, const int rowCount, int col1, int col2) {
    for (int i = 0; i < rowCount; i++) {
        int tmp = Q[i][col1];
        Q[i][col1] = Q[i][col2];
        Q[i][col2] = tmp;
    }
}

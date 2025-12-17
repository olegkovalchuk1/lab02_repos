#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

enum Specialty {
    KN, 
    INF, 
    ME, 
    FIZ 
};


union GradeUnion {
    struct {
        int phys;
        int math;
        int inform;
    } sub;
    int marks[3]; // Можливість доступу як до масиву
};

struct Student {
    char surname[60];
    int course;
    Specialty spec;
    GradeUnion grades;
};

// Структура для повернення результатів першого завдання
struct ResultCounts {
    int cntPhys;
    int cntMath;
    int cntInf;
};

// Прототипи функцій
void Create(char* fname); // створення файлу
void Print(char* fname); // виведення таблиці
ResultCounts CalcGood(char* fname); // підрахунок оцінок "добре"
double CalcPercent(char* fname); // обчислення відсотка відмінників

#endif
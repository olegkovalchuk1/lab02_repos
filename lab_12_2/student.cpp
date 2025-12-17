#include "student.h"

string SpecStr(Specialty s) // допоміжна функція для виводу назви
{
    switch (s) {
    case KN: return "Computer Sci";
    case INF: return "Informatics";
    case ME: return "Math & Econ";
    case FIZ: return "Physics";
    default: return "Unknown";
    }
}

void Create(char* fname)
{
    ofstream fout(fname, ios::binary); // відкрили файл для запису
    char ch; // відповідь користувача
    Student s; // змінна для запису
    int sp; // тимчасова змінна для спеціальності

    do {
        cout << "Enter surname: "; cin >> s.surname;
        cout << "Enter year: "; cin >> s.course;
        cout << "Specialty (0-CS, 1-Inf, 2-ME, 3-Phys): "; cin >> sp;
        s.spec = (Specialty)sp; // перетворення int в enum

        cout << "Physics grade: "; cin >> s.grades.sub.phys;
        cout << "Math grade: "; cin >> s.grades.sub.math;
        cout << "CS grade: "; cin >> s.grades.sub.inform;

        // записуємо структуру у файл
        fout.write((char*)&s, sizeof(Student));

        cout << "Continue? (y/n): "; cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    fout.close();
    cout << endl;
}

void Print(char* fname)
{
    ifstream fin(fname, ios::binary); // відкрили файл для зчитування
    if (!fin) {
        cout << "File not found!" << endl;
        return;
    }

    Student s;
    int i = 1;

    cout << "==========================================================================" << endl;
    cout << "| No | Surname        | Year | Specialty    | Physics | Math    | CS     |" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

    while (fin.read((char*)&s, sizeof(Student))) // поки можна прочитати структуру
    {
        cout << "| " << setw(2) << i++ << " | "
            << setw(14) << left << s.surname << " | "
            << setw(4) << s.course << " | "
            << setw(12) << SpecStr(s.spec) << " | "
            << setw(7) << s.grades.sub.phys << " | "
            << setw(7) << s.grades.sub.math << " | "
            << setw(6) << s.grades.sub.inform << " |" << endl;
    }
    cout << "==========================================================================" << endl;
    cout << endl;
    fin.close();
}

ResultCounts CalcGood(char* fname)
{
    ifstream fin(fname, ios::binary); // відкрили файл
    ResultCounts res = { 0, 0, 0 }; // ініціалізація лічильників
    Student s;

    while (fin.read((char*)&s, sizeof(Student))) // читаємо по одному запису
    {
        if (s.grades.sub.phys == 4) res.cntPhys++; // якщо фізика "добре"
        if (s.grades.sub.math == 4) res.cntMath++; // якщо математика "добре"
        if (s.grades.sub.inform == 4) res.cntInf++; // якщо інформ. "добре"
    }
    fin.close();
    return res; // повертаємо результат у місце виклику
}

double CalcPercent(char* fname)
{
    ifstream fin(fname, ios::binary);
    Student s;
    int total = 0; // загальна кількість студентів
    int match = 0; // кількість тих, хто відповідає умові

    while (fin.read((char*)&s, sizeof(Student)))
    {
        total++;
        // умова: і з фізики, і з математики оцінка "5"
        if (s.grades.sub.phys == 5 && s.grades.sub.math == 5)
            match++;
    }
    fin.close();

    if (total == 0) return 0.0;
    return ((double)match / total) * 100.0; // повертаємо відсоток
}
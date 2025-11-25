#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

enum Spec { KN, INF, MATH, PHYS };
string SpecStr[] = { "КН", "Інф", "Мат", "Фіз" };

struct Student
{
    string prizv;
    int kurs;
    Spec spec;
    int fiz;
    int math;
    int info;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void CountGoodMarks(Student* p, const int N, int& goodFiz, int& goodMath, int& goodInfo);
double PercentBestFM(Student* p, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів N: ";
    cin >> N;

    Student* p = new Student[N];

    int menuItem;

    do {
        cout << "\n\nВиберіть дію:\n";
        cout << " [1] - введення даних\n";
        cout << " [2] - вивід даних\n";
        cout << " [3] - підрахунок оцінок 'добре' (4)\n";
        cout << " [4] - процент студентів з оцінками 5 з фізики і математики\n";
        cout << " [0] - вихід\n";

        cout << "Ваш вибір: ";
        cin >> menuItem;
        cout << endl;

        switch (menuItem)
        {
        case 1:
            Create(p, N);
            break;

        case 2:
            Print(p, N);
            break;

        case 3:
        {
            int f, m, i;
            CountGoodMarks(p, N, f, m, i);
            cout << "Кількість оцінок 'добре' (4):\n";
            cout << " Фізика: " << f << endl;
            cout << " Математика: " << m << endl;
            cout << " Інформатика: " << i << endl;
        }
        break;

        case 4:
        {
            double proc = PercentBestFM(p, N);
            cout << "Процент студентів з оцінками 5 з фізики і математики: "
                << fixed << setprecision(2) << proc << "%\n";
        }
        break;

        case 0:
            break;

        default:
            cout << "Помилка! Невірний пункт меню.\n";
        }

    } while (menuItem != 0);

    delete[] p;
    return 0;
}

void Create(Student* p, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент №" << i + 1 << ":\n";

        cin.get();
        cin.sync();

        cout << " Прізвище: ";
        getline(cin, p[i].prizv);

        cout << " Курс: ";
        cin >> p[i].kurs;

        cout << " Спеціальність (0-КН, 1-Інф, 2-Мат, 3-Фіз): ";
        cin >> spec;
        p[i].spec = (Spec)spec;

        cout << " Оцінка з фізики: ";
        cin >> p[i].fiz;

        cout << " Оцінка з математики: ";
        cin >> p[i].math;

        cout << " Оцінка з інформатики: ";
        cin >> p[i].info;

        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "====================================================================================\n";
    cout << "| № | Прізвище        | Курс | Спеціальність | Фізика | Математика | Інформатика |\n";
    cout << "------------------------------------------------------------------------------------\n";

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << i + 1 << " ";
        cout << "| " << setw(15) << left << p[i].prizv;
        cout << "| " << setw(4) << right << p[i].kurs << " ";
        cout << "| " << setw(13) << left << SpecStr[p[i].spec];
        cout << "| " << setw(7) << right << p[i].fiz << " ";
        cout << "| " << setw(11) << right << p[i].math << " ";
        cout << "| " << setw(12) << right << p[i].info << " |\n";
    }

    cout << "====================================================================================\n";
}

void CountGoodMarks(Student* p, const int N, int& goodFiz, int& goodMath, int& goodInfo)
{
    goodFiz = goodMath = goodInfo = 0;

    for (int i = 0; i < N; i++)
    {
        if (p[i].fiz == 4)  goodFiz++;
        if (p[i].math == 4) goodMath++;
        if (p[i].info == 4) goodInfo++;
    }
}

double PercentBestFM(Student* p, const int N)
{
    int k = 0;

    for (int i = 0; i < N; i++)
        if (p[i].fiz == 5 && p[i].math == 5)
            k++;

    return (double)k / N * 100.0;
}

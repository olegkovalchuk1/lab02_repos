#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Route.h"

using namespace std;

// Функція безпечного введення цілого числа (контроль помилок)
int GetInt()
{
	int value;
	while (!(cin >> value)) // поки введення не є числом
	{
		cin.clear(); // скидаємо прапори помилок
		while (cin.get() != '\n'); // очищуємо буфер
		cout << "Error! Enter a number: ";
	}
	// Очищуємо залишок рядка після числа, щоб не заважав getline
	cin.ignore(cin.rdbuf()->in_avail());
	return value;
}

void CreateTXT(char* fname) // створення списку маршрутів (новий файл)
{
	ofstream fout(fname); // відкрили файл для запису (перезапис)
	char ch;              // відповідь користувача
	Route r;              // тимчасова змінна для маршруту

	do
	{
		cout << "Route number: ";
		r.number = GetInt(); // вводимо номер з перевіркою

		cout << "Start point: ";
		getline(cin, r.startPoint); // вводимо назву пункту (може бути з пробілами)

		cout << "End point: ";
		getline(cin, r.endPoint);

		// Записуємо у файл у форматі: Номер Початок Кінець
		// Використовуємо роздільник (наприклад, новий рядок для кожного поля) для надійності
		fout << r.number << endl;
		fout << r.startPoint << endl;
		fout << r.endPoint << endl;

		cout << "Continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void AddRouteTXT(char* fname) // поповнення списку (додавання в кінець)
{
	ofstream fout(fname, ios::app); // відкрили файл для дозапису (append)
	Route r;

	cout << "--- Adding new route ---" << endl;
	cout << "Route number: ";
	r.number = GetInt();

	cout << "Start point: ";
	getline(cin, r.startPoint);

	cout << "End point: ";
	getline(cin, r.endPoint);

	fout << r.number << endl;
	fout << r.startPoint << endl;
	fout << r.endPoint << endl;

	cout << "Added successfully." << endl;
}

void PrintTXT(char* fname) // перегляд списку
{
	ifstream fin(fname); // відкрили файл для зчитування
	Route r;

	cout << "========================================" << endl;
	cout << " #  | Start Point        | End Point    " << endl;
	cout << "========================================" << endl;

	// Зчитуємо дані в тому ж порядку, як і записували
	while (fin >> r.number)
	{
		fin.ignore(); // пропускаємо перехід рядка після числа
		getline(fin, r.startPoint);
		getline(fin, r.endPoint);

		cout << setw(3) << r.number << " | "
			<< setw(18) << left << r.startPoint << " | "
			<< r.endPoint << endl;
	}
	cout << endl;
}

bool SearchRoute(char* fname, int num, Route& foundRoute) // пошук маршруту
{
	ifstream fin(fname); // відкрили файл
	Route r;
	bool found = false;

	while (fin >> r.number) // скануємо файл
	{
		fin.ignore();
		getline(fin, r.startPoint);
		getline(fin, r.endPoint);

		if (r.number == num) // якщо номер співпав
		{
			foundRoute = r; // копіюємо дані у вихідний параметр
			found = true;   // ставимо прапорець
			// Не робимо break, якщо хочемо знайти останній (або робимо, якщо перший)
			break;
		}
	}
	return found; // повертаємо результат (так або ні)
}
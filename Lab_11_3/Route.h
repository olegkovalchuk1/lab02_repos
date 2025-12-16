#pragma once
#include <string>

using namespace std;

// Структура для зберігання даних про маршрут
struct Route
{
	string startPoint; // початковий пункт
	string endPoint;   // кінцевий пункт
	int number;        // номер маршруту
};

// Прототипи функцій
void CreateTXT(char* fname); // створення файлу (перезапис)
void AddRouteTXT(char* fname); // додавання одного маршруту (поповнення)
void PrintTXT(char* fname); // виведення вмісту файлу
bool SearchRoute(char* fname, int num, Route& foundRoute); // пошук маршруту (повертає результат)
int GetInt(); // допоміжна функція для безпечного введення числа

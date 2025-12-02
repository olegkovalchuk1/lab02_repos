#define _CRT_SECURE_NO_WARNINGS
#include "Unit.h"

void PrintTXT(char* fname)
{
	ifstream fin(fname); // відкрили файл для зчитування
	if (!fin.is_open()) {
		cout << "Error: File not found!" << endl;
		return;
	}

	string s;
	cout << "\n--- File Content ---" << endl;
	while (getline(fin, s))
	{
		cout << s << endl;
	}
	cout << "--------------------\n" << endl;
	fin.close(); // не забуваємо закрити, щоб наступна функція могла його відкрити
}

bool ProcessTXT(char* fname)
{
	ifstream fin(fname);
	if (!fin.is_open()) {
		return false; // Якщо файлу немає, то і пар немає
	}

	string s;
	while (getline(fin, s))
	{
		// Якщо рядок менший за 2 символи, там не може бути пари
		if (s.length() < 2) continue;

		for (unsigned i = 0; i < s.length() - 1; i++)
		{
			// Перевірка сусідніх букв
			if ((s[i] == 'a' && s[i + 1] == 'a') ||
				(s[i] == 'b' && s[i + 1] == 'b') ||
				(s[i] == 'c' && s[i + 1] == 'c'))
			{
				fin.close();
				return true; // Знайшли!
			}
		}
	}

	fin.close();
	return false; // Нічого не знайшли
}
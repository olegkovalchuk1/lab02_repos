#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Unit.h"

using namespace std;

int main()
{
	char fname[100];

	cout << "Enter the name of existing file (e.g. t.txt): ";
	cin >> fname;

	// 1. Спочатку покажемо вміст файлу (опціонально, але корисно для перевірки)
	PrintTXT(fname);

	// 2. Викликаємо функцію пошуку
	if (ProcessTXT(fname))
	{
		cout << "Result: YES (Found 'aa', 'bb' or 'cc')" << endl;
	}
	else
	{
		cout << "Result: NO (Pairs not found or file error)" << endl;
	}

	return 0;
}
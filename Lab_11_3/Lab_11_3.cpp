#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Route.h"

using namespace std;

int main()
{
	char fname[100]; // масив для імені файлу
	int menuItem;    // вибір меню

	cout << "Enter filename (e.g., data.txt): ";
	cin >> fname;

	do
	{
		cout << "=== MENU ===" << endl;
		cout << "[1] Create new list (overwrite)" << endl;
		cout << "[2] Add route to list" << endl;
		cout << "[3] View all routes" << endl;
		cout << "[4] Search route by number" << endl;
		cout << "[0] Exit" << endl;
		cout << "Select action: ";
		menuItem = GetInt(); // використовуємо функцію з контролем помилок

		cout << endl;

		switch (menuItem)
		{
		case 1:
			CreateTXT(fname);
			break;
		case 2:
			AddRouteTXT(fname);
			break;
		case 3:
			PrintTXT(fname);
			break;
		case 4:
		{
			int searchNum;
			cout << "Enter route number to search: ";
			searchNum = GetInt();

			Route result; // змінна для збереження результату

			// Функція повертає true/false, а дані кладе в result
			if (SearchRoute(fname, searchNum, result))
			{
				cout << "FOUND:" << endl;
				cout << "Start: " << result.startPoint << endl;
				cout << "End:   " << result.endPoint << endl;
			}
			else
			{
				cout << "Route number " << searchNum << " not found." << endl;
			}
		}
		break;
		case 0:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid menu item!" << endl;
		}
		cout << endl;

	} while (menuItem != 0);

	return 0;
}
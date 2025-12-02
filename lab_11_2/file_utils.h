#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// Виведення вмісту файлу на екран (щоб бачити, що опрацьовуємо)
void PrintTXT(char* fname);

// Функція пошуку: повертає true, якщо є слово на літеру 'a', інакше false
bool ContainsWordStartingWithA(char* fname);
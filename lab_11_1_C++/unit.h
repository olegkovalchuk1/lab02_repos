#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функція для виведення вмісту файлу (щоб бачити, що ми перевіряємо)
void PrintTXT(char* fname);

// Головна функція завдання: перевірка на "aa", "bb", "cc"
bool ProcessTXT(char* fname);
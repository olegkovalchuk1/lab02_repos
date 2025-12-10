#pragma once
#ifndef FILEOPS_H
#define FILEOPS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функція створення файлу з цілими числами
void CreateFile(const char* fileName);

// Функція виведення вмісту бінарного файлу (int) на екран
void PrintFile(const char* fileName);

// Функція розділення чисел на парні та непарні у два різні файли
void SplitFile(const char* sourceName, const char* evenName, const char* oddName);

#endif
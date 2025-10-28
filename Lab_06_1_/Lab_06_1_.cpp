#include <iostream>
#include <iomanip>   
#include <cstdlib>   
#include <ctime>     

using namespace std;

// √енеруЇ масив випадкових чисел у заданому д≥апазон≥
void generateArray(int arr[], int size, int minVal, int maxVal) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = minVal + rand() % (maxVal - minVal + 1);
    }
}

// ¬иводить масив з форматуванн€м
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << setw(4) << arr[i];
    cout << endl;
}

// ќбчислюЇ к≥льк≥сть елемент≥в, що задовольн€ють критер≥й 
int countElements(const int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] % 2 != 0 && i % 13 != 0)
            count++;
    return count;
}

// ќбчислюЇ суму елемент≥в, що задовольн€ють критер≥й 
int sumElements(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        if (arr[i] % 2 != 0 && i % 13 != 0)
            sum += arr[i];
    return sum;
}

// «ам≥нюЇ нул€ми елементи, що задовольн€ють критер≥й 
void replaceWithZero(int arr[], int size) {
    for (int i = 0; i < size; i++)
        if (arr[i] % 2 != 0 && i % 13 != 0)
            arr[i] = 0;
}

int main() {
    const int SIZE = 21;
    int c[SIZE];
    const int MIN = 15, MAX = 85;

    generateArray(c, SIZE, MIN, MAX);


    printArray(c, SIZE);

    int count = countElements(c, SIZE);
    int sum = sumElements(c, SIZE);

    replaceWithZero(c, SIZE);

    cout << "Number of elements satisfying the criterion:" << count << endl;
    cout << "Sum of the following elements:" << sum << endl;


    printArray(c, SIZE);

    return 0;
}

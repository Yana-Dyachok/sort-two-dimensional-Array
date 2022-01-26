/*2. Відсортуйте динамічний масив за зростанням або спаданням.Реалізуйте меню для користувача.
Наприклад:
1 – сортування за зростанням
2 – за спаданням.*/
#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;
void divisionArr(int** matrix, int n, int m);//функція розподілу динамічної пам'яті
void inputArr(int** matrix, int n, int m);//функція для вводу елементів масиву
void printArr(int** matrix, int n, int m);//функція виводить елементи масиву
void increaseArr(int** matrix, int n, int m);//функція сортує елементи масиву за зростанням
void decreaseArr(int** matrix, int n, int m);//функція сортує елементи масиву за спаданням
void deleteArr(int** matrix, int n, int m);//функція видалення масиву
int main()
{   srand(time(NULL));//завдяки даній функції, рандомні числа будуть постійно змінюватись 
    SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
    int** matrix = nullptr;//вказівник масиву рівний 0
    int n = 0;//змінна - відповідає стовпцям масиву
    int m = 0;//змінна - відповідає рядкам масиву
    cout << "Введіть число m" << endl;
    cin>>n;
    cout << "Введіть число m" << endl;
    cin>>m;
    matrix = new int* [n];
    divisionArr(matrix, n, m);//звертаємось до функції розподілу динамічної пам'яті
    inputArr(matrix, n, m);//звертаємось до функції для вводу елементів масиву
    cout << endl;
    printArr(matrix, n, m);//звертаємось до функції виведення елементів масиву
    cout << endl;
    cout << "Cортування за зростанням" << endl;
    increaseArr(matrix, n, m);//звертаємось до функції яка сортує елементи масиву за зростанням
    printArr(matrix, n, m);//звертаємось до функції ввиведення елементів масиву
    cout << "Cортування за спаданням" << endl;
    decreaseArr(matrix, n, m);//звертаємось до функції яка сортує елементи масиву за спаданням
    printArr(matrix, n, m);//звертаємось до функції виведення елементів масиву
    deleteArr(matrix, n, m);//звертаємось до функції видалення масиву
    delete[]matrix;//видаляємо matrix
}
void divisionArr(int** matrix, int n, int m) {//функція розподілу динамічної пам'яті
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
    }
}
void inputArr(int** matrix, int n, int m) {//функція для вводу елементів масиву
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
}
void printArr(int** matrix, int n, int m) {//функція виводить елементи масиву
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
void deleteArr(int** matrix, int n, int m) {//функція видалення масиву
    for (int i = 0; i < n; i++)
    {
        delete[]matrix[i];
    }
}
void increaseArr(int** matrix, int n, int m) {//функція сортує елементи масиву за зростанням
    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < m; l++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i + 1 == n and j + 1 == m) {//якщо елемент масиву буде знаходитись в кінці матриці- продовжуємо спочатку
                        continue;
                    }
                    else {
                        if (j + 1 == m and matrix[i][j] > matrix[i + 1][0]) {//якщо елемент масиву буде знаходитись в кінці рядка матриці та більший за елементи першого стовпця- сортуємо
                            swap(matrix[i][j], matrix[i + 1][0]);//сортуємо бульбашковим методом
                        }
                        else {
                            if (j + 1 == m) {//якщо елемент масиву буде знаходитись в кінці рядка матриці- продовжуємо 
                                continue;
                            }
                            else {
                                if (matrix[i][j] > matrix[i][j + 1]) {//при даній умові відсортовуємо за зростанням
                                    swap(matrix[i][j], matrix[i][j + 1]);//сортуємо бульбашковим методом
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void decreaseArr(int** matrix, int n, int m) {//функція сортує елементи масиву за спаданням
    for (int k = 0; k < n; k++)
    {
        for (int l = 0; l < m; l++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i + 1 == n and j + 1 == m) {//якщо елемент масиву буде знаходитись в кінці матриці- продовжуємо спочатку
                        continue;
                    }
                    else {
                        if (j + 1 == m and matrix[i][j] < matrix[i + 1][0]) {//якщо елемент масиву буде знаходитись в кінці рядка матриці та більший за елементи першого стовпця- сортуємо
                            swap(matrix[i][j], matrix[i + 1][0]);//сортуємо бульбашковим методом
                        }
                        else {
                            if (j + 1 == m) {//якщо елемент масиву буде знаходитись в кінці рядка матриці- продовжуємо 
                                continue;
                            }
                            else {
                                if (matrix[i][j] < matrix[i][j + 1]) {//при даній умові відсортовуємо за спаданням
                                    swap(matrix[i][j], matrix[i][j + 1]);//сортуємо бульбашковим методом
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
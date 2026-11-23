// головний модуль: масив прізвищ, меню, виклик функцій інших модулів
// Лабораторна робота № 10, завдання 10.1 В, варіант 27
//   1. Для кожного студента вивести: прізвище і середній бал.
//   2. Обчислити процент студентів, які отримали з фізики оцінки "5" або "4".
#include <iostream>
#include <string>
#include <Windows.h>               // забезпечення відображення кирилиці
#include "Student.h"
#include "Create.h"
#include "Print.h"
#include "Calc.h"
using namespace std;

// кількість елементів у масиві прізвищ
const int MAX_PRIZVYSHCH = 30;

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    // Масив прізвищ — ЗАПОВНИТИ САМОСТІЙНО, наприклад:
    // string prizvyshcha[MAX_PRIZVYSHCH] = { "Іваненко", "Петренко", "Коваль" };
    // Незаповнені елементи залишаються порожніми — для таких студентів
    // прізвище буде запитано з клавіатури.
    string prizvyshcha[MAX_PRIZVYSHCH] = { };

    int N;
    do {
        cout << "Введіть кількість студентів N: ";
        if (!(cin >> N))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            N = 0;
        }
    } while (N <= 0);

    Student* p = new Student[N]();   // динамічний масив структур

    int menuItem;
    do {
        cout << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних" << endl;
        cout << " [2] - вивід даних на екран у вигляді таблиці" << endl;
        cout << " [3] - вивід прізвища та середнього балу кожного студента" << endl;
        cout << " [4] - процент студентів, які отримали з фізики \"5\" або \"4\"" << endl << endl;
        cout << " [0] - вихід та завершення роботи програми" << endl << endl;
        cout << "Введіть значення: ";
        if (!(cin >> menuItem))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            menuItem = -1;
        }
        cout << endl;

        switch (menuItem)
        {
        case 1:
            Create(p, N, prizvyshcha, MAX_PRIZVYSHCH);
            break;
        case 2:
            Print(p, N);
            break;
        case 3:
            PrintSerednijBal(p, N);
            break;
        case 4:
            cout << "Процент студентів, які отримали з фізики оцінки \"5\" або \"4\": "
                << PercentFizyka4abo5(p, N) << "%" << endl;
            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення! "
                "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menuItem != 0);

    delete[] p;                      // звільнення динамічної пам'яті
    return 0;
}
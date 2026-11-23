// Print.cpp — реалізація виведення даних на екран
#include <iostream>
#include <iomanip>
#include <string>
#include "Print.h"
#include "Calc.h"
using namespace std;

// Повертає кількість СИМВОЛІВ у рядку (а не байтів).
// Якщо рядок у кодуванні UTF-8 (кирилиця = 2 байти), рахуємо символи;
// інакше (наприклад, win-1251, де 1 символ = 1 байт) повертаємо size().
static int DovzhynaSymvoliv(const string& s)
{
    int symvoly = 0;
    for (size_t i = 0; i < s.size(); )
    {
        unsigned char c = (unsigned char)s[i];
        int dovzhyna;
        if (c < 0x80)                dovzhyna = 1;
        else if ((c & 0xE0) == 0xC0) dovzhyna = 2;
        else if ((c & 0xF0) == 0xE0) dovzhyna = 3;
        else if ((c & 0xF8) == 0xF0) dovzhyna = 4;
        else return (int)s.size();                    // не UTF-8

        if (i + dovzhyna > s.size())
            return (int)s.size();                     // не UTF-8
        for (int k = 1; k < dovzhyna; k++)
            if (((unsigned char)s[i + k] & 0xC0) != 0x80)
                return (int)s.size();                 // не UTF-8

        i += dovzhyna;
        symvoly++;
    }
    return symvoly;
}

// Повертає рядок s, доповнений пробілами справа до ширини width символів
static string Zliva(const string& s, const int width)
{
    int dovzhyna = DovzhynaSymvoliv(s);
    return s + string(dovzhyna < width ? width - dovzhyna : 0, ' ');
}

// Повертає рядок s, доповнений пробілами зліва до ширини width символів
static string Sprava(const string& s, const int width)
{
    int dovzhyna = DovzhynaSymvoliv(s);
    return string(dovzhyna < width ? width - dovzhyna : 0, ' ') + s;
}

void Print(const Student* p, const int N)
{
    const string dviLinii(119, '=');
    const string odnaLinia(119, '-');

    cout << endl << "Таблиця 1. Відомості про студентів та їхні оцінки" << endl;
    cout << dviLinii << endl;
    cout << "| " << Zliva("№", 3)
        << " | " << Zliva("Прізвище", 14)
        << " | " << Zliva("Курс", 4)
        << " | " << Zliva("Спеціальність", 23)
        << " | " << Zliva("Фізика", 6)
        << " | " << Zliva("Математика", 10)
        << " | " << Zliva("Програмув.", 10)
        << " | " << Zliva("Чис. методи", 11)
        << " | " << Zliva("Педагогіка", 10)
        << " |" << endl;
    cout << odnaLinia << endl;

    for (int i = 0; i < N; i++)
    {
        // у кожного студента заповнена лише одна з трьох останніх клітинок
        string programuvannia, chyselniMetody, pedahohika;
        switch (p[i].specialnist)
        {
        case KN: programuvannia = to_string(p[i].prohramuvannia);  break;
        case INF: chyselniMetody = to_string(p[i].chyselni_metody); break;
        default: pedahohika = to_string(p[i].pedahohika);      break;
        }

        cout << "| " << Sprava(to_string(i + 1), 3)
            << " | " << Zliva(p[i].prizv, 14)
            << " | " << Sprava(to_string(p[i].kurs), 4)
            << " | " << Zliva(SpecialnistToString(p[i].specialnist), 23)
            << " | " << Sprava(to_string(p[i].fizyka), 6)
            << " | " << Sprava(to_string(p[i].matematyka), 10)
            << " | " << Sprava(programuvannia, 10)
            << " | " << Sprava(chyselniMetody, 11)
            << " | " << Sprava(pedahohika, 10)
            << " |" << endl;
    }
    cout << dviLinii << endl << endl;
}

void PrintSerednijBal(const Student* p, const int N)
{
    const string dviLinii(41, '=');
    const string odnaLinia(41, '-');

    cout << endl << "Таблиця 2. Середній бал студентів" << endl;
    cout << dviLinii << endl;
    cout << "| " << Zliva("№", 3)
        << " | " << Zliva("Прізвище", 18)
        << " | " << Zliva("Сер. бал", 10)
        << " |" << endl;
    cout << odnaLinia << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << Sprava(to_string(i + 1), 3)
            << " | " << Zliva(p[i].prizv, 18)
            << " | " << setw(10) << right << fixed << setprecision(2)
            << SerednijBal(p[i])
            << " |" << endl;
    }
    cout << dviLinii << endl << endl;
}
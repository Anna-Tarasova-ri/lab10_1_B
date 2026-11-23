// Student.h — опис типів даних: перелік спеціальностей та структура Student з об'єднанням
#pragma once
#include <string>

// спеціальності (перелік)
enum Specialnist
{
    KN,   // комп'ютерні науки
    INF,   // інформатика
    ME,   // математика та економіка
    FI,   // фізика та інформатика
    TN    // трудове навчання
};

// кількість спеціальностей у переліку
const int KILKIST_SPECIALNOSTEI = 5;

// інформація про студента (рівень В)
struct Student
{
    std::string prizv;                 // прізвище
    int         kurs = 1;       // курс (ціле число)
    Specialnist specialnist = KN;      // спеціальність (перелік)
    int         fizyka = 0;       // оцінка з фізики
    int         matematyka = 0;       // оцінка з математики
    union                              // третя оцінка — залежить від спеціальності
    {
        int prohramuvannia = 0;        // КН — програмування
        int chyselni_metody;           // ІН — чисельні методи
        int pedahohika;                // ME, FI, TN — педагогіка
    };
};

// повертає назву спеціальності у вигляді рядка
std::string SpecialnistToString(const Specialnist s);
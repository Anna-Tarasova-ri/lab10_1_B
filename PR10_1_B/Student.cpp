// Student.cpp — реалізація допоміжних функцій для типу Student
#include "Student.h"
using namespace std;

string SpecialnistToString(const Specialnist s)
{
    switch (s)
    {
    case KN: return "Комп'ютерні науки";
    case INF: return "Інформатика";
    case ME: return "Математика та економіка";
    case FI: return "Фізика та інформатика";
    case TN: return "Трудове навчання";
    }
    return "невідомо";
}
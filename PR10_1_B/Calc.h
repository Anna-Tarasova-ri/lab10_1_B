// Calc.h — опрацювання масиву: обчислення (без виведення на екран)
#pragma once
#include "Student.h"

// повертає третю оцінку студента (з програмування, чисельних методів
// або педагогіки — залежно від його спеціальності)
int TretiaOcinka(const Student& s);

// повертає середній бал одного студента (фізика, математика, третя оцінка)
double SerednijBal(const Student& s);

// повертає відсоток студентів, які отримали з фізики оцінку "5" або "4"
double PercentFizyka4abo5(const Student* p, const int N);
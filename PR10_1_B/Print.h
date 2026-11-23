// Print.h — виведення даних на екран
#pragma once
#include "Student.h"

// виводить масив студентів у вигляді таблиці (із заголовком і шапкою)
void Print(const Student* p, const int N);

// виводить для кожного студента прізвище і середній бал (таблиця)
void PrintSerednijBal(const Student* p, const int N);
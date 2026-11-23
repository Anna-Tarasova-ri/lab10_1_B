// Create.h — формування (введення) масиву структур з об'єднаннями
#pragma once
#include <string>
#include "Student.h"

// Заповнює масив студентів.
// Прізвище береться з масиву prizvyshcha (якщо елемент заповнений),
// інакше вводиться з клавіатури. Решта полів вводиться з клавіатури;
// третя оцінка залежить від спеціальності студента.
void Create(Student* p, const int N,
    const std::string prizvyshcha[], const int kilkistPrizvyshch);
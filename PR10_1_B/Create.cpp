// Create.cpp — реалізація формування масиву структур з об'єднаннями
#include <iostream>
#include <string>
#include "Create.h"
using namespace std;

// Вводить ціле число з клавіатури, доки воно не потрапить у діапазон [min; max]
static int VvestyVDiapazoni(const string& pidkazka, const int min, const int max)
{
    int x;
    while (true)
    {
        cout << pidkazka;
        if (cin >> x && x >= min && x <= max)
            return x;

        cout << "     Помилка! Введіть ціле число від " << min
            << " до " << max << "." << endl;
        cin.clear();                              // скидаємо стан помилки потоку
        cin.ignore(10000, '\n');                  // видаляємо зайві символи
    }
}

void Create(Student* p, const int N,
    const string prizvyshcha[], const int kilkistPrizvyshch)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;

        // прізвище: з масиву (якщо заповнений), інакше — з клавіатури
        if (i < kilkistPrizvyshch && !prizvyshcha[i].empty())
        {
            p[i].prizv = prizvyshcha[i];
            cout << "     прізвище: " << p[i].prizv << endl;
        }
        else
        {
            cout << "     прізвище: ";
            cin >> ws;                            // пропускаємо залишки у буфері
            getline(cin, p[i].prizv);
        }

        p[i].kurs = VvestyVDiapazoni("     курс (1-4): ", 1, 4);

        p[i].specialnist = (Specialnist)VvestyVDiapazoni(
            "     спеціальність (0 - комп'ютерні науки, 1 - інформатика,\n"
            "                    2 - математика та економіка, 3 - фізика та інформатика,\n"
            "                    4 - трудове навчання): ",
            0, KILKIST_SPECIALNOSTEI - 1);

        p[i].fizyka = VvestyVDiapazoni("     оцінка з фізики (1-5): ", 1, 5);
        p[i].matematyka = VvestyVDiapazoni("     оцінка з математики (1-5): ", 1, 5);

        // третя оцінка залежить від спеціальності (об'єднання)
        switch (p[i].specialnist)
        {
        case KN:
            p[i].prohramuvannia =
                VvestyVDiapazoni("     оцінка з програмування (1-5): ", 1, 5);
            break;
        case INF:
            p[i].chyselni_metody =
                VvestyVDiapazoni("     оцінка з чисельних методів (1-5): ", 1, 5);
            break;
        case ME:
        case FI:
        case TN:
            p[i].pedahohika =
                VvestyVDiapazoni("     оцінка з педагогіки (1-5): ", 1, 5);
            break;
        }

        cout << endl;
    }
}
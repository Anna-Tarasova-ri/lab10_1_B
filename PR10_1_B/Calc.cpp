// Calc.cpp — реалізація функцій обчислення
#include "Calc.h"

int TretiaOcinka(const Student& s)
{
    switch (s.specialnist)
    {
    case KN: return s.prohramuvannia;
    case INF: return s.chyselni_metody;
    default: return s.pedahohika;              // ME, FI, TN
    }
}

double SerednijBal(const Student& s)
{
    return (s.fizyka + s.matematyka + TretiaOcinka(s)) / 3.0;
}

double PercentFizyka4abo5(const Student* p, const int N)
{
    if (N <= 0)
        return 0.0;

    int k = 0;
    for (int i = 0; i < N; i++)
        if (p[i].fizyka == 5 || p[i].fizyka == 4)
            k++;

    return 100.0 * k / N;
}
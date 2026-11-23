// UnitTest1.cpp — модульні тести для лабораторної роботи № 10, завдання 10.1 В, варіант 27
// Тестуються функції без введення/виведення:
//   TretiaOcinka, SerednijBal, PercentFizyka4abo5 (модуль Calc),
//   SpecialnistToString (модуль Student).
#include "pch.h"
#include "CppUnitTest.h"

// підключаємо тестовані модулі з основного проєкту
// (шлях підстав під свою структуру папок рішення)
#include "../PR10_1_B/Student.cpp"
#include "../PR10_1_B/Calc.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest
{
    // ---------- TretiaOcinka ----------
    TEST_CLASS(TretiaOcinkaTests)
    {
    public:
        TEST_METHOD(KN_Prohramuvannia)
        {
            Student s;
            s.specialnist = KN;
            s.prohramuvannia = 4;
            Assert::AreEqual(4, TretiaOcinka(s));
        }

        TEST_METHOD(INF_ChyselniMetody)
        {
            Student s;
            s.specialnist = INF;
            s.chyselni_metody = 3;
            Assert::AreEqual(3, TretiaOcinka(s));
        }

        TEST_METHOD(ME_Pedahohika)
        {
            Student s;
            s.specialnist = ME;
            s.pedahohika = 5;
            Assert::AreEqual(5, TretiaOcinka(s));
        }

        TEST_METHOD(FI_Pedahohika)
        {
            Student s;
            s.specialnist = FI;
            s.pedahohika = 2;
            Assert::AreEqual(2, TretiaOcinka(s));
        }

        TEST_METHOD(TN_Pedahohika)
        {
            Student s;
            s.specialnist = TN;
            s.pedahohika = 4;
            Assert::AreEqual(4, TretiaOcinka(s));
        }

        TEST_METHOD(OcinkyFizykyIMatematykyNeVplyvajut)
        {
            Student s;
            s.specialnist = KN;
            s.fizyka = 1;
            s.matematyka = 1;
            s.prohramuvannia = 5;
            Assert::AreEqual(5, TretiaOcinka(s));
        }
    };

    // ---------- SerednijBal ----------
    TEST_CLASS(SerednijBalTests)
    {
    public:
        TEST_METHOD(KN_ZvychajniOcinky)
        {
            Student s;
            s.specialnist = KN;
            s.fizyka = 5; s.matematyka = 4; s.prohramuvannia = 3;
            Assert::AreEqual(4.0, SerednijBal(s), 1e-9);
        }

        TEST_METHOD(INF_DrobovyjSerednijBal)
        {
            Student s;
            s.specialnist = INF;
            s.fizyka = 4; s.matematyka = 4; s.chyselni_metody = 5;
            Assert::AreEqual(13.0 / 3.0, SerednijBal(s), 1e-9);
        }

        TEST_METHOD(ME_UsiMinimalni)
        {
            Student s;
            s.specialnist = ME;
            s.fizyka = 1; s.matematyka = 1; s.pedahohika = 1;
            Assert::AreEqual(1.0, SerednijBal(s), 1e-9);
        }

        TEST_METHOD(FI_Trijky)
        {
            Student s;
            s.specialnist = FI;
            s.fizyka = 2; s.matematyka = 3; s.pedahohika = 4;
            Assert::AreEqual(3.0, SerednijBal(s), 1e-9);
        }

        TEST_METHOD(TN_UsiMaksymalni)
        {
            Student s;
            s.specialnist = TN;
            s.fizyka = 5; s.matematyka = 5; s.pedahohika = 5;
            Assert::AreEqual(5.0, SerednijBal(s), 1e-9);
        }

        TEST_METHOD(TretiaOcinkaVrahovuyetsya)
        {
            Student s;
            s.specialnist = KN;
            s.fizyka = 5; s.matematyka = 5; s.prohramuvannia = 2;
            Assert::AreEqual(4.0, SerednijBal(s), 1e-9);
        }
    };

    // ---------- PercentFizyka4abo5 ----------
    TEST_CLASS(PercentFizyka4abo5Tests)
    {
    public:
        TEST_METHOD(PolovynaStudentiv)
        {
            Student p[4];
            p[0].fizyka = 5; p[1].fizyka = 4; p[2].fizyka = 3; p[3].fizyka = 2;
            Assert::AreEqual(50.0, PercentFizyka4abo5(p, 4), 1e-9);
        }

        TEST_METHOD(UsiMajutP_yatirkyAboChetvirky)
        {
            Student p[3];
            p[0].fizyka = 5; p[1].fizyka = 5; p[2].fizyka = 4;
            Assert::AreEqual(100.0, PercentFizyka4abo5(p, 3), 1e-9);
        }

        TEST_METHOD(ZhodenNeMaje)
        {
            Student p[3];
            p[0].fizyka = 3; p[1].fizyka = 2; p[2].fizyka = 1;
            Assert::AreEqual(0.0, PercentFizyka4abo5(p, 3), 1e-9);
        }

        TEST_METHOD(TrijkaNeRahujetsya)
        {
            Student p[1];
            p[0].fizyka = 3;
            Assert::AreEqual(0.0, PercentFizyka4abo5(p, 1), 1e-9);
        }

        TEST_METHOD(DrobovyjProcent)
        {
            Student p[3];
            p[0].fizyka = 5; p[1].fizyka = 3; p[2].fizyka = 2;
            Assert::AreEqual(100.0 / 3.0, PercentFizyka4abo5(p, 3), 1e-9);
        }

        TEST_METHOD(NulStudentivNeDilytNaNul)
        {
            Student* p = nullptr;
            Assert::AreEqual(0.0, PercentFizyka4abo5(p, 0), 1e-9);
        }

        TEST_METHOD(RiznaSpecialnistNeVplyvaje)
        {
            Student p[2];
            p[0].specialnist = KN;  p[0].fizyka = 5;
            p[1].specialnist = TN;  p[1].fizyka = 2;
            Assert::AreEqual(50.0, PercentFizyka4abo5(p, 2), 1e-9);
        }

        TEST_METHOD(OcinkyZInshyhPredmetivNeVplyvajut)
        {
            Student p[2];
            p[0].fizyka = 2; p[0].matematyka = 5; p[0].pedahohika = 5;
            p[1].fizyka = 5; p[1].matematyka = 1; p[1].pedahohika = 1;
            Assert::AreEqual(50.0, PercentFizyka4abo5(p, 2), 1e-9);
        }
    };

    // ---------- SpecialnistToString ----------
    TEST_CLASS(SpecialnistToStringTests)
    {
    public:
        TEST_METHOD(KilkistSpecialnostej)
        {
            Assert::AreEqual(5, KILKIST_SPECIALNOSTEI);
        }

        TEST_METHOD(NazvyUsihSpecialnostej)
        {
            Assert::AreEqual(string("Комп'ютерні науки"), SpecialnistToString(KN));
            Assert::AreEqual(string("Інформатика"), SpecialnistToString(INF));
            Assert::AreEqual(string("Математика та економіка"), SpecialnistToString(ME));
            Assert::AreEqual(string("Фізика та інформатика"), SpecialnistToString(FI));
            Assert::AreEqual(string("Трудове навчання"), SpecialnistToString(TN));
        }

        TEST_METHOD(ZnachennyaPerelikuIdutPoPoryadku)
        {
            Assert::AreEqual(0, (int)KN);
            Assert::AreEqual(1, (int)INF);
            Assert::AreEqual(2, (int)ME);
            Assert::AreEqual(3, (int)FI);
            Assert::AreEqual(4, (int)TN);
        }
    };
}
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;
enum Specialnist { KOMPUTERNI_NAUKY, INFORMATYKA, MATEMATYKA_TA_EKONOMIKA, PHISYKA_TA_INFORMATYKA, KIBERBEZPEKA };
string specialnistStr[] = { "КН", "інф", "мат&екон", "фіз&інф", "кібербезпека" };
struct Student
{
    string prizv;
    unsigned kurs;
    Specialnist specialnist;
    unsigned physics;
    unsigned math;
    union
    {
        unsigned programuvannia;
        unsigned chiselni_metody;
        unsigned pedagogika;
    };

};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Kilkist_otsinok(Student* p, const int N);
double five_four(Student* p, const int N);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    cout << "Введіть N: "; cin >> N;
    Student* p = new Student[N];
    Create(p, N);
    Print(p, N);
    Kilkist_otsinok(p, N);
    five_four(p, N);
    return 0;
}
void Create(Student* p, const int N)
{
    int specialnist;

    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << " прізвище: "; getline(cin, p[i].prizv);
        cout << " курс: "; cin >> p[i].kurs;
        cout << " спеціальність (0 - комп'ютерні науки, 1 - інформатика, 2 - математика та економіка, 3 - фізика та інформатика, 4 - кібербезпека):";
        cin >> specialnist;
        cout << " оцінка з фізики: "; cin >> p[i].physics;
        cout << "оцінка з математики: "; cin >> p[i].math;
        p[i].specialnist = Specialnist(specialnist);
        switch (p[i].specialnist)
        {
        case KOMPUTERNI_NAUKY:
            cout << " оцінка з програмування : "; cin >> p[i].programuvannia;
            break;
        case INFORMATYKA:
            cout << "оцінка з чисельних методів: "; cin >> p[i].chiselni_metody;
            break;
        case MATEMATYKA_TA_EKONOMIKA:
        case PHISYKA_TA_INFORMATYKA:
        case KIBERBEZPEKA:
            cout << " оцінка з педагогігики : "; cin >> p[i].pedagogika;
            break;
            cout << endl;
        }
    }
}
void Print(Student* p, const int N)
{
    cout << "========================================================================================================"
        << endl;
    cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Програмування | Чис. методи | Педагогіка |"
        << endl;
    cout << "--------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(1) << right << i + 1 << " ";
        cout << "| " << setw(9) << left << p[i].prizv
            << "| " << setw(4) << right << p[i].kurs << " "
            << "| " << setw(14) << left << specialnistStr[p[i].specialnist]
            << "| " << setw(6) << right << p[i].physics << " "
            << "| " << setw(10) << left << p[i].math << " ";
        switch (p[i].specialnist)
        {
        case KOMPUTERNI_NAUKY:
            cout << "| " << setw(13) << right << p[i].programuvannia << " " << "|" << setw(14) << "|" << setw(13) << "|";
            break;
        case INFORMATYKA:
            cout << "|" << setw(16) << right << fixed << "|" << setw(13) << left << p[i].chiselni_metody << "|" << setw(11) << right << " " << " |";
            break;
        case MATEMATYKA_TA_EKONOMIKA:
        case PHISYKA_TA_INFORMATYKA:
        case KIBERBEZPEKA:
            cout << "|" << setw(17) << right << fixed << "| " << setw(12) << left << " " << "| " << setw(11) << right << p[i].pedagogika << "|";
            break;
            cout << endl;
        }
    }
    cout << "========================================================================================================"
        << endl;
    cout << endl;
}
void Kilkist_otsinok(Student* p, const int N)
{
    int k = 0;
    int m = 0;
    int t = 0;
    int l = 0;
    int h = 0;
    for (int i = 0; i < N; i++)
    {
        if (p[i].physics == 3)
            k++;
        if (p[i].math == 3)
            m++;
        if (p[i].programuvannia == 3)
            t++;
        if (p[i].chiselni_metody == 3)
            l++;
        if (p[i].pedagogika == 3)
            h++;

    }
    cout << "кількість оцінок задовільно з фізики: " << k << endl;
    cout << "кількість оцінок задовільно з математики: " << m << endl;
    cout << "кількість оцінок задовільно з інформатики: " << t << endl;

}
double five_four(Student* p, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (p[i].physics == 5 || p[i].physics == 4)
            if (p[i].math == 5 || p[i].math == 4)
            {
                k++;
                cout << "Студенти, які мають 4 або 5 з математики та фізики: " << p[i].prizv << endl;
                return 0;
            }
}
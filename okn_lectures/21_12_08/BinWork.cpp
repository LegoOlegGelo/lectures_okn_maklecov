#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

int main()
{
    /*
    ofstream f("bin.txt", ios_base::in | ios_base::out);

    if (f.is_open())
    {
        int a = 0x96;

        f.write((const char*)&a, sizeof(a));

        f.close();
    }
    else
        cout << "Файл не удалось открыть" << endl;


    ifstream fin("bin.txt", ios_base::binary);

    if (fin.is_open())
    {
        int a;
        fin.read((char*)&a, sizeof(a));
        
        cout << a << endl;
    }
    */

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");

    struct student
    {
        char lastname[30]; // поле структуры
        char firstname[30];
        char address[100];
        char phone[15];
        int ege;
    };

    student arsenii = { "Гусаров", "Арсений", "Где-то на дубравной", "8989819182", 300 };
    cout << arsenii.firstname << " - " << arsenii.ege << " Живет: " << arsenii.address << endl;

    student* ars = &arsenii;
    cout << ars->lastname << endl;

    ofstream f("data.dat");
    f.write((const char*)ars, sizeof(*ars));
    f.close();

    return 0;
}

#include <iostream>

using namespace std;

int nod(int a, int b)
{
    if (a < b)
    {
        int c = a;
        a = b;
        b = c;   
    }

    int ost = 1;

    while (ost > 0)
    {
        ost = a % b;
        a = b;
        b = ost;
    }

    return a;
}

int nok(int a, int b)
{
    return a * b / nod(a, b);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int x = 10, y = 15;

    cout << nok(10, 15) << endl << nod (10, 15) << endl;

    return 0;
}
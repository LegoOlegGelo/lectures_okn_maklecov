#include <iostream>

using namespace std;

int swap(int a)
{
    int swapped = 0;

    while(a > 0)
    {
        swapped *= 10;
        swapped += (a % 10);
        a /= 10;
    }

    return swapped;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int a = 1234;
    a = swap(a);
    cout << a << endl;

    while(a > 0)
    {
        cout << a % 10 << " ";
        a /= 10;
    }

    cout << endl << endl;

    return 0;
}
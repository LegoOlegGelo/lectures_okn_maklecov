#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;

    int c = 0, n = 0, a1;
    
    // определить есть ли в числе повторяющиеся числа
    //
    //
    //
    //
    //
    // ---

    while(a > 0)
    {
        c = n;
        n = a % 10;
        a /= 10;
        if (c == n)
        {
            cout << "DA" << endl;
            return 0;
        }
    }

    cout << "NET" << endl << endl;
    return 0;
}
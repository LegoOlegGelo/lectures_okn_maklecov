#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    int A[10];
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        A[i] = -10 + rand() % 21;
    }    

    for (int i = 0; i < 10; i++)
        cout << A[i] << ' ';

    int min = 0, max = 0;
    int min_i = A[0], max_i = A[0];

    for (int i = 1; i < 10; i++)
    {
        if (A[i] < min)
        {
            min = A[i]; min_i = i;
        }

        if (A[i] > max)
        {
            max = A[i]; max_i = i;
        }
    }

    cout << endl << "min, min index: " << min << " " << min_i;
    cout << endl << "max, max index: " << max << " " << max_i << endl;

    return 0;
}
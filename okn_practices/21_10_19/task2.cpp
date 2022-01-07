#include <iostream>

using namespace std;

// РЕШЕНИЕ ДЛЯ ОБЩЕГО СЛУЧАЯ, В ТОМ ЧИСЛЕ И ДЛЯ N = 10, parts = 2

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    int N, parts; // N - кол-во элементов, parts - на сколько частей делить массив
    cin >> N >> parts;

    int* A = new int[N];

    for (int i = 0; i < N; i++)
    {
        A[i] = -10 + rand() % 21;
    }    

    for (int i = 0; i < N; i++)
        cout << A[i] << ' ';


    for (int i = 0; i < parts; i++)
        for (int j = 0; j < N / parts / 2; j++)
        {
            int c = A[i * (N / parts) + j];
            A[i * (N / parts) + j] = A[i * (N / parts) + (N / parts) - 1 - j];
            A[i * (N / parts) + (N / parts) - 1 - j] = c;
        }

    cout << endl << endl;
    for (int i = 0; i < N; i++)
        cout << A[i] << ' ';
    
    cout << endl << endl;

    return 0;
}
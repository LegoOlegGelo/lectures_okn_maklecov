#include <iostream>

using namespace std;

void rnd_perm(int* arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        // случ int
        arr[i] = 1 + rand() % size;
        
        // если такой элемент уже был раньше,
        // уменьшаем i, чтобы перезаписался arr[i]
        for (int j = 0; j < i; j++)
            if (arr[j] == arr[i])
            {
                i--;
                break;
            }
    }
}

int main()
{
    srand(time(NULL));
    int* A = new int[6];
    rnd_perm(A, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << "Ход #" << i << endl;
        cin.get();
        
        if (A[i] == 6)
        {
            cout << "вы мертвы" << endl;
            break;
        }
        else
            cout << "следующий ход" << endl;
    }

    delete[] A;
    return 0;
}
#include <iostream>

using namespace std;

void rnd_arr(int* arr, const int size)
{
    for (int i = 0; i < size; i++)
        *(arr++) = 10 + rand() % 90;
}

void sort(int* arr, const int size, int begin, int end)
{
    for (int i = begin; i < end; i++)
    {
        int min = arr[i];
        int ind_min = i;

        for (int j = i + 1; j < end; j++)
            if (arr[j] < min)
            {
                min = arr[j];
                ind_min = j;
            }
        
        int tmp = arr[i];
        arr[i] = min;
        arr[ind_min] = tmp;
    }
}

void sort_by_2_digit(int* arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = arr[i];
        int ind_min = i;

        for (int j = i + 1; j < size; j++)
            if (arr[j] % 10 < min % 10)
            {
                min = arr[j];
                ind_min = j;
            }
        
        int tmp = arr[i];
        arr[i] = min;
        arr[ind_min] = tmp;
    }
}
 
void print_array(int array[], const int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    
    cout << endl;
}

int main()
{
    srand(time(NULL));
    int size;
    cin >> size;
    int* A = new int[size];

    // task 5
    rnd_arr(A, size);
    print_array(A, size);
    
    for (int i = 0; i < 2; i++)
        sort(A, size, i * size / 2, (i + 1) * size / 2);

    print_array(A, size);

    cout << endl;

    // task 4
    rnd_arr(A, size);
    print_array(A, size);
    
    sort_by_2_digit(A, size);

    print_array(A, size);


    delete[] A;
    return 0;
}
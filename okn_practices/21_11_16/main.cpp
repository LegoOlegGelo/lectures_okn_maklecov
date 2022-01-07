#include <iostream>
#include <string>

using namespace std;

void print_array(int array[], const int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    
    cout << endl;
}

void rnd_arr(int* arr, const int size)
{
    for (int i = 0; i < size; i++)
        *(arr++) = 0 + rand() % 20;
}

template <typename T>
int get_len(T x)
{
    T frac = x - (int)x;
    int whole = (int)x;
    int len = 0;

    while (whole > 0)
    {
        whole /= 10;
        len++;
    }

    int dop = 1 if (x - (int)x > 0);

    return len + 1 + dop;
}

template <typename T>
void fill_digits(T* X, T x, int size)
{
    int whole = (int)x;
    T fraction = x - whole;
    int stop = size;

    for (int i = size - 1; i >= 0; i--)
    {
        X[i] = whole % 10;
        whole /= 10;
        
        if (whole == 0)
        {
            stop = i - 1;
            break;
        }
    }

    if (fraction != 0)
    {
        X[stop] = -1;
    }

    while (fraction > 0)
    {
        fraction *= 10;
        whole = whole * 10 + (int)fraction % 10;
        fraction -= (int)fraction % 10;
    }

    for (int i = size - 1; i >= 0; i--)
    {
        X[i] = whole % 10;
        whole /= 10;
    }

}

template <typename T>
bool check_items(T a, T b)
{
    //return to_string(a) > to_string(b); // решение в одну строчку

    int len_a = get_len(a), len_b = get_len(b);

    int* A = new int[len_a];
    int* B = new int[len_b];

    fill_digits(A, a, len_a);
    fill_digits(B, b, len_b);

    

    return false;
}

template <typename T>
void sort_bubble(T* A, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++)
            if (check_items(A[j], A[j + 1]))
            {
                T c = A[j];
                A[j] = A[j + 1];
                A[j + 1] = c;
            }
}

int main()
{
    srand(time(NULL));
    int size;
    cin >> size;

    int* A = new int[size];

    rnd_arr(A, size);
    sort_bubble(A, size);
    print_array(A, size);

    delete[] A;
    return 0;
}
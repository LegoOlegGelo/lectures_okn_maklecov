#include <iostream>

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
        *(arr++) = 0 + rand() % 10;
}

void rnd_perm(int* arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 1 + rand() % size;
        
        for (int j = 0; j < i; j++)
            if (arr[j] == arr[i])
            {
                i--;
                break;
            }
    }
}

void sdvig_vlevo(int *array, int begin, int end) {
    int tmp = array[begin];
    for (int i = begin; i < end; i++){
        array[i] = array[i + 1];
    }
    array[end] = tmp;
}
void sdvig_vpravo(int *array, int begin, int end) {
    int tmp = array[end];
    for (int i = end-1; i >= begin; i--){
        array[i + 1] = array[i];
    }
    array[begin] = tmp;
}

void quicksort(int *array, int begin, int end) {
    int mid = (end + begin) / 2;

    if (end - begin < 1 || end < 0)
        return;

    for (int i = begin; i < mid; i++)
        if (array[i] > array[mid] && i < mid) {
            sdvig_vlevo(array, i, mid);
            i--;
            mid--;
        }

    for (int i = mid + 1; i < end; i++)
        if (array[i] <= array[mid] && i > mid) {
            sdvig_vpravo(array, mid, i);
            mid++;
        }

    quicksort(array, begin, mid);
    quicksort(array, mid + 1, end);
}

int main()
{
    srand(time(NULL));
    int size = 10;
    cin >> size;
    int* A = new int[size];

    cout << endl << "Проверка на случайной перестановке:" << endl;
    rnd_perm(A, size);
    print_array(A, size);
    quicksort(A, 0, size);
    print_array(A, size);

    cout << endl << "Проверка на случайном массиве:" << endl;
    rnd_arr(A, size);
    print_array(A, size);
    quicksort(A, 0, size);
    print_array(A, size);
    

    cout << endl;
    delete[] A;
    return 0;
}
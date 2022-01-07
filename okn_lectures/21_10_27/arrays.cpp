#include <iostream>
#include "arrays.h"

using namespace std;

void print_arr(double* arr, const int size)
{
    for (int i = 0; i < size; i++)
        cout << *(arr++) << " ";
    
    cout << endl;
}
#include <iostream>
#include "arrays.h"

#define PI 3.14159265

using namespace std;

int main()
{
    double* a = new double[10];

    for (int i = 0; i < 10; i++)
        a[i] = i + 1.0 / (i + 1);

    print_arr(a, 10);

    return 0;
}

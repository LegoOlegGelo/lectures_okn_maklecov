#include <iostream>

void swp(int& a, int& b)
{​​​​​​​​
    auto t = a;
    a = b;
    b = t;
}​​​​​​​​

void sort_by_min(int* a, int n)
{​​​​​​​​
    for (int i = 0; i < n - 1; i++)
    {​​​​​​​​
        for (int j = i + 1; j < n; j++)
        {​​​​​​​​
            if (a[i] > a[j])
            {​​​​​​​​
                swp(a[i], a[j]);
            }​​​​​​​​
        }​​​​​​​​
    }​​​​​​​​
}​​​​​​​​

void sort_bubble(int* a, int n)
{​​​​​​​​
    for (int i = 0; i < n; i++)
    {​​​​​​​​
        for (int j = 0; j < n - 1; j++)
        {​​​​​​​​
            if (a[j] > a[j + 1])
            {​​​​​​​​
                swp(a[j], a[j + 1]);
            }​​​​​​​​
        }​​​​​​​​
    }​​​​​​​​
}​​​​​​​​


void sort_quick(int* a, int n)
{​​​​​​​​
    int i = 0, j = n - 1;
    int v = a[n >> 1];
    do
    {​​​​​​​​
        while (a[i] < v) i++;
        while (a[j] > v) j--;
        if (i <= j)
        {​​​​​​​​
            if (i < j) 
                swp(a[i], a[j]);
            i++;
            j--;
        }​​​​​​​​
    }​​​​​​​​ while (i <= j); //a[i] = *(a+i)
    if (i < n - 1) sort_quick(a + i, n - i);
    if (j > 0) sort_quick(a, j + 1);
}​​​​​​​​

#include <iostream>

using namespace std;

int f(int x)
{
    return x * x;
}

int (*pf)(int x); // указатель на f(int x)

typedef int (*my_func_type)(int x); // создаем свой тип данных

void fff(my_func_type mf)
{
    cout << mf(5) << endl;
}

int main()
{
    pf = f;

    int a = 5;
    int* b = &a;

    my_func_type f1 = f;


    cout << pf(*b) << endl;

    return 0;
}
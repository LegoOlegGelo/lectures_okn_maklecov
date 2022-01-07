#include <iostream>

using namespace std;

template<typename T>
void f(T a)
{
    cout << a << endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    f<char>(65);
    f(5.0);
    f('a');

    int x = 10;
    printf("x = %d", x);
    // %d - int
    // %f - float
    // %lf - double
    // %c - char
    // %s - string
    // %ld - long long
    // %p - pointer
    // %x - вывод int в 16-ричной СС
    // %g - вывод вещественных целых в компактной записи (без запятой, если оно целое)

    // ОСТАНОВИЛИСЬ НА: функции с произвольным количеством параметров


    return 0;
}
#include <iostream>

using namespace std;

void hanoi(int n, int to, int from)
{
    if (n == 0) return;

    int p = 6 - to - from;

    hanoi(n-1, to, p);
    cout << to << "->" << from << endl;
    hanoi(n-1, p, from);
}

void bin(int n)
{
    if (n <= 0) return;

    bin(n / 2);
    cout << n % 2;
}

int sum(int n)
{
    if (n < 10) return n;
    return sum(n / 10) + n % 10;
}

int nod(int n, int m)
{
    if (n == 0 || m == 0) return n + m;

    if (n > m) return nod(n - m, m);
    else return nod(n, m - n);
}

int factor(int x)
{
    if (x <= 1) return 1;
    return x * factor(x - 1);
}

int main()
{
    cout << factor(10) << endl;

    return 0;
}
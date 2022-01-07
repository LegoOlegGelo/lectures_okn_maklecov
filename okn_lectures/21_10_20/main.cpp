#include <iostream>
#include <cstdarg>

using namespace std;

int sum(int n, ...)
{
    int* arg = &n;

    int s = 0;

    for (int i = 0; i < n; i++)
    {
        s += *(++++arg);
    }

    return s;
}

double sum2(int n, ...)
{
    va_list arg;
    double res = 0;
    va_start(arg, n);

    for (int i = 0; i < n; i++)
    {
        res += va_arg(arg, double);
    }

    va_end(arg);
    return res;
}

double sum3(const char* arg_types, ...)
{
    double res = 0.;

    va_list arg;
    va_start(arg, arg_types);

    for (const char* c = arg_types; *c; c++)
    {
        switch (*c)
        {
            case 'i': res += va_arg(arg, int); break;
            case 'd': res += va_arg(arg, double); break;
            case 'c': res += va_arg(arg, int); break;
            // case 'f': res += va_arg(arg, float); break;
            
            default: break;
        }
    }

    va_end(arg);
    return res;
}

int main()
{
    cout << sum(5, 1, 1, 1, 1, 1) << endl;

    // cout << (int)'a' << endl;
    // cout << sum3("idc", 2, 3.3, 'a') << endl;

    return 0;
}

/*



*/
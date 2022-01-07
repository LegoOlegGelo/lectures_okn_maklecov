#include <iostream>
#include "test.h"
#include <fstream>
#include <cstdarg>

using namespace std;

int my_pow(int& x, int& degree);

template <typename T>
T multiply(T a, T b)
{
    return a * b;
}

int m2(int x) { return 2 * x; }
int m3(int x) { return 3 * x; }

int (*f_ptr)(int x);
typedef int (*my_func_type)(int x);

int sum_many(int count, ...);
int sum_many2(int count, ...);

int main()
{
    cout << "Hello, World!" << endl;

    int x, y;

    // ввод вывод в стиле C, C++
    cin >> x >> y;
    cout << "Sum = " << Sum(x, y) << endl;

    scanf_s("%d %d", &x, &y);
    printf_s("x = %d, y = %d", x, y);

    // типы данных
    int a1;
    float a2;
    double a3;
    char a4;
    bool a5;

    // константы
    const float PI = 3.14159;
    const char ONE = '1';

    // область видимости переменных
    // (size_t i существует только внутри цикла)
    // int aaa существует в функции main
    int aaa = 5;
    for (size_t i = 0; i < 5; i++)
       cout << i << endl;

    // осн. операторы языка C
    // if, for, while, switch

    // указатели
    int* a1_ptr = &a1;

    // выделение и очищение памяти в куче
    int* b1 = new int[64];
    delete[] b1;

    // функции
    cout << "x^y = " << pow(x, y) << endl;

    // формальные и фактические параметры
    // фактические x и y в выражении:
    int res = my_pow(x, y);
    // формальные a, b:
    // int my_func(int a, int b) { ... }

    // ссылки
    int& a_ref = aaa;

    // передача параметров в функцию:
    // 1. по значению:
    //    int func_value(int a) { ... }
    //    int main() { int x = 5; func_value(x); }
    // 2. по ссылке:
    //    int func_ref(int& a) { ... }
    //    int main() { int x = 5; func_ref(x); }
    // 3. по указателю:
    //    int func_ptr(int* a, int* b) { ... }
    //    int main() { int* x = 5; int y = 3; func_ptr(x, &y); }

    // перегрузка функций
    int s1 = Sum(x, y);
    int s2 = Sum(x, y, aaa);

    // шаблоны функций
    float xf = 3.83, yf = 5.5;
    int si = multiply(x, y);
    float sf = multiply(xf, yf);

    // указатели на функции
    // объявление вверху до функции main
    f_ptr = m2;
    cout << f_ptr(5) << endl;
    my_func_type f2 = m2;
    cout << f2(5) << endl;

    // статический массив
    int arr_static[32];
    // динамический массив
    int* arr_dynamic = new int[64];
    delete[] arr_dynamic;

    // указатель на указатель
    int** arr = new int* [64];
    for (size_t i = 0; i < 64; i++)
       arr[i] = new int[64];

    // строка как массив символов
    char* str1 = new char[256];
    delete[] str1;

    // функции для работы со строками
    // strlen, strtok_s, strcpy_s, strcat_s, sprintf_s, sscanf_s

    // strtok_s:
    char* str2 = new char[256];
    gets_s(str2, 255);
    char* str2_copy = str2;
    char* context = new char[256];
    while (char* part = strtok_s(str2_copy, ",", &context))
    {
       cout << part << " - ";
       str2_copy = nullptr;
    }
    delete[] str2;

    // работа с файлами
    // C++
    ifstream inf("test.dat", ios_base::in | ios_base::binary);
    ofstream fout("out.txt");
    fstream fs("super.txt");
    bool bool1 = inf.is_open();
    inf.seekg(0, ios_base::end); // beg - begin; end - end; cur - current
    int file_len = inf.tellg();
    inf.seekg(0, ios_base::beg);
    while (!inf.eof()) { char a; inf >> a; /* ... */ }
    inf.close();
    // C
    FILE* f;
    f = fopen("c_test.txt", "r");
    while (!feof(f)) { char a; fscanf_s(f, "%c", &a); /* ... */ }
    fclose(f);

    // структурированные типы данных
    struct book
    {
       char name[100];
       char author[50];
       int sheets_count;
    };
    // 1ый способ
    book* war_and_peace = new book;
    war_and_peace->sheets_count = 1250;
    char author[] = "Leo Tolstoy";
    for (size_t i = 0; i < strlen(author) + 1; i++)
       war_and_peace->author[i] = author[i];
    // 2ой способ
    book dead_souls = { "Мертвые души", "Н. В. Гоголь", 450 };

    int result = sum_many2(3, 1, 2, 3);
    cout << result << endl;

    

    // прочее
    cout << sum_many(5, 1, 2, 3, 4, 5) << endl;
    cout << sizeof(int*) << endl;

    struct my_struct
    {
        int a;
        int b;
        double c;
        char d[50];
    };

    cout << sizeof(my_struct*) << endl;
    cout << sizeof(double) << endl;
    
    return 0;
}

int my_pow(int& x, int& degree)
{
    int res = 1;

    for (size_t i = 0; i < degree; i++)
        res *= x;

    return res;
}

// функции с переменным кол-вом параметров
// вызов функции: sum_many(3, 7, 8, 5); // где 3 - кол-во параметров
int sum_many(int count, ...)
{
    int* arg = &count;
    int s = 0;

    for (size_t i = 0; i < count; i++)
    {
        arg += sizeof(int*) / 4;
        s += *arg;
    }

    return s;
}

int sum_many2(int count, ...)
{
    va_list arg;
    va_start(arg, count);

    int s = 0;

    for (size_t i = 0; i < count; i++)
        s += va_arg(arg, int);

    return s;
}
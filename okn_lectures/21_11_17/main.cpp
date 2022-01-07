#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    // for windows:
    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);

    char* str = new char[256];

    cin >> str;
    cout << str << endl;

    str[0] = 'o';
    str[1] = 'a';
    str[2] = 0; // нуль-символ (терминальный ноль)

    const char* s = "abcdef";

    int size = strlen(s); // strlen на лекции есть, а у меня нет :(
    cout << size;

    strcpy(); // копирование строк
    strcat_s(); // конкатенация строк
    sprintf_s(); // вывод строки
    sscanf_s(); // ввод строки 

    return 0;
}
#include <iostream>
#include <string.h>

using namespace std;

// strtok(); // деление строки по символам

int get_sum(const char* s)
{
    char* s_copy = new char[strlen(s) + 1];
    strcpy(s_copy, s);
    char* context;
    char* temp = s_copy;

    int sum = 0;

    while (char* part = strtok(temp, " ", &context))
    {
        // sum += stoi(part);
        // sum += atoi(part);
        sum += sscanf(part, "%d", &a);


        temp = nullptr;
    }


    delete[] s_copy;
    return sum;
}

int main()
{
    setlocale(LC_ALL, "Rus");

    const char* str = "11 2 33 4 55 6 7 88 999";

    cout << get_sum(str) << endl;

    return 0;
}
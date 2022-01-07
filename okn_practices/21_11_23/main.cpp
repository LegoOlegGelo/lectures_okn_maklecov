#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    // setlocale(LC_ALL, "Rus");

    // cout << strlen("abcde") << endl;

    // cout << strcmp("AA", "A") << endl; // возвращает разность первой и второй строк


    char word[256];
    cin >> word;
    int dots_count = 0;
    char html[] = ".html";

    int i = 0;
    while (word[i])
    {
        if (word[i] == '.')
            dots_count++;
        i++;
    }

    if (dots_count == 0)
    {
        word[i] = '.';
        strcpy(word+i, html);
    }
    else
    {
        i = 0; cnt = 0;
        while (word[i])
        {
            if (word[i] == '.')
                cnt++;
            i++;

            if (cnt == counter)
            {
                
                i--;
            }
        }
    }

    cout << word << endl;

    return 0;
}
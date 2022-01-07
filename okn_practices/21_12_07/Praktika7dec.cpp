#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

// strstr() - первое вхождение в строку

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream fin("test.txt"); // можно сразу открывать
    ofstream fout("out.txt"); // можно сразу открывать
    
    if (!fin.is_open())
    {
        cout << "no file" << endl;
        return -1;
    }

    char parasit[] = ", короче,";
    /*char* text = new char[1024 * 4];

    int counter = 0;
    while (!fin.eof())
    {
        char x;
        fin >> x;
        text[counter++] = x;
    }

    text[counter] = 0;

    cout << text << endl;

    fin.close();*/

    char text[] = "мама, короче, мама";

    for (int i = 0; i < strlen(text); i++)
    {
        if (parasit[0] == text[i])
        {
            bool is_parasit = true;

            for (int j = 0; j < strlen(parasit); j++)
                if (parasit[j] != text[i + j])
                {
                    is_parasit = false;
                    break;
                }
                else
                {
                    is_parasit = true;
                }
            
            if (is_parasit)
                continue;
        }
        
        fout << text[i];
    }

    fout.close();

    return 0;
}
#include <iostream>
#include <fstream>

using namespace std;

int main2()
{
    fstream f("test.txt", ios_base::in | ios_base::out);
    
    if (f.is_open())
    {
        while (!f.eof())
        {
            int a;
            f >> a;

            if (f.fail())
            {
                f.clear();
                // seekp и seekg (отступ, от чего отступ)
                f.seekp(f.tellg(), ios_base::beg); // перед сменой направления потока fstream нужно ставить курсор :(
                f << " ";
                f.seekg(f.tellp(), ios_base::beg);
            }
            else
                cout << a << " ";
        }

        f.close();
    }
    else
        cout << "Файл не удалось открыть" << endl;

    return 0;
}

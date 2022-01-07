#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    // c++ стиль
    ifstream fi;
    ofstream fo;

    // второй параметр необязательный в данном случае
    fi.open("test.txt", ios_base::in);

    // по умолчанию используется режим 'w' (ios_base::trunc)
    fo.open("out.txt", ios_base::out | ios_base::trunc);

    // app - append (дозапись)
    //fo.open("out.txt", ios_base::out | ios_base::app);


    if (fi.is_open() && fo.is_open())
    {
        //char* a = new char[256];
        int a;

        fi.seekg(0, ios_base::end);
        streampos end_pos = fi.tellg();

        fi.seekg(0, ios_base::beg);

        while (!fi.eof())
        {
            fi >> a;

            if (fi.fail())
            {
                fi.clear();
                fi.seekg(1, ios_base::cur); // ios_base::beg, ios_base::end
                
                if (fi.tellg() >= end_pos)
                    break;
                
                continue;
            }

            fo << a << endl << endl;
            cout << a << " ";
        }
    }

    fi.close();
    fo.close();


    fstream f;

    f.open("test.txt");



    f.close();

    return 0;
}
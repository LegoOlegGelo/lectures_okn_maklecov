#include <iostream>
#include <fstream>

using namespace std;

int main1()
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
        int a;

        while (!fi.eof())
        {
            fi >> a;

            if (fi.fail())
                continue;

            fo << a << endl << endl;
            cout << a << " ";
        }
    }

    fi.close();
    fo.close();

    return 0;
}
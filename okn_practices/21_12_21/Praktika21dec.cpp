#include <iostream>
#include <fstream>

using namespace std;

struct man {
    int age;
    char name[50];
};

int get_count_of_men(int bytes)
{
    return bytes / sizeof(man);
}

int main()
{
    ifstream fin("input.dat", ios_base::binary | ios_base::in);
    ofstream fout("input.dat", ios_base::binary | ios_base::out);

    man a = { 18, "Oleg" };
    cout << a.name << endl;

    if (fin.is_open())
    {
        fin.seekg(0, ios_base::end);
        int bytes_count = fin.tellg();
        fin.seekg(0, ios_base::beg);

        int count = get_count_of_men(bytes_count);

        while (!fin.eof())
        {
            int b;
            fin.read((char*)&b, sizeof(b));
            cout << b << " ";

            if (fout.is_open())
            {

            }
            else
            {
                cout << "тех поддержка 8" << endl;
            }
        }
    }
    else
    {
        cout << "8 800 555 35 35" << endl;
    }

    char* tmp;
    
    while (char* part = )

    fin.close();

    return 0;
}
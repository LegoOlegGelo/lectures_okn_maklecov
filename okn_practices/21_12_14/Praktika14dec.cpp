#include <iostream>
#include <fstream>

using namespace std;

int main1()
{
    ifstream inf("input.txt");
    ofstream outf("output.txt");


    if (inf.is_open())
    {
        int first;
        inf >> first;
        inf.seekg(0, ios_base::beg);

        int min = first, max = first, sum = 0, count = 0;

        inf.seekg(0, ios_base::end);
        streampos end_pos = inf.tellg();
        inf.seekg(0, ios_base::beg);

        int a;

        while (!inf.eof())
        {
            inf >> a;

            if (inf.fail())
            {
                inf.clear();
                inf.seekg(1, ios_base::cur);

                if (inf.tellg() >= end_pos)
                    break;

                continue;
            }

            count++;
            sum += a;

            if (a < min) min = a;
            else if (a > max) max = a;
        }

        outf << "min: " << min << "; max: " << max << "; mean: " << (double)sum / count << endl;
    }

    inf.close();
    outf.close();

    return 0;
}

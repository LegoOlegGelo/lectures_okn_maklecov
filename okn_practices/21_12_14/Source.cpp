#include <iostream>
#include <fstream>

using namespace std;


void sdvig_vlevo(int* array, int begin, int end) {
    int tmp = array[begin];
    for (int i = begin; i < end; i++) {
        array[i] = array[i + 1];
    }
    array[end] = tmp;
}

void sdvig_vpravo(int* array, int begin, int end) {
    int tmp = array[end];
    for (int i = end - 1; i >= begin; i--) {
        array[i + 1] = array[i];
    }
    array[begin] = tmp;
}

void quicksort(int* array, int begin, int end) {
    int mid = (end + begin) / 2;

    if (end - begin < 1 || end < 0)
        return;

    for (int i = begin; i < mid; i++)
        if (array[i] > array[mid] && i < mid) {
            sdvig_vlevo(array, i, mid);
            i--;
            mid--;
        }

    for (int i = mid + 1; i < end; i++)
        if (array[i] <= array[mid] && i > mid) {
            sdvig_vpravo(array, mid, i);
            mid++;
        }

    quicksort(array, begin, mid);
    quicksort(array, mid + 1, end);
}


int main()
{
    ifstream inf("input.txt");
    ofstream outf("output.txt");

    int* arr = new int[100];
    int count = 0;

    if (inf.is_open())
    {
        inf.seekg(0, ios_base::end);
        streampos end_pos = inf.tellg();
        inf.seekg(0, ios_base::beg);

        int a;

        while (!inf.eof())
        {
            inf >> arr[count];

            if (inf.fail())
            {
                inf.clear();
                inf.seekg(1, ios_base::cur);

                if (inf.tellg() >= end_pos)
                    break;

                continue;
            }

            count++;
        }

        quicksort(arr, 0, count);

        if (outf.is_open())
        {
            for (int i = 0; i < count; i++)
            {
                outf << arr[i] << " ";
            }
        }
    }

    inf.close();
    outf.close();

    return 0;
}
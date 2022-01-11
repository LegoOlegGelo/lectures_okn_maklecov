#include <iostream>
#include <fstream>

using namespace std;

struct point
{
    int X;
    int Y;
};

float get_len(point a, point b)
{
    int dx = a.X - b.X;
    int dy = a.Y - b.Y;

    return sqrt(dx * dx + dy * dy);
}

float get_perimeter(point a, point b, point c)
{
    return get_len(a, b) + get_len(a, c) + get_len(b, c);
}

int main()
{
    // открытие, проверка данных
    ifstream fin("points.txt");
    
    if (!fin.is_open())
    {
        cout << "File open error" << endl;

        return -1;
    }
    
    int N = 0;

    fin.seekg(0, ios_base::end);
    int eof_index = fin.tellg();
    fin.seekg(0, ios_base::beg);

    while (!fin.eof())
    {
        int a;
        fin >> a;

        if (fin.fail())
        {
            fin.clear();
            fin.seekg(1, ios_base::cur);

            if (fin.tellg() >= eof_index)
                break;

            continue;
        }

        N++;
    }

    if (N % 2 == 1)
    {
        cout << "File contains invalid data" << endl;
        return -2;
    }

    N /= 2;

    if (N < 3)
    {
        cout << "File contains less than 3 points" << endl;
        return -3;
    }


    // чтение данных с файла
    point* points = new point[N];

    fin.seekg(0, ios_base::beg);

    int i = 0;
    while (!fin.eof() && i < N * 2)
    {
        int a;
        fin >> a;

        if (fin.fail())
        {
            fin.clear();
            fin.seekg(1, ios_base::cur);

            if (fin.tellg() >= eof_index)
                break;

            continue;
        }

        if (i % 2 == 0)
            points[i++ / 2].X = a;
        else
            points[i++ / 2].Y = a;
    }
    

    // вывод
    for (size_t i = 0; i < N; i++)
    {
        point p = points[i];
        cout << p.X << " " << p.Y << endl;
    }
    cout << endl;


    // перебор
    float max_perimeter = 0;
    int max_indexes[] = { 0, 0, 0 };

    for (size_t i = 0; i < N - 2; i++)
        for (size_t j = i + 1; j < N - 1; j++)
            for (size_t k = j + 1; k < N; k++)
            {
                float perim = get_perimeter(points[i], points[j], points[k]);
                if (perim > max_perimeter)
                {
                    max_perimeter = perim;
                    max_indexes[0] = i;
                    max_indexes[1] = j;
                    max_indexes[2] = k;
                }
            }


    // вывод результатов
    cout << "3 points with max perimeter = " << max_perimeter << endl;

    for (size_t i = 0; i < 3; i++)
    {
        point p = points[max_indexes[i]];

        cout << p.X << " " << p.Y << endl;
    }


    // очищение памяти, выход
    delete[] points;
    return 0;
}
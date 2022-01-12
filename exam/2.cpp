#include <iostream>
#include <fstream>

using namespace std;

float** read_matrix(int& rows, int& cols)
{
    rows = 0;
    cols = 0;

    ifstream fin("matrix.txt");

    if (!fin.is_open())
    {
        cout << "File open error";
        return nullptr;
    }

    // длина файла
    fin.seekg(0, ios_base::end);
    streampos eof_index = fin.tellg();
    fin.seekg(0, ios_base::beg);

    // количество элементов
    int elements_count = 0;
    while (!fin.eof())
    {
        float a;
        fin >> a;

        if (fin.fail())
        {
            fin.clear();
            fin.seekg(1, ios_base::cur);

            if (fin.tellg() >= eof_index)
                break;

            continue;
        }

        elements_count++;
    }

    // количество строк
    fin.seekg(0, ios_base::beg);
    char* tmp = new char[1024];
    while (!fin.eof())
    {
        fin.getline(tmp, 1023);
        
        if (strlen(tmp) > 0)
            rows++;
    }

    // количество столбцов
    cols = elements_count / rows;

    // создаем матрицу и возвращаем ее
    fin.seekg(0, ios_base::beg);

    float** matrix = new float*[rows];
    for (size_t i = 0; i < rows; i++)
        matrix[i] = new float[cols];
    
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
        {
            if (fin.eof())
            {
                cout << "Read file error" << endl;
                return nullptr;
            }

            fin >> matrix[i][j];
        }

    fin.close();

    return matrix;
}

float sub_norm(float** A, int M, int col)
{
    float res = 0;

    for (size_t i = 0; i < M; i++)
        res += abs(A[i][col]);

    return res;
}

float Norm1(float** A, int M, int N)
{
    float* sums = new float[N];

    for (size_t j = 0; j < N; j++)
        sums[j] = sub_norm(A, M, j);

    int max_i = 0;

    for (size_t i = 0; i < N; i++)
        if (sums[max_i] < sums[i])
            max_i = i;

    float maxx = sums[max_i];
    delete[] sums;
    return maxx;
}

void print_matrix(float** A, int M, int N)
{
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < N; j++)
            cout << A[i][j] << " ";

        cout << endl;
    }
}

int main()
{
    int M = 0, N = 0;
    float** matrix = read_matrix(M, N);

    if (matrix == nullptr)
        return -1;

    // вывод матрицы
    print_matrix(matrix, M, N);

    // норма
    cout << endl;
    cout << "Norm1 = " << Norm1(matrix, M, N) << endl;

    int K;
    cout << "K = ";
    cin >> K;

    for (size_t i = 1; i <= min(K, M); i++)
        cout << "K = " << i << "; Norm1 = " << Norm1(matrix, i, N) << endl;

    // нужно очистить память
    for (size_t i = 0; i < M; i++)
        delete[] matrix[i];

    delete[] matrix;
    return 0;
}

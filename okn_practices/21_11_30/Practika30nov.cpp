//#include <iostream>
//
//using namespace std;
//
//void print_matrix(int** matrix, int rows, int cols)
//{
//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 0; j < cols; j++)
//            cout << matrix[i][j] << " ";
//
//        cout << endl;
//    }
//}
//
//void random_matrix(int** matrix, int rows, int cols)
//{
//    for (int i = 0; i < rows; i++)
//        for (int j = 0; j < cols; j++)
//            matrix[i][j] = 10 + rand() % 90;
//}
//
//int sum(int* row, int len)
//{
//    int s = 0;
//
//    for (int i = 0; i < len; i++)
//        s += row[i];
//
//    return s;
//}
//
//void fill_1(int** matrix, int rows, int cols)
//{
//    int j_cache = 0;
//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 0; j < cols; j++)
//            matrix[i][j] = j + 1 + j_cache;
//
//        j_cache++;
//    }
//}
//
//void fill_2(int** matrix, int rows, int cols)
//{
//    int j_cache = 0;
//    for (int i = 0; i < rows; i++)
//    {
//        for (int j = 0; j < cols; j++)
//            matrix[i][j] = j + 1 + j_cache++;
//    }
//}
//
//void fill_3(int** matrix, int rows, int cols)
//{
//    int j_cache = 1;
//    for (int i = 0; i < rows; i++)
//    {
//        if (i % 2 == 0)
//            for (int j = 0; j < cols; j++)
//                matrix[i][j] = j_cache++;
//        else
//            for (int j = cols - 1; j >= 0; j--)
//                matrix[i][j] = j_cache++;
//    }
//}
//
//void fill_4(int** matrix, int rows, int cols)
//{
//    int j_cache = 1;
//
//    for (int j = 0; j < cols; j++)
//            if (j % 2 == 0)
//                for (int i = 0; i < rows; i++)
//                    matrix[i][j] = j_cache++;
//            else
//                for (int i = rows - 1; i >= 0; i--)
//                    matrix[i][j] = j_cache++;
//}
//
//int main1()
//{
//    setlocale(LC_ALL, "Rus");
//    srand(time(NULL));
//
//    int r = 5, c = 5;
//    int** matrix = new int* [r];
//
//    for (int i = 0; i < r; i++)
//        matrix[i] = new int[c];
//
//    random_matrix(matrix, r, c);
//    print_matrix(matrix, r, c);
//
//    int i_min = 0, j_min = 0;
//    for (int i = 0; i < r; i++)
//        for (int j = 0; j < c; j++)
//            if (matrix[i][j] < matrix[i_min][j_min])
//            {
//                i_min = i; j_min = j;
//            }
//
//    cout << "Ответ: " << matrix[i_min][j_min] << " : (i, j) = (" << i_min << ", " << j_min << ")" << endl;
//
//    cout << endl << endl;
//
//    return 0;
//
//    int maxsum = sum(matrix[0], c);
//    int i_max = 0;
//
//    for (int i = 1; i < r; i++)
//        if (sum(matrix[i], c) > maxsum)
//            i_max = i;
//
//    cout << maxsum << endl;
//
//    fill_1(matrix, r, c);
//    print_matrix(matrix, r, c);
//
//    cout << endl;
//
//    fill_2(matrix, r, c);
//    print_matrix(matrix, r, c);
//
//    cout << endl;
//
//    fill_3(matrix, r, c);
//    print_matrix(matrix, r, c);
//
//    cout << endl;
//
//    fill_4(matrix, r, c);
//    print_matrix(matrix, r, c);
//
//    for (int i = 0; i < r; i++)
//        delete[] matrix[i];
//
//    delete[] matrix;
//    return 0;
//}
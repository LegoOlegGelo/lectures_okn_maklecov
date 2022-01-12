#include <iostream>
#include <fstream>

using namespace std;

float** transpose_matrix(float** A, int rows, int cols)
{
	float** transposed = new float* [cols];

	for (size_t i = 0; i < cols; i++)
		transposed[i] = new float[rows];

	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			transposed[j][i] = A[i][j];

	return transposed;
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

void write_matrix(float** A, int M, int N)
{
	fstream f("transposed_matrix.dat", ios_base::out | ios_base::trunc | ios_base::binary);

	if (!f.is_open())
	{
		cout << "File open error" << endl;
		return;
	}

	f.write((const char*)&M, sizeof(int));
	f.write((const char*)&N, sizeof(int));

	for (size_t i = 0; i < M; i++)
		for (size_t j = 0; j < N; j++)
		{
			float el = A[i][j];
			f.write((const char*)&el, sizeof(float));
		}

	f.close();
}

bool check_eof_fail(ifstream& fin)
{
	if (fin.eof() || fin.fail())
	{
		cout << "File read error" << endl;
		return true;
	}

	return false;
}

float** read_matrix(int& rows, int& cols)
{
	ifstream fin("matrix.dat", ios_base::in | ios_base::binary);

	if (!fin.is_open())
	{
		cout << "File open error" << endl;
		return nullptr;
	}

	// rows
	if (check_eof_fail(fin))
		return nullptr;
	fin.read((char*)&rows, sizeof(int));

	// cols
	if (check_eof_fail(fin))
		return nullptr;
	fin.read((char*)&cols, sizeof(int));

	// matrix
	if (check_eof_fail(fin))
		return nullptr;

	float** matrix = new float* [rows];

	for (size_t i = 0; i < rows; i++)
		matrix[i] = new float[cols];

	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
		{
			float el = 0;
			fin.read((char*)&el, sizeof(float));
			matrix[i][j] = el;
		}

	fin.close();

	return matrix;
}

float** init_matrix(int rows, int cols)
{
	float** matrix = new float* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new float[cols];

		for (size_t j = 0; j < cols; j++)
			matrix[i][j] = 1 + j + i * cols;
	}

	return matrix;
}

int main()
{
	// чтение матрицы
	int rows = 3, cols = 5;

	float** matrix = read_matrix(rows, cols);
	//float** matrix = init_matrix(rows, cols);

	if (matrix == nullptr)
		return -1;

	print_matrix(matrix, rows, cols);
	cout << endl;

	// транспонирование и запись в файл
	float** transposed = transpose_matrix(matrix, rows, cols);
	print_matrix(transposed, cols, rows);
	write_matrix(transposed, cols, rows);

	// очищение памяти
	for (size_t i = 0; i < cols; i++)
		delete[] transposed[i];
	delete[] transposed;

	for (size_t i = 0; i < rows; i++)
		delete[] matrix[i];
	delete[] matrix;
	return 0;
}
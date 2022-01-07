#include <iostream>
#include "matrix_funcs.h"

using namespace std;

void print_matrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << matrix[i][j] << " ";

		cout << endl;
	}
}

void random_matrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			matrix[i][j] = 10 + rand() % 90;
}

int** create_matrix(int rows, int cols)
{
	if (rows * cols <= 0 || rows < 0)
		return nullptr;

	int** matrix = new int* [rows];

	for (int i = 0; i < rows; i++)
		matrix[i] = new int[cols];

	return matrix;
}

void delete_matrix(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		delete[] matrix[i];

	delete[] matrix;
}

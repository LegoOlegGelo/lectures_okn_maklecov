#include <iostream>
#include "matrix_funcs.h"

using namespace std;

int** transposition(int** A, int A_rows, int A_cols)
{
	int B_rows = A_cols, B_cols = A_rows;
	int** B = create_matrix(B_rows, B_cols);

	for (int i = 0; i < A_rows; i++)
		for (int j = 0; j < A_cols; j++)
			B[B_rows - 1 - j][B_cols - 1 - i] = A[i][j];

	return B;
}

int main()
{
	srand(time(NULL));

	int A_rows = 3, A_cols = 5;

	int** A = create_matrix(A_rows, A_cols);
	random_matrix(A, A_rows, A_cols);
	print_matrix(A, A_rows, A_cols);

	cout << endl;

	int** B = transposition(A, A_rows, A_cols);
	int B_rows = A_cols, B_cols = A_rows;
	print_matrix(B, B_rows, B_cols);

	// очищаем память
	delete_matrix(A, A_rows, A_cols);
	delete_matrix(B, B_rows, B_cols);
	return 0;
}
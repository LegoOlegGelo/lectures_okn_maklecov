#pragma once

#include "matrix_funcs.h"

void print_matrix(int** matrix, int rows, int cols);
void random_matrix(int** matrix, int rows, int cols);
int** create_matrix(int rows, int cols);
void delete_matrix(int** matrix, int rows, int cols);
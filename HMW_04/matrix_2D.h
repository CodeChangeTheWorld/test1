# ifndef MATRIX_2D_H
# define MATRIX_2D_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct matrix {
// Elements of the structure
	int rows;
	int cols;
	double **pt;
	char *tag;
	int status;
} matrix;


matrix matrix_constructor(int n1, int n2, char* tag);
void matrix_destructor(matrix* mat);
void matrix_set(matrix* mat, int row, int col, int val);
double matrix_get(matrix* mat, int row, int col, int val);
matrix matrix_add(matrix* m1, matrix* m2, char* tag);
matrix matrix_product(matrix* m1, matrix* m2, char* tag);
matrix matrix_read(char* filename, char* tag);
void matrix_write(matrix* m);

# endif
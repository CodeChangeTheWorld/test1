#include <stdio.h>   // printf, fopen, etc.
#include <stdlib.h>  // If one want to use malloc for array declaration
#include <string.h>  //for strstr
#include "matrix_2D.h"

matrix matrix_constructor(int n1, int n2, char* tag){

	struct matrix* m = (matrix *) malloc(sizeof(matrix));
	if(n1<1 || n2<1){
		m->rows = 0;
		m->cols = 0;
		m->status = 0;
		m->pt = NULL;
		return *m;
	}

	m->rows = n1;
	m->cols = n2;
	m->tag = tag;

	m->pt = (double **)malloc(n1 * sizeof(double *));

	for(int i= 0;i<n1;i++){
		m->pt[i] = (double *)malloc(n2 * sizeof(double));
	}
	m->status = 1;
	return *m;
}

void matrix_destructor(matrix* mat){
	int rows = mat->rows;
	for(int i=0;i<rows;i++){
		free(mat->pt[i]);
	}
	free(mat->pt);
	mat->rows = 0;
	mat->cols = 0;
	mat->status = 0; 
}

void matrix_set(matrix* mat, int row, int col, int val){
	mat->pt[row][col] = val;
}

double matrix_get(matrix* mat, int row, int col, int val){
	return mat->pt[row][col];
}

matrix matrix_add(matrix* m1, matrix* m2, char* tag){
	int row = m1->rows;
	int col = m1->cols;
	matrix m = matrix_constructor(row, col,tag);
	for(int i=0;i<row ;i++){
		for(int j=0;j<col;j++){
			m.pt[i][j] = m1->pt[i][j] + m2->pt[i][j];
		}
	}
	return m;
}

matrix matrix_product(matrix* m1, matrix* m2, char* tag){

	int m1_row = m1->rows; 
	int m1_col = m1->cols;
	int m2_row = m2->rows;
	int m2_col = m2->cols;
	matrix m = matrix_constructor(m1_row,m2_col,tag);
	int sum = 0;
	for(int i=0;i<m1_row;i++){
		for(int j=0;j<m1_col;j++){
			for(int k=0;k<m2_row;k++){
				sum += m1[i][j]*m2[j][k];
			}

			m.pt[i][j] = sum;
			sum = 0;
		}
	}
	m.tag = m1->tag;
	return m;
}

matrix matrix_read(char* filename, char* tag){

	FILE *fpt;
	fpt = fopen(filename, "r");
	int row, col;
	double value;
	fscanf(fpt,"%d",&row);
	fscanf(fpt,"%d",&col);
	matix m = matrix_constructor(row, col, tag);

	for (int i=0;i<row;i++){
		for(int j=0; j<col;j++){
			fscanf(fpt,"%lf", &value);
    		m.pt[i][j]=value;
		}
	}
	fclose(fpt);
    m.tag = tag;
    return m;
}

void matrix_write(matrix* m){
	FILE *fpt;
    fpt = fopen(m->tag, "w");
    fprintf(fpt, "%d %d \n", m->rows, m->cols);
    for(int i=0;i<m->rows;i++){
    	for(int j=0;j<m->cols;j++){
    		fprintf(fpt, "%lf ", m->pt[i][j]);
    	}

    	fprintf(fpt, "\n");
    }
    fclose(fpt);
}
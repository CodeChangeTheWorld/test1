#include "matrix_2D.h"

void matrix_swap_row(matrix *m, int n1, int n2){
	if(m->status != 1 || n1 >= m -> rows || n2 >= m->rows) return;
	for(int i=0; i<m->cols; i++){
		double d = m->pt[n1][i];
		m->pt[n1][i] = m->pt[n2][i];
		m->pt[n2][i] = d;
	}
	return;
}

void matrix_divide_row(matrix *m, double r, int n1){
	if(m->status != 1 || n1>= m->rows) return;
	for(int i=0; i<m->cols; i++){
		m->pt[n1][i] = (double)(m->pt)[n1][i]/r;
	}
	return;
}

void matrix_subtract_row(matrix *m, int n1, int n2, double r){
	if(m->status != 1 || n1 >= m -> rows || n2 >= m->rows) return;
	for(int i=0; i<m->cols; i++){
		m->pt[n1][i] -= (m->pt)[n2][i] * r;
	}
	return;
}
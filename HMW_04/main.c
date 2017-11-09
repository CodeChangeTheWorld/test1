#include "gauss_elimination.c"
#include "matrix_2D.h"

int main(){

	matrix ma = matrix_read("matrix_A", "ma");
	matrix mb = matrix_read("matrix_B", "mb");
	matrix maplusb = matrix_add(&ma, &mb, "maplusb");
	matrix maxb = matrix_product(&ma, &mb, "maxb");
	matrix ma_inverse = matrix_gauss_inverse(&ma, "ma_inverse");
	matrix_write(&maplusb);
	matrix_write(&maxb);
	matrix_write(&ma_inverse);
}
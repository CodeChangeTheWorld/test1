#include "matrix_gauss_inverse.c"


matrix matrix_gauss_inverse(matrix* m, char* tag){
	if(m->rows!=m->cols || m-> status != 1) return matrix_constructor(0 , 0, tag);
	matrix temp = matrix_constructor(m->rows, 2*m->cols,tag);
	matrix result = matrix_constructor(m->rows, m->rows,tag);
	result.tag = tag;
	int n = m->rows;
	int flag = 1;
	double d;
	//copy m into temp
	for(int i=0; i < n; i++){
		for(int j=0;j<n ; j++){
			temp.pt[i][j] = m->pt[i][j];
		}
		temp.pt[i][n+i] = 1;
	}

	/************** partial pivoting **************/
	for(int i= n-1;i >= 1;i--){
		if(temp.pt[i-1][0] <  temp.pt[i][0]){
			matrix_swap_row(&temp,i-1,i);
		}
	}

	/********** reducing to diagonal  matrix ***********/
	for (int i = 0; i < n; i++)
    {
    	//There is 0 in the pivot diagonal from which we know the matrix not invertible. 
    	if(temp.pt[i][i] == 0){
            flag = 0;
            break;
        } 

        for (int j = 0; j < n ; j++)
            if (j != i)
            {
                d = temp.pt[j][i] / temp.pt[i][i];
                matrix_subtract_row(&temp, j, i, d);	
            }
    }

    
    if(flag != 0){

    	/************** reducing to unit matrix *************/
	    for (int i = 1; i <= n; i++)
	    {
	        d = temp.pt[i][i];
	        matrix_divide_row(&temp, i,d);
	    }
	 	
	 	for (int i = 0; i < n; i++)
	    {
	        for (int j = n ; j < n * 2; j++)
	            result.pt[i][j-n] = temp.pt[i][j];
	    }
	}

	return result;

}


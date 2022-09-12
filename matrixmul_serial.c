#include<stdio.h>
#include<omp.h>

int main(){

     double start; 
     double end; 
     start = omp_get_wtime();
// Square Matrices
    // R1 = 4, C1 = 4 and R2 = 4, C2 = 4 (Update these values in MACROs)
    int mat1[4][4] = {
            {1, 1, 1, 1},
            {2, 2, 2, 2},
            {3, 3, 3, 3},
            {4, 4, 4, 4}
    };
 
    int mat2[4][4] = {
            {1, 1, 1, 1},
            {2, 2, 2, 2},
            {3, 3, 3, 3},
            {4, 4, 4, 4}
    };
    int mat3[4][4];
 for ( int i = 0; i < 4; i ++)
 {
 for ( int j = 0; j < 4; j ++)
  {
 mat[i ][ j] = 0.0;
 for ( int k = 0; k < 4; k ++)
 mat3[i ][ j] = mat3[i ][ j] + mat1[i ][ k] * mat2[k ][ j ];
 }
 }
     end = omp_get_wtime(); 
    printf("Work took %f seconds\n", end - start);
    return 0;
}

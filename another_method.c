#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <time.h>
#define N 100

int main()
{
     double start; 
     double end; 
     start = omp_get_wtime();
    double i_int = 0.0;
    double dx = 1.0 / N;

#pragma omp parallel for reduction(+:i_int)
    
    for (int i = 0; i < N; i++)
    {
        double x = i * dx;
        double fx = sqrt(1.0 - x * x);
        i_int = i_int + fx * dx;
    }

    double pi = 4 * i_int;
    
    printf("%20.40f\n", pi);
    end = omp_get_wtime(); 
    printf("Work took %f seconds\n", end - start);

}

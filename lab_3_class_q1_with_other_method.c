#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <time.h>
#define N 1000000000

int main()
{
    clock_t start, end;
    start = clock();
    double i_int = 0.0;
    double dx = 1.0 / N;

#pragma omp parelle for //reduction(+:i_int)
    
    for (int i = 0; i < N; i++)
    {
        double x = i * dx;
        double fx = sqrt(1.0 - x * x);
        i_int = i_int + fx * dx;
    }

    double pi = 4 * i_int;
    printf("%20.88f\n", pi);
    end = clock();
    double t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f\n",t);

}
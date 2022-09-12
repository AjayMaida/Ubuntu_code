#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    long double sum=0;
    clock_t start, end;
    start = clock();
#pragma omp parallel for
   // {
        //int tid = omp_get_thread_num();
        for (int i = 0; i < 1000000000; i++)
        {
            ++sum;
        }
       // printf("thread num : %d and the sum : %Lf\n", tid, sum);
   // }
    end = clock();
    double tim = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("final sum : %Lf   \n TIME IT TOOK IS %F\n", sum, tim);
    return 0;
}

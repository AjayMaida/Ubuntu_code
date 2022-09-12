#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
#pragma omp parallel
{
int tid=omp_get_thread_num();
int t_thread=omp_get_num_threads();
printf("hello world, from thread %d and total threads : %d\n",tid,t_thread);
}    
return 0;
}

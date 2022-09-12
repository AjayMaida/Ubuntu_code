#include <stdlib.h>
#include <omp.h>
#include <stdio.h>
#include <time.h>
#define siz 1000000000

int main()
{
    int i = 0;
    clock_t start, end;
    double tim;
    start = clock();
    long double psum = 1, sum = 0;
#pragma omp parallel private(i) shared(sum)
    {
        long double psum = 1;
        int tid = omp_get_thread_num();
        int nums = omp_get_num_threads();
        printf("total number of threads:%d\n", nums);
        // partitioning of loop for different process
        int from = (siz / nums) * tid;
        int to = (siz / nums) * (tid + 1) - 1; //-1 because indexing start with 0
        if (tid == nums - 1)
        {
            to = siz - 1;
        }
        // incase if number total iteration are not same last one will get more
        // printf("thread num: %d, from : %d to : %d and total thread: %d\n",tid,from,to,nums);
        for (i = from; i <= to; ++i)

        // for(int i=0;i<siz;i++)
        {
            psum++;
            // if (tid==0){printf("yes iam in loop: %Lf\n",psum);}
        }
// printf("sum of this thread num:%d and its sum : %Lf\n",tid,psum);
//#pragma omp critical
        sum += psum;
    }
    printf("Total sum till now : %Lf\n", sum);
    end = clock();
    tim = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("total sum : %Lf and total time %f\n", sum, tim);
    return 0;
}

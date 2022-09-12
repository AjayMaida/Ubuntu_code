#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

clock_t start,end;
double cpu_time_used;long double sum=1;
start=clock();
#pragma omp parallel for
   for (int i=1;i<10000000;i++){
   #pragma omp critical
    sum++;
    //   printf("%d: %d\n",omp_get_thread_num(),i);

       } 

 end=clock();
 cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
 printf("toatl sum : %Lf and total time it took : %f\n",sum,cpu_time_used);
return 0;
}

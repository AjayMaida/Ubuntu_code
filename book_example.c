#include<omp.h>
#include<stdio.h>
#include<math.h>

#define n 1000
int main(){

double final_integral, integral ;
double dx=1.0/n;
#pragma omp parallel
{
int tid=omp_get_thread_num();
int num_t=omp_get_num_threads();
printf("%d %d\n",num_t,tid);
#pragma omp parallel for
for(int i=0;i<n;i++)
{
double x=i*dx;
double fx=sqrt( 1.0 - x*x);
integral = integral +fx*dx;
}
final_integral = final_integral+integral;
}
double pi=4+final_integral;
printf("%20.80f\n",pi);
return 0;
}

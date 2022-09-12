#include<stdio.h>
#include<math.h>

#define N 100000000
 
int main ()
{
int intervals ;
double integral = 0.0,final_integral =0.0;
double dx = 1.0 / N ;
 # pragma omp parallel private( integral) shared(final_integral)
 {
   int tid=omp_get_thread_num();
   int num_threads=omp_get_num_threads();
  // int c=N/num_threads;
   int from=(N/num_threads)*tid;
   int to=(N/num_threads)*(tid+1)-1;
      if(tid==num_threads-1) to=N-1;
   for ( int i = from; i <= to; i ++)
    {
      double x = i * dx ;
      double fx = sqrt (1.0 - x * x);
      integral = integral + fx * dx ;
    }
 final_integral=final_integral+integral;
 }
double pi = 4 * final_integral;
printf("%20.80f\n",pi);
return 0;
 }

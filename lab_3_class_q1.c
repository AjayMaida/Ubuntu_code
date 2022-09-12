#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define N 1000000000

int main()
{
  clock_t start, end;
  start = clock();
  double final_integral = 0.0, integral = 0.0;
  double dx = 1.0 / N;
#pragma omp parallel private(integral) shared(final_integral)
  {
    int tid = omp_get_thread_num();
    int num_t = omp_get_num_threads();
    double from = (N / num_t) * tid;
    double to = (N / num_t) * (tid + 1) - 1;
    if (tid == num_t - 1)
      to = N - 1;

    printf("%d\n", num_t);
    for (int i = from; i <= to; i++)
    {
      double x = i * dx;
      double fx = sqrt(1.0 - x * x);
      integral = integral + fx * dx;
    }
    //#pragma omp critical
    final_integral = final_integral + integral;
  }
  double pi = 4 * final_integral;
  printf("%20.80f\n", pi);
  end = clock();
  double t = (double)(end - start) / CLOCKS_PER_SEC;
  printf("time it took to exucute : %f\n", t);
  return 0;
}

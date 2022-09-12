#include<stdio.h>
#include<time.h>
#include<omp.h>
long long int fib(int n){return (n<2 ? 1 : fib(n-1) + fib(n-2));}
#define n 45
int main(){
clock_t start,end;
double tim;
start=clock();
#pragma omp parallel
{
printf(" fib of %d : %Ld\n",n,fib(n));
}
end=clock();
printf("time taken : %f\n",((double)(end-start))/CLOCKS_PER_SEC);
return 0;}

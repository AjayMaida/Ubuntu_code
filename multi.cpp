#include<iostream>
#include<omp.h>
using namespace std;
int main(){
#pragma omp parallel
{
int id=omp_get_thread_num();
printf("hello from the thread %d\n",id);
}
return 0;}

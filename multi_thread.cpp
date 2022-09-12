#include<omp.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

 int main(){
 
 #pragma omp parallel 
 {
 int thread_num=omp_get_num_threads();
 int t_id=omp_get_thread_num();
 printf("hello, from thread %d, total threads : %d\n",t_id,thread_num);
  }
  return 0;
 }

#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

 int main(){
 int thread_num;
 int t_id;
 #pragma omp parallel 
 {
 t_id=omp_get_thread_num();
 thread_num=omp_get_num_threads();
 for(int i=0;i<100000;i++){}
 printf("hello, from thread %d, total threads : %d\n",t_id,thread_num);
 if(t_id==0){
 }
  }
  return 0;
 }

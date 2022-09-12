#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
using namespace std;
void* worker_thread(void* arg){
//sleep(1);
printf("worker_thread  : %d\n",(int*)arg);
return (void*)987;
pthread_exit(NULL);
}

int main(){
pthread_t thread[5];
int id;
int status;
for (int i=0;i<5 ;i++){
status=pthread_create(&thread[i],NULL,worker_thread,(void*)i);
if(status != 0){
cout<<"\nerror in creating New thread : "<<status;
exit(1);
}
}

//wait to comlete thread
//void* result;
//pthread_join(thread,&result);
//printf("main thread done :%d\n",(int*)result);
sleep(2);	
pthread_exit(NULL);
}

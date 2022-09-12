#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

void* fun1(void* arg){
for (int i=0;i<8;i++)
{sleep(1);
cout<<"this is  fun1\n";
}
return NULL;
}
void fun2(){
for(int i=0;i<8;i++)
{//sleep(1);
cout<<"this is fun2\n";}
}


int main(){

pthread_t thread;
int status;
cout<<"started!!!\n";
pthread_create(&thread,NULL,fun1,NULL);
//fun1();
fun2();
return 0;
}

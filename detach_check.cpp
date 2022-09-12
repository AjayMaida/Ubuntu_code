#include<iostream>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<string>
#include<pthread.h>

using namespace std;
void* worker_thread(void* arg){
    cout<<"Thread is running:\n";
    return (int*)1234;
}
int main(){
    pthread_t thread;
    void* result;
    int rc;
    rc=pthread_create(&thread,NULL,worker_thread,NULL);
    if(rc!=0){
        cout<<"Error in creating thread"<< endl;
        exit(1);
    }
    //wait for thread to complete
    pthread_join(thread,&result);
    //pthread_detach(thread);
   // sleep(1);
    cout<<"Main thread Done !"<<result<<endl;
}
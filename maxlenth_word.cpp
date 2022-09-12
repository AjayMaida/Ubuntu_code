#include<iostream>
int main(){
    char arr[100];
    std::cin.getline(arr,100);
    //find the max lenth word and print it
    int curlen=0,maxlen=0,st=0,mxst=0,i=0;
    while(1){
        //if word is ended check its lenth to maxword len
        if(arr[i] == ' ' or arr[i] == '\0'){
            if(curlen>maxlen){
                maxlen=curlen;
               mxst=st; 
            }
            curlen=0; //word eneded
            if(arr[i]!='\0')
            st=i+1;
        }
        else
        curlen++;
        if(arr[i]=='\0')
        break;
        i++;
    }
    std::cout<<"max len word is : ";
    for(int i=mxst;i<=maxlen+mxst;i++){
        std::cout<<arr[i];
    }   
    std::cout<<" having lenth "<<maxlen<<"\n";
    std::cout<<arr[st]<<"\n";
}
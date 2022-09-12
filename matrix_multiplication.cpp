#include<iostream>
int main(){
    int a[][3]={{1,2,3},{4,5,6},{6,7,8}};
    int b[][3]={{1,2,3,},{4,5,6},{6,7,8}};
    int c[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int sum=0;
            for(int k=0;k<3;k++){
                sum+=a[i][k]*b[k][j];
            }c[i][j]=sum;
        }
    }
    for(int i=0;i<3;i++){s
        for(int j=0;j<3;j++){
            std::cout<<c[i][j]<<" ";
        }std::cout<<"\n";
    }
}
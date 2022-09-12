#include<iostream>
using namespace std;
int main(){
    int row,col;
    cin>>row>>col;
    int arr[row][col];
    for(int i=0;i<row;++i){
        for(int j=0;j<col;++j){
            cin>>arr[i][j];
        }
    }
    cout<<"\n\n"; 
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }cout<<"\n";
    }
    cout<<"\n\n"; 
    //spiral order print of 2-D array
    int col_st=0,col_end=col-1,row_st=0,row_end=row-1;
    
    while(row_st<=row_end && col_st<=col_end)
    {
        for(int r=col_st;r<=col_end;r++){
        cout<<arr[row_st][r]<<" ";
    }
    row_st++;
    for(int c=row_st;c<=row_end;c++){
        cout<<arr[c][col_end]<<" ";
    }col_end--;
    if(row_st<=row_end)
    for(int r=col_end;r>=col_st;--r){
        cout<<arr[row_end][r]<<" ";
    }row_end--;
    if(col_st<=col_end)
    for(int c=row_end;c>=row_st;--c){
        cout<<arr[c][col_st]<<" ";
    }col_st++;
    
    }

}
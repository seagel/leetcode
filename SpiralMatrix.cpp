//
// Created by Somesh Mehta on 07/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int rowStart = 0,rowEnd= n-1;
    int colStart = 0,colEnd = m-1;
    while(rowStart <= rowEnd && colStart <= colEnd){
        for(int i=colStart;i<=colEnd;i++){
            cout<<arr[rowStart][i]<<" ";
        }
        rowStart++;
        for(int i=rowStart;i<=rowEnd;i++){
            cout<<arr[i][colEnd]<<" ";
        }
        colEnd--;
        if(rowEnd >= rowStart){
            for(int i=colEnd;i>=colStart;i--){
                cout<<arr[rowEnd][i]<<" ";
            }
            rowEnd --;
        }
        if(colEnd >= colStart){
            for(int i =rowEnd;i>=rowStart;i--){
                cout<<arr[i][colStart]<<" ";
            }
            colStart++;
        }

    }

    return 0;
}
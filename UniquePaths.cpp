//
// Created by Somesh Mehta on 24/12/20.
//
#include "stdio.h"
#include "iostream"
#include "vector"
using namespace  std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > grid(n,vector<int> (m));
    vector<vector<int>> ans(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            grid[i][j] =x;
        }
    }

    ans[0][0]=1;

    for(int i=1;i<m;i++){
        if(grid[0][i] == 0){
            ans[0][i] = ans[0][i-1];
        }
    }

    for(int i=1;i<n;i++){
        if(grid[i][0] == 0){
            ans[i][0] = ans[i-1][0];
        }
    }

    for(int i=1;i<n;i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] == 0) {
                ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
                cout << ans[i][j] << endl;
            }
        }
    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            cout<<ans[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<ans[n-1][m-1];

}
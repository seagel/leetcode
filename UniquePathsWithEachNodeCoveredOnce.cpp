//
// Created by Somesh Mehta on 24/12/20.
//

#include <stdio.h>
#include <iostream>
#include <iosfwd>
#include <vector>

using namespace std;

void countPaths(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &vis,int totalCount,int currentCount,int &ans){
    int n = grid.size() , m = grid[0].size();

    if(i<0||j <0||i>=n||j>=m)
        return;
    if(vis[i][j] || grid[i][j] == -1)
        return;

    vis[i][j] =1 ;
    if(grid[i][j] == 0){
        currentCount++;
    }
    if(grid[i][j] == 2){
        cout<<ans<<" "<<i<<j<<endl;
        if(currentCount == totalCount){
            ans++;
        }
        vis[i][j] =0;
        return ;
    }

    countPaths(i-1,j,grid,vis,totalCount,currentCount,ans);
    countPaths(i,j-1,grid,vis,totalCount,currentCount,ans);
    countPaths(i+1,j,grid,vis,totalCount,currentCount,ans);
    countPaths(i,j+1,grid,vis,totalCount,currentCount,ans);
    vis[i][j] = 0;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > grid(n,vector<int> (m));
    vector<vector<int>> vis(n,vector<int> (m,0));
    int startX ,startY;
    int obstacleCount = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            if(x == 1){
                startX = i;
                startY = j;
            }else if(x == 0){
                obstacleCount++;
            }
            grid[i][j] =x;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    int ans = 0;
    countPaths(startX,startY,grid,vis,obstacleCount,0,ans);
}



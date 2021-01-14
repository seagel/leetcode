//
// Created by Somesh Mehta on 11/01/21.
//

#include<iostream>
#include<vector>
#include <opencl-c.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> prime(n+1,0);
    prime[0]=1;
    prime[1]=1;
    for(int i=2;i<=n/2;i++){
        if(prime[i] ==0){
            for(int j=2;i*j<=n;j++){
                prime[i*j] =1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(prime[i] ==0){
            cout<<i<<endl;
        }
    }
    return 0;
}
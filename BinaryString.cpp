//
// Created by Somesh Mehta on 24/12/20.
//
#include <iostream>;
#include <cmath>

using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int temp = pow(2,n-2);
    if(k > (temp * 2)) {
        cout << "Not Valid";
    }
    bool flip = false;
    while(k > 2){
        k= k%temp;
        temp = temp/2;
        flip = !flip;
    }
    if(k == 1){
        flip ? cout<< 1 : cout<<0;
    }else{
        flip ? cout<< 0 : cout<<1;
    }


    return 0;
}
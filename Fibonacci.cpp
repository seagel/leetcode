//
// Created by Somesh Mehta on 10/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
int fibonacci_recursion(int n){
    if(n == 1 || n ==2){
        return 1;
    }
    return fibonacci_recursion(n-1) + fibonacci_recursion(n-2);

}
int fibonacci_tailRecursion(int n,int a=0,int b=1){
    if(n == 0){
        return a;
    }
    if(n == 1)
    {
        return b;
    }
    return fibonacci_tailRecursion(n - 1,b,a+b);
}

int main(){
    int n;
    cin>>n;
    cout<<fibonacci_tailRecursion(n)<<endl;
    return 0;
}

//
// Created by Somesh Mehta on 10/01/21.
//
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void nextGreaterElement(vector<int> &a,int n){
    stack<int> st;
    st.push(a[0]);
    for(int i=1;i<n;i++){
        while(!st.empty() && st.top() <a[i]){
            cout<<st.top()<<" Next Greater Element "<<a[i]<<endl;
            st.pop();
        }
        st.push(a[i]);
    }
    while(!st.empty()){
        cout<<st.top()<<" Next Greater Element "<<-1<<endl;
        st.pop();
    }
}
void nextSmallerElement(vector<int>&a,int n){
    stack<int> st;
    st.push(a[0]);
    for(int i=1;i<n;i++){
        while(!st.empty() && st.top() > a[i]){
            cout<<st.top()<<" Next Smaller Element "<<a[i]<<endl;
            st.pop();
        }
        st.push(a[i]);
    }
    while(!st.empty()){
        cout<<st.top()<<" Next Smaller Element "<<-1<<endl;
        st.pop();
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    nextSmallerElement(a,n);
    return 0;
}


//
// Created by Somesh Mehta on 27/12/20.
//

#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        st.push(arr[i]);
    }
    vector<vector<int> > ans;
    ans.push_back({st.top()});
    st.pop();
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        int limitThisLevel = ans.size();
        while (limitThisLevel--){
            vector<int> temp = ans[0];
            ans.erase(ans.begin());
            for(int pos=0;pos<=temp.size();pos++){
                vector<int> temp2(temp);
                temp2.insert(temp2.begin()+pos,curr);
                ans.push_back(temp2);
            }
        }
    }
    cout<<ans.size()<<endl;
    for(const auto& an : ans){
        for(int j : an){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//
// Created by Somesh Mehta on 14/01/21.
//
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(),people.end());

    vector<vector<int>> ans(people.size());
    for(int i=0;i<people.size();i++){
        int count = people[i][1];
        int j =0;
        while(count > 0 || (j< people.size() && ans[j].size() > 0)){
            if(ans[j].size()==0 || ans[j][0] >= people[i][0]){
                count--;
            }
            j++;
        }
        ans[j] = people[i];
    }
    return ans;

}

int main(){
    int n;
    cin>>;
    vector<vector<int>> arr(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arr[i] = {x,y};
    }
    reconstructQueue(arr);
    return 0;
}

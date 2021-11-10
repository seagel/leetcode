#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	vector<pair<int,int>> arr;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		arr.push_back({x,y});
	}
	sort(arr.begin(),arr.end());
	priority_queue<int,vector<int>,greater<int>> minHeap;
	for(int i=0;i<n;i++){
		if(minHeap.empty()){
			minHeap.push(arr[i].second);
		}else{
			int earliestEnd = minHeap.top();
			if(earliestEnd < arr[i].first){
				minHeap.pop();
				minHeap.push(arr[i].second);
			}else{
				minHeap.push(arr[i].second);
			}
		}
	}
	cout<<minHeap.size();
 
	return 0;
}

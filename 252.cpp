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
	bool isPossible = true;
	sort(arr.begin(),arr.end());
	for(int i=1;i<n;i++){
		if(arr[i-1].second >= arr[i].first){
			isPossible = false;
			break;
		}
	}
	if(isPossible){
		cout<<"true";
	}else{
		cout<<"false";
	}
 
	return 0;
}

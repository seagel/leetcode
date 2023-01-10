#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<pair<int,int>> bytesRanges) {
	vector<int> ans;
  set<pair<int,int>> bytesSeen;
  int sum = 0;
  for(auto entry : bytesRanges){
    int start = entry.first;
    int end = entry.second;
    for(auto record : bytesSeen){
      if(start >= record.first && end <= record.second){
        start = -1;
        end = -1;
        break;
      }else if(start <=record.second && end > record.second){
        start = record.second + 1;
      }else if(record .first > start && record.first <= end){
        end = record.first -1;
      }
    }
    if(start != -1 && end != -1){
      sum += end - start + 1;
      bytesSeen.insert({start,end});
    }
    for(auto record : bytesSeen){
      cout<<record.first<<" "<<record.second<<endl;
    }
  }
  return ans;
}

int main() {
	vector<pair<int,int>> ranges;
  ranges.push_back({1,8});
  ranges.push_back({2,8});
  ranges.push_back({2,6});
  ranges.push_back({3,18});
  solve(ranges);
	return 0;
}


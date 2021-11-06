class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> results;
        if(intervals.size() == 0){
            return {newInterval};
        }
        bool isInserted = false;
        for(vector<int> curr : intervals){
            if(curr[0]< newInterval[0]){
                results.push_back(curr);
            }else if(!isInserted && curr[0] == newInterval[0]){
                isInserted = true;
                results.push_back({curr[0],max(curr[1],newInterval[1])});
            }else {
                if(!isInserted){
                   isInserted = true;
                    results.push_back(newInterval); 
                }
                results.push_back(curr);
            }
        }
        if(!isInserted){
            results.push_back(newInterval); 
        }
        vector<vector<int>> new_results;
        int idx = 0;
        new_results.push_back(results[0]);
        for(int i=1;i<results.size();i++){
            // cout<<results[i][0]<<" "<<results[i][1]<<endl;
            if(results[i][0] > new_results[idx][1]){
                new_results.push_back(results[i]);
                idx++;
            }else if(results[i][0]>=new_results[idx][0] && results[i][0]<=new_results[idx][1]){
                new_results[idx] = {min(new_results[idx][0],results[i][0]),max(new_results[idx][1],results[i][1])};
            }
            //cout<<new_results[idx][0]<<" "<<new_results[idx][1]<<endl;
            
        }
        return new_results;
    }
};

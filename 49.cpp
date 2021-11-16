class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> count(26,0);
        map<string,vector<int>> groupMap;
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].length();j++){
                count[strs[i][j]-'a']++;
            }
            string temp = "";
            for(int j=0;j<26;j++){
                temp.push_back(count[j]);
                count[j] = 0;
            }
            if(groupMap.find(temp) == groupMap.end()){
                groupMap[temp] = vector<int> ();
            }
            groupMap[temp].push_back(i);
        }
        vector<vector<string>> results;
        for(auto it = groupMap.begin();it!=groupMap.end();it++){
            vector<string> temp;
            for(int i=0;i<it->second.size();i++){
                temp.push_back(strs[it->second[i]]);
            }
            results.push_back(temp);
        }
        return results;
    }
};

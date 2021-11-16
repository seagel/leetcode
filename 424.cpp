class Solution {
public:
    int characterReplacement(string s, int k) {
       map<char,int> count;
        int left =0;
        int maxF = 0;
        int maxL = 0;
        for(int r = 0;r<s.length();r++){
            count[s[r]]++;
            maxF = max(maxF,count[s[r]]); 
            int len = r - left +1;
            if(len - maxF > k){
                count[s[left]] -- ;
                left++;
            }
            maxL = max(maxL,r - left + 1);
        }
        return maxL;
    }
};

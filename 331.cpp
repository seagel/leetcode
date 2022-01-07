class Solution {
public:
    bool isValidSerialization(string data) {
        int cnt =0,i=0;
        bool start = false;
        for(int i=0;i<data.length();i++){
            if(data[i] == ','){
                start =false;
                continue;
            }
            if(start)
                continue;
            if(i!=0)
                cnt--;
            if(cnt < 0)
                return false;
            if(data[i]!='#'){
                start = true;
                cnt+=2;
            }
                
            
        }
        return cnt==0;
    }
    
};

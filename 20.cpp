class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                // cout<<"first loop"<<endl;
                st.push(s[i]);
            }else if(!st.empty()  && ((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '['))){
                // cout<<"second loop"<<endl;
                st.pop();
            }else{
                // cout<<"third loop"<<endl;
                return false;
            }
        }
        return st.empty() ? true : false;
    }
};

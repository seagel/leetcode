//
// Created by Somesh Mehta on 13/01/21.
//

#include<iostream>
#include<vector>
using namespace std;
bool isMatch(string s, string p) {
    if(p.length() == 0){
        return false;
    }
    char prev ;
    int index = 0,patternIndex = 0;
    while(patternIndex < p.length() && index < s.length()){
        if(p[patternIndex] == '.'){
            prev = '.';
            patternIndex++;
            index++;
        }else if(p[patternIndex] == '*'){
            if(prev == '.'){
                if(patternIndex + 1 < p.length()){
                    patternIndex = patternIndex + 1;
                    while(index < s.length() && p[patternIndex] != s[index]){
                        index++;
                    }
                }else{
                    return true;
                }
            }else{
                while(index < s.length() && prev == s[index]){
                    index++;
                }
            }
            patternIndex++;
        }else if(index < s.length() && p[patternIndex] == s[index]){
            prev = p[patternIndex];
            patternIndex++;
            index++;
        }else if(index < s.length() && p[patternIndex] != s[index] && patternIndex + 1 < p.length() &&p[patternIndex + 1] == '*'){
            patternIndex = patternIndex+2;
        }
    }
    if((index < s.length() || patternIndex < p.length())){
        return false;
    }
    return true;
}
int main(){
    string s,p;
    cin>>s>>p;
    cout<<isMatch(s,p);
    return 0;
}
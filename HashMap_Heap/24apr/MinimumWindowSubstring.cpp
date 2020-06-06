// https://leetcode.com/problems/minimum-window-substring/
// Minimum Window Substring
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        int start=0;
        int end=0;
        int matchCount=0;
        int Anslen=INT_MAX;
        int AnsStart=-1;
        int AnsEnd=-1;
        unordered_map<char,int> Tumap;
        unordered_map<char,int> Sumap;
        for(char c: t){
            Tumap[c]++;
        }
        while(end<s.size()){
            Sumap[s[end]]++;
            if(Tumap.find(s[end])!=Tumap.end()){
                if(Sumap[s[end]]==Tumap[s[end]]){
                    matchCount++;
                }
            }
            end++;
            while(matchCount==Tumap.size()){
                
                int currLen=end-start;
                if(currLen<Anslen){
                    Anslen=currLen;
                    AnsStart=start;
                    AnsEnd=end;
                }
                Sumap[s[start]]--;
                if(Tumap.find(s[start])!=Tumap.end()){
                    if(Sumap[s[start]]<Tumap[s[start]]){
                        matchCount--;
                    }
                }
                start++;
            }
        }
            if(AnsStart==-1 || Anslen==INT_MAX){
                return ans;
            
            }
        ans= s.substr(AnsStart,Anslen);
        return ans;
    }
};
int main(){
    Solution s;
    cout<<s.minWindow("a", "aa")<<endl;

    return 0;
}
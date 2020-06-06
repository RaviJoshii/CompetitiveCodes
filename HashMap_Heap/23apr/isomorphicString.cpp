// https://leetcode.com/problems/isomorphic-strings/
// Isomorphic Strings

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sl=s.size();
        int tl=t.size();
        if(sl!=tl){
            return false;
        }
        unordered_map <char,char> umaps;
        unordered_map <char,char> umapt;
        for(int i=0;i<sl;i++){
            char sCh=s[i];
            char tCh=t[i];
            if(umaps.find(sCh)!=umaps.end()){
                if(umaps[sCh]!=tCh){
                    return false;
                }
            }
            else{
                //newly add
                if(umapt.find(tCh)!=umapt.end()){
                    return false;
                }
                umaps[sCh]=tCh;
                umapt[tCh]=sCh;
            }
        }
        return true;
    }
    
};
int main(){
    Solution s;
    cout<<s.isIsomorphic("paper","title");
    cout<<s.isIsomorphic("abc","dee");
    return 0;
}
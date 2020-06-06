// https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Find All Anagrams in a String
// https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92059/O(n)-Sliding-Window-JAVA-Solution-Extremely-Detailed-Explanation

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.size()<p.size()||p.size()==0||s.size()==0){
            return ans;
        }
        int matchCount=0;
        int start=0;
        int end=0;
        unordered_map<char,int> Pumap;
        unordered_map<char,int> Sumap;
        for(int i=0;i<p.size();i++){
            Pumap[p[i]]++;

        }
        // cout<<Pumap.size()<<endl;
        while(end<s.size()){
            Sumap[s[end]]++;
            if(Pumap.find(s[end])!=Pumap.end()){
                if(Pumap[s[end]]==Sumap[s[end]]){
                    matchCount++;
                    // cout<<matchCount<<endl;
                }
            }
            end++;
            // cout<<matchCount<<" - "<<Pumap.size()<<endl;
            while(matchCount==Pumap.size()){
                // cout<<end-start<<endl;
                if(end-start==p.size()){
                    ans.push_back(start);
                }
                
                Sumap[s[start]]--;
                if(Pumap.find(s[start])!=Pumap.end()){
                    if(Sumap[s[start]]<Pumap[s[start]]){
                        matchCount--;
                    }
                }
                start++;
            }
            
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> ans=s.findAnagrams("abab", "ab");
    // cout<<ans.size()<<endl;
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}
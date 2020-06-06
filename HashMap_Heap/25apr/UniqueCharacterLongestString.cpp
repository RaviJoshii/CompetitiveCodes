// https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Longest Substring Without Repeating Characters

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> umap;
        int start=0;
        int end=0;
        int len=0;
        while(end<s.size()){
            umap[s[end]]++;
            if(umap[s[end]]>1){
                while(umap[s[end]]>1){
                    umap[s[start]]--;
                    start++;
                }
            }
            end++;
            len=max(len,end-start);
            // cout<<len<<endl;
            
        }
        return len;
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution s;
    cout<<s.lengthOfLongestSubstring(str)<<endl;
    }
    
}
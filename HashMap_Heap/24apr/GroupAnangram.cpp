// https://leetcode.com/problems/group-anagrams/submissions/
//  Group Anagrams

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string format(vector<int> &vec){
        string s="";
        for(int num:vec){
            s+=num;
            s+="#";
        }
        return s;
    }
    void clear(vector<int> &vec){
        for(int i=0;i<vec.size();i++){
            vec[i]=0;
        }
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> vec(26);
        vector<vector<string>> ans;
        unordered_map<string,int> umap;
        for(string str:strs){
            clear(vec);
            for(char c:str){
                vec[c-'a']++;   
            }
            string key=format(vec);
            if(umap.find(key)!=umap.end()){
                int idx=umap[key];
                ans[idx].push_back(str);
            }
            else{
                umap[key]=ans.size();
                ans.push_back({str});
            }
        }
        return ans;
    }
};
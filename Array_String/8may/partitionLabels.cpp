// https://leetcode.com/problems/partition-labels/
// Partition Labels
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char , int> umap;
        for(int i=0;i<S.size();i++){
            umap[S[i]]=i;
        }
        int end=-1;
        vector<int> ans;
        int j=0;
        for(int i=0;i<S.size();i++){
            end=max(end,umap[S[i]]);
            if(i==end){
                ans.push_back(i-j+1);
                j=i+1;
                end=-1;
            }
        }
        return ans;
        
    }
};
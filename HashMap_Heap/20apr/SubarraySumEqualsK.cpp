// https://leetcode.com/problems/subarray-sum-equals-k/
// Subarray Sum Equals K
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        unordered_map<int,int> umap;
        int ans=0;
        umap[0]=1;
        for(int i=0;i<nums.size();i++){
            int check=prefix[i]-k;
            if(umap.find(check)!=umap.end()){
                ans+=umap[check];
                // umap[check]++;
            }
            if(umap.find(prefix[i])!=umap.end()){
                umap[prefix[i]]++;
            }
            else{
                umap[prefix[i]]=1;
            }
        }
        return ans;
    }
};
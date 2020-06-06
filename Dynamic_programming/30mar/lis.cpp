// https://leetcode.com/problems/longest-increasing-subsequence/
// 300. Longest Increasing Subsequence
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int BS(int l,int r,int data,vector<int> &arr){
    while (r - l > 1) { 
    int m = l + (r - l) / 2; 
    if (arr[m] >= data) 
        r = m; 
    else
        l = m; 
    } 
    return r; 
}
int lengthOfLIS(vector<int>& nums) {
    if(nums.size()==0){
        return 0;
    }
    vector<int> vec;
    vec.push_back(nums[0]);
    for(int i=1;i<nums.size();i++){
        if(nums[i]<vec[0]){
            vec[0]=nums[i];
        }
        else if(nums[i]>vec[vec.size()-1]){
            vec.push_back(nums[i]);
        }
        else{
            int idx=BS(-1,vec.size()-1,nums[i],vec);
            vec[idx]=nums[i];
            
        }
    }
    return vec.size();
    }
};
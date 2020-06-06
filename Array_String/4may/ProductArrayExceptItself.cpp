// https://leetcode.com/problems/product-of-array-except-self/
// Product of Array Except Self
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        long long suffix=1;
        vector<int> prefix(nums.size());
        if(nums.size()==0){
            return prefix;
        }
        prefix[0]=nums[0];
        
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]*nums[i];
        }
        
        for(int i=nums.size()-1;i>0;i--){
            prefix[i]=prefix[i-1]*suffix;
            suffix=suffix*nums[i];
        }
        prefix[0]=suffix;
        
        return prefix;
    }
};
// https://leetcode.com/problems/maximum-subarray/
//  Maximum Subarray
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int cmax=nums[0];
        int omax=nums[0];
        for(int i=1;i<nums.size();i++){
            if(cmax<0){
                cmax=nums[i];
            }
            else{
                cmax+=nums[i];
            }
            omax=max(omax,cmax);
        }
        return omax;
    }
};
// https://leetcode.com/problems/largest-number-at-least-twice-of-others/
// Largest Number At Least Twice of Others

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int fmax=INT_MIN;int smax=INT_MIN;
        int fmaxI;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>fmax){
                smax=fmax;
                fmax=nums[i];
                fmaxI=i;
                
            }else if(nums[i]>smax){
                smax=nums[i];
            }
        }
        if(fmax/2>=smax){  //equivalent to fmax>= 2*smax // due to overflow i used this
            
            return fmaxI;
        }
        return -1;
        
    }
};
// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// Find the Smallest Divisor Given a Threshold
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Divisors(vector<int>& nums,int k){
        int th=0;
        for(auto num : nums){
            th+=ceil((num*(1.0))/k);
        }
        return th;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1;
        int hi=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>hi){
                hi = nums[i];
            }
        }
        int ans=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int th=Divisors(nums,mid);
            if(th>threshold){
                lo=mid+1;
            }else if(th<=threshold){
                ans=mid;
                hi=mid-1;

            }
        }
        return ans;
    }
};

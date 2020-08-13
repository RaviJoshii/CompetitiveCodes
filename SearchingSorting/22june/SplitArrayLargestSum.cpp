// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Capacity To Ship Packages Within D Days
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubbarays(vector<int>& nums,int MaxSum){
        long long temp=0;
        long long requiredDays=1;
        for(long long i=0;i<nums.size();i++){
            if(temp+nums[i]>MaxSum){
                temp=0;
                requiredDays++;
            } 
            temp+=nums[i];
        }
        return requiredDays;
    }
    int splitArray(vector<int>& nums, int m) {
        if(nums.size()==0){
            return 0;
        }
        long long  mini=INT_MIN;
        long long maxi=0;
        for(long long i=0;i<nums.size();i++){
            if(nums[i]>mini){
                mini=nums[i];
            }
            maxi+=nums[i];
        }
        long long ans=INT_MAX;
        while(mini<=maxi){
            long long mid=(mini+maxi)/2;
            long long countSubarray=countSubbarays(nums,mid);
            if(countSubarray>m){
                //means we have to increase our "mid"  
                mini=mid+1;
            }else if(countSubarray<=m){
                maxi=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> vec={1,2147483647};

    int m=1;
    cout<<s.splitArray(vec,m);
}
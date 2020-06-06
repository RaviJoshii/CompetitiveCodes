// https://leetcode.com/problems/jump-game-ii/
// 45. Jump Game II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1){return 0;}
        if(nums[0]==0){
                return 0;
        }
        
        // APPROACH 1:- O(n2)
        // vector<int> dp(nums.size());
        // dp[nums.size()-1]=0;
        // for(int i=nums.size()-2;i>=0;i--){
        //     int mins=nums.size();
        //     if(nums[i]==0){
        //         dp[i]=mins;
        //         continue;
        //     }
        //     for(int j=1;j<=nums[i];j++){
        //         if(j+i<nums.size()){
        //             mins=min(mins,dp[j+i]);
        //         }
        //     }
        //     dp[i]=mins+1;
        // }
        // return dp[0];
        
        // APPROACH 2: -O(nlogn)       
        if(nums.size()<=1){
        return 0;
        }
        int i=0;
        int jc=0;
        while(i<nums.size()){
            if(i+nums[i] > nums.size()-2){
                jc++;
                break;
            }
            int nextI=0;int maxJump=0;
            for(int k=i+1;k<=i+nums[i];k++){
                if(maxJump<nums[k]+k){
                    maxJump=nums[k]+k;
                    nextI=k;
                }
            }
            i=nextI;
            jc++;
        }
        return jc;
        
    }
    
};
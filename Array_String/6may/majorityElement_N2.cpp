// https://leetcode.com/problems/majority-element-ii/
// Majority Element II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int val1,val2,count1,count2;
        count1=0;
        count2=0;
        
        vector<int> ans;
        if(nums.size()==0){
            return ans;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val1){
                count1++;
            }else if(nums[i]==val2){
                count2++;
            }else if(count1==0){
                val1=nums[i];
                count1=1;
            }else if(count2==0){
                val2=nums[i];
                count2=1;
            }else{
                count2--;
                count1--;
            }
        }
        bool flag1=false;
        bool flag2=false;
        int cn1=0; int cn2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val1){
                cn1++;
            }else if(nums[i]==val2){
                cn2++;
            }
        }
        if(cn1>(nums.size()/3)){
            ans.push_back(val1);
        }
        if(cn2>(nums.size()/3)){
            ans.push_back(val2);
        }
        return ans;
    }
};
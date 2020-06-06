// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
//  Smallest Range Covering Elements from K Lists
#include<bits/stdc++.h>
using namespace std;
class item{
    public:
    int val;
    int i,j;
    item(int val,int i,int j){
        this->i=i;
        this->val=val;
        this->j=j;

    }
    bool operator>(const item &i1)const{
        return this->val>i1.val;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<item,vector<item>,greater<item>> pq;
        int k=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<k;i++){
            pq.push(item(nums[i][0],i,0));
            maxi=max(maxi,nums[i][0]);
        }
        int len=INT_MAX;
        int sp;int ep;
        while(pq.size()==k){
            item rem=pq.top();pq.pop();
            if((maxi-rem.val+1)<len){
                sp=rem.val;
                ep=maxi;
                len=ep-sp+1;
            }

            if(rem.j+1<nums[rem.i].size()){
                pq.push(item(nums[rem.i][rem.j+1],rem.i,rem.j+1));
                maxi=max(maxi,nums[rem.i][rem.j+1]);
            }
        }
        return {sp,ep};
        
    }       
};
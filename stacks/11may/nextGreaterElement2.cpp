// https://leetcode.com/problems/next-greater-element-ii/
//  Next Greater Element II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        if(nums.size()==0){
            return ans;
        }
        stack<int> st;
        st.push(0);
        int i;
        for(int j=1;j<2*nums.size();j++){
             i=j%(nums.size());
            int num = nums[i];
            while(st.size()>0 && nums[st.top()]<num){
                ans[st.top()]=num;
                st.pop();
            }
            if(j<nums.size()){
                st.push(i);
            }
           
        }
        while(st.size()>0){
            ans[st.top()]=-1;
            st.pop();
        }
        return ans;
        
    }
};
// https://leetcode.com/problems/daily-temperatures/submissions/
// Daily Temperatures
#include <iostream>
#include<vector>
#include<stack>
using namespace std;
      
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        if(nums.size()==0){
            return ans;
        }
        stack<int> st;
        st.push(0);
        for(int i=1;i<nums.size();i++){
            int num = nums[i];
            while(st.size()>0 && nums[st.top()]<num){
                ans[st.top()]=(i-st.top());
                st.pop();
            }
            st.push(i);
        }
        while(st.size()>0){
            ans[st.top()]=0;
            st.pop();
        }
        return ans;
        
    }
};
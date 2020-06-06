// https://leetcode.com/problems/max-consecutive-ones-ii/
// https://www.lintcode.com/problem/max-consecutive-ones-ii/description
// Max Consecutive Ones II

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int prevIndex=-1;
        int ans=INT_MIN;
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                j=prevIndex+1;
                prevIndex=i;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};

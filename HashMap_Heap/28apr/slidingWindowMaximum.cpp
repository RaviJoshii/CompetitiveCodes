// https://leetcode.com/problems/sliding-window-maximum/
// Sliding Window Maximum
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        if(n<1){
            return ans;
        }
        vector<int> left(n);
        vector<int> right(n);
        for(int i=0;i<n;i++){
            if(i%k==0){
                left[i]=nums[i];
                continue;
            }
            left[i]=max(nums[i],left[i-1]);
        }
        for(int i=n-1;i>=0;i--){
            if((i==n-1)||(i+1)%k==0){
                right[i]=nums[i];
                continue;
            }
            right[i]=max(nums[i],right[i+1]);
        }
        for(int p:left){
            cout<<p<<" ";
        }
        cout<<endl;
        for(int p:right){
            cout<<p<<" ";
        }
        cout<<endl;
        for(int i=0;i<=n-k;i++){
            int j=i+k-1;
            ans.push_back(max(right[i],left[j]));
        }
        return ans;
    }
};
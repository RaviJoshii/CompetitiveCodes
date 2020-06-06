// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Remove Duplicates from Sorted Array
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int count = 1;
        int prev=0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]!=nums[prev]){
                prev++;
                nums[prev]=nums[i];
                count++;
            }
        }
        return count;
        
        
    }
};
// https://leetcode.com/problems/wiggle-sort/
// https://www.lintcode.com/problem/wiggle-sort/description
// https://www.geeksforgeeks.org/convert-array-into-zig-zag-fashion/
// Wiggle Sort

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        if(nums.size()==0){
            return;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(i%2==0){
                //even
                if(nums[i]>nums[i+1]){
                    swap(nums[i],nums[i+1]);
                }
            }else{
                //odd
                if(nums[i]<nums[i+1]){
                    swap(nums[i],nums[i+1]);
                }

            }
        }
    }
};
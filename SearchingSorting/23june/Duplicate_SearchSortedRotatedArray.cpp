// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/28218/My-8ms-C%2B%2B-solution-(o(logn)-on-average-o(n)-worst-case)
// Search in Rotated Sorted Array II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[left]==nums[mid] && nums[mid]==nums[right]){
                left++;
                right--;
            }
            else if(nums[left]<=nums[mid]){
                if(nums[left]<=target && nums[mid]>=target){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
            else{
                if(nums[right]>=target && nums[mid]<=target){
                     left=mid+1;
                }else{
                    right=mid-1;
                }
                
            }

        }
        return false;

    }
};


int main(){

   return 0;
}
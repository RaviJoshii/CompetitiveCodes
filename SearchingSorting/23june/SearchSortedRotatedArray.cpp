// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Search in Rotated Sorted Array
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int BS(vector<int> &vec,int k,int lo,int hi) 
    { 
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(vec[mid]==k){
                return mid;
            }else if(vec[mid]<k){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return -1;
        
    } 
    int search(vector<int>& nums, int target) {
        int lo =0;
        int hi=nums.size()-1;
        //finding pivot;
        while(lo<hi){
            int mid=(hi+lo)/2;
            if(nums[mid]>nums[hi]){
                lo=mid+1;
            }else{
                hi=mid;
            }
        }
        // cout<<"s.p: "<<lo<<endl;
        int sp=lo; //starting point index;
        int left,right;
        if(((sp-1)>=0) && target>=nums[0]&& target<=nums[sp-1]){
            left=0;
            right=sp-1;
        }else{
            left=lo;
            right=nums.size()-1;
        }
        return BS(nums,target,left,right);        
    }
};

int main(){
    vector<int> nums={4,5,6,7,0,1,2};
    int target=0;
    Solution s;
    cout<<s.search(nums,target);
    return 0;
}
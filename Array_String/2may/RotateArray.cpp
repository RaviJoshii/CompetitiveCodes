// https://leetcode.com/problems/rotate-array/
// Rotate Array
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverse(vector<int> &arr,int i,int j){
        while(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        vector<int> res(nums.size());
        int j=0;
        reverse(nums,0,nums.size()-k-1);
        reverse(nums,nums.size()-k,nums.size()-1);
        reverse(nums,0,nums.size()-1);
    }
};
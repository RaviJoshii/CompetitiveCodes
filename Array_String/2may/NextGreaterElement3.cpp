// https://leetcode.com/problems/next-greater-element-iii/submissions/
// Next Greater Element III
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     void reverse(string &arr,int i,int j){
        while(i<j){
            auto temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    int nextGreaterElement(int n) {
        string nums=to_string(n);
        int idx=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                idx=i-1;
                break;
            }
        }
        if(idx==-1){
            return -1;
        }
        int jsi;
        int jse=INT_MAX;
        for(int i=idx+1;i<nums.size();i++){
            if(nums[i]>nums[idx]&& nums[i]<=jse){
                jse=nums[i];
                    jsi=i;
            }
        }
        //swapping;
        auto temp=nums[idx];
        nums[idx]=nums[jsi];
        nums[jsi]=temp;
        
        reverse(nums,idx+1,nums.size()-1);
        long ans = stol(nums);
        return ans > INT_MAX? -1 : ans;
    }
};
int main(){
    Solution s;
    cout<<s.nextGreaterElement(230241);
    return 0;
}
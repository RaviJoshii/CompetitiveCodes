// https://leetcode.com/problems/longest-consecutive-sequence/
// Longest Consecutive Sequence
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<1){
            return 0;
        }
        unordered_map<int,int> umap;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(umap.find(nums[i])!=umap.end()){
                continue;
                // to handle duplicate data
            }
            int minus1=nums[i]-1;
            int plus1=nums[i]+1;
            int sp,ep;
            int len=0;
            if(umap.find(minus1)==umap.end() && umap.find(plus1)==umap.end()){
                //-1 and +1 both not are in map
                sp=nums[i];
                ep=nums[i];
            }
            else if(umap.find(minus1)!=umap.end() && umap.find(plus1)==umap.end()){
                 //-1 in map //+1 not in map
                 sp=nums[i]-umap[minus1];
                 ep=nums[i];
            }
            else if(umap.find(minus1)==umap.end() && umap.find(plus1)!=umap.end()){
                //-1  not in map //+1  in map
                 ep=nums[i]+umap[plus1];
                 sp=nums[i];
            }
            else{
                //-1 and +1 are both  in map
                  umap[nums[i]]=1;//so that nums[i] will not considered again
                 ep=nums[i]+umap[plus1];
                 sp=nums[i]-umap[minus1];
            }
            len=ep-sp+1;
            umap[ep]=len;
            umap[sp]=len;
            if(umap[ep]>ans){
                ans=umap[ep];
            }
        }
        
        // for(auto it:umap){
        //     ans=max(ans,it.second);
        // }
        return ans;
    }
};
int main(){
    vector<int> vec={4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};
    // vector<int> vec={1,3,7,5};
    Solution s;
    cout<<s.longestConsecutive(vec);
}
// https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
// Max Chunks To Make Sorted II
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> maxLeft(arr.size());
        vector<int> minRight(arr.size());
        
        maxLeft[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            maxLeft[i]=max(maxLeft[i-1],arr[i]);
        }
        minRight[arr.size()-1]=arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--){
            minRight[i]=min(minRight[i+1],arr[i]);
        }
        int chunks=0;
        for(int i=0;i<arr.size()-1;i++){
            if(maxLeft[i]<=minRight[i+1]){
                chunks++;
            }
        }
        // int idx=arr.size()-1;
        // if(maxLeft[idx]<=minRight[idx]){
        //     chunks++;
        // }
        chunks++;
        return chunks;
        
    }
};
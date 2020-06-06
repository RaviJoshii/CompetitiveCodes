// https://leetcode.com/problems/max-chunks-to-make-sorted/
// Max Chunks To Make Sorted
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size()==0){
            return 0;
        }
        int maxi=0;
        int chunks=0;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
            if(i==maxi){
                chunks++;
            }
        }
        return chunks;
    }
};
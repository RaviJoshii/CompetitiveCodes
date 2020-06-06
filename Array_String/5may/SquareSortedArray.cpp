// https://leetcode.com/problems/squares-of-a-sorted-array/
// Squares of a Sorted Array
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans(A.size());
        if(A.size()==0){
            return ans;
        }
        
        int i=0;
        
        int j=A.size()-1;
        int k=A.size();
        while(i<=j){
            int first=abs(A[i]);
            int second=abs(A[j]);
            if(first<second){
                ans[--k]=second*second;
                j--;
            }
            else{
                ans[--k]=first*first;
                i++;
            }
        }
        return ans;
    }
};
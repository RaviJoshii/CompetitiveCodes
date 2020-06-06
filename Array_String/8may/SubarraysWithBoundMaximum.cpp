// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
//  Number of Subarrays with Bounded Maximum
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int i=0;
        int smaller=0;
        int ans=0;
        for(int j=0;j<A.size();j++){
            if(A[j]>=L && A[j]<=R){
                smaller=j-i+1;
                ans+=smaller;
            }else if(A[j]<L){
                ans+=smaller;
            }else if(A[j]>R){
                smaller =0;
                i=j+1;
            }
        }
        return ans;
    }
};

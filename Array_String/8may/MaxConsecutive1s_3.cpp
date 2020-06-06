// https://leetcode.com/problems/max-consecutive-ones-iii/
// Max Consecutive Ones III
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        list<int> ls;
        int ans=0;
        int j=0;
        for(int i=0;i<A.size();i++){
            if(A[i]==0){
                ls.push_back(i);
                if(ls.size()>K){
                    int rem=ls.front();
                    ls.pop_front();
                    j=rem+1;
                }
            }
            
            ans=max(ans,i-j+1);
            
        }
        return ans;
        
        
    }
};
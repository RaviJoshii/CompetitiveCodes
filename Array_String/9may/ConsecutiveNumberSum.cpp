// https://leetcode.com/problems/consecutive-numbers-sum/
// Consecutive Numbers Sum
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int num=sqrt(2*N);
        int ans=0;
        for(int k=1;k<=num;k++){
            if((N-(k*(k-1))/2)%k==0){
                ans++;
            }
        }
        return ans;
        
    }
};
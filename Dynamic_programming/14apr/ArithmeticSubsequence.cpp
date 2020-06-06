// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
// Arithmetic Slices II - Subsequence
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3){
            return 0;
        }
        vector<unordered_map<int,int>> dp(A.size()); 
        int ans=0;
        for(int i=0;i<A.size();i++){
            for(int j=i-1;j>=0;j--){
                
                if((((long)A[i]-(long)A[j]) > INT_MAX) || (((long)A[i]-(long)A[j])< INT_MIN) ){continue;}
                    int diff=A[i]-A[j];
                    dp[i][diff] += 1;
                    if(dp[j].find(diff) != dp[j].end()){
                        dp[i][diff] += dp[j][diff];
                        ans += dp[j][diff];
                        // here "ans" will updated as the length of subsequence id >2
                    } 
                }
            }
            // for(int i=0;i<dp.size();i++){
            //     unordered_map<int,int> temp=dp[i];
            //     cout<<A[i]<<" :  ";
            //     for(auto it:temp){
            //         cout<<"("<<it.first<<":"<<it.second<<") , ";
            //     }
            //     cout<<endl;
            // }
        return ans;
        }
};
int main(){
    Solution s;
    vector<int> arr={2,4,6,8,10};
    cout<<s.numberOfArithmeticSlices(arr);
}

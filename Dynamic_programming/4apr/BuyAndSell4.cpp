// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Best Time to Buy and Sell Stock IV
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n<1){
            return 0;
        }
        vector<vector<int>> dp(k+1,vector<int>(n));
        for(int i=0;i<=k;i++){
            int factor=0-prices[0];
            for(int j=0;j<n;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                    continue;
                }
                dp[i][j]=max(dp[i][j-1],prices[j]+factor);
                factor=max(factor,dp[i-1][j]-prices[j]);
            }
        }
        // for(int i=0;i<dp.size();i++){
        //     for(int j=0;j<dp[0].size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};
int main(){
    vector<int> vec={3,5,8,4,3,7,12};
    Solution s;
    cout<<s.maxProfit(3,vec);
}
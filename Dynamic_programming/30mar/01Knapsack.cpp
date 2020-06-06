// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
// 0-1 Knapsack Problem
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    for(int y=0;y<t;y++){
        int n,capacity;
        cin>>n>>capacity;
        vector<int> prices(n);
        vector<int> weights(n);
        for(int j=0;j<n;j++){
            cin>>prices[j];
        }
        for(int j=0;j<n;j++){
            cin>>weights[j];
        }
        vector<vector<int>> dp(prices.size(),vector<int>(capacity+1,0));
        for(int i=0;i<prices.size();i++){
            for(int j=0;j<=capacity;j++){
                if(j==0) {dp[i][j]=0;continue;}
                if(i==0){
                    if(weights[i]<=j){
                        dp[i][j]=prices[i];
                    }
                    continue;
                }
                int inc=0;
                int exc=dp[i-1][j];
                if(weights[i]<=j){
                    inc=prices[i]+dp[i-1][j-weights[i]];
                }
                dp[i][j]=max(inc,exc);
            }
            
        }
         cout<<dp[weights.size()-1][capacity]<<endl;
    }
    return 0;
}
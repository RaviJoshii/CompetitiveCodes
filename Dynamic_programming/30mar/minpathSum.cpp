// https://leetcode.com/problems/minimum-path-sum/
// Minimum Path Sum

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols));
        dp[rows-1][cols-1]=grid[rows-1][cols-1];
        for(int i=cols-2;i>=0;i--){
            dp[rows-1][i]=grid[rows-1][i]+dp[rows-1][i+1];
        }
        for(int i=rows-2;i>=0;i--){
            dp[i][cols-1]=grid[i][cols-1]+dp[i+1][cols-1];
        }
        for(int i=rows-2;i>=0;i--){
            for(int j=cols-2;j>=0;j--){
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])+grid[i][j];
            }
        }
        
        return dp[0][0];
        
    }
};
// https://www.lintcode.com/problem/paint-house-ii/description
// https://leetcode.com/problems/paint-house-ii/
// paint house ii
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        // write your code here
        int n=costs.size();
        if(n<1){
            return 0;
        }
        int k=costs[0].size();
        vector<vector<int>> dp(n,vector<int>(k));
        int Fmin=INT_MAX;
        int Smin=INT_MAX;
        for(int i=0;i<k;i++){
            dp[0][i]=costs[0][i];
            if(costs[0][i]<Fmin){
                Smin=Fmin;
                Fmin=dp[0][i];
               
            }
            else if(costs[0][i]<Smin){
                 Smin=dp[0][i];
            }
        }
        for(int i=1;i<n;i++){
            int currFmin=INT_MAX;
            int currSmin=INT_MAX;
            for(int j=0;j<k;j++){
                int factor;
                if(dp[i-1][j]==Fmin){
                    factor=Smin;
                }
                else{
                    factor=Fmin;
                }
                dp[i][j]=costs[i][j]+factor;
                if(dp[i][j]<currFmin){
                    currSmin=currFmin;
                    currFmin=dp[i][j];
                }
                else if(dp[i][j]<currSmin){
                    currSmin=dp[i][j];
                }
            }
            Fmin=currFmin;
            Smin=currSmin;
        }
        return Fmin;
    }
};
int main(){
    Solution s;
    vector<vector<int> > vec={{1,2,3},{1,4,6}};
    cout<<s.minCostII(vec);
    return 0;
}
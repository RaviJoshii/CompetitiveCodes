// https://www.geeksforgeeks.org/edit-distance-dp-5/
// Edit Distance
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>m>>n;
        string s1,s2;
        cin>>s1>>s2;
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0){
                    dp[i][j]=j;
                }
                else if(j==0){
                     dp[i][j]=i;
                }
                else if(s1[j-1]==s2[i-1]){
                        dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j]);
                }
            }
        }
        // for(int i=0;i<dp.size();i++){
        //     for(int j=0;j<dp[0].size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
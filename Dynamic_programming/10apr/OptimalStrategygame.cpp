// https://www.geeksforgeeks.org/optimal-strategy-for-a-game-dp-31/
// Optimal Strategy for a Game
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<vector<int>> dp(n,vector<int>(n));
        for(int g=0;g<dp.size();g++){
            for(int i=0;i<dp.size()-g;i++){
                int j=i+g;
                if(i==j){
                    dp[i][j]=arr[i];
                }
                else if(g==1){
                    dp[i][j]=max(arr[i],arr[j]);
                }
                else if(g%2==1){
                    int Omin1=min(dp[i][j-2],dp[i+1][j-1]);//opponent minimum selection
                    int Omin2=min(dp[i+2][j],dp[i+1][j-1]);//opponent minimum selection
                    dp[i][j]=max(arr[j]+Omin1,arr[i]+Omin2);
                }
            }
        }
        cout<<dp[0][n-1]<<endl;
    }
}
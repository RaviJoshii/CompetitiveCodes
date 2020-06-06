// Count number of ways to partition a set into k subsets
// https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/
#include<iostream>
#include<vector>
using namespace std;
  
int countP(int n, int k) 
{ 
    vector<vector<int>> dp(n+1,vector<int>(k+1));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(j==1||j==i){
                dp[i][j]=1;
            }
            else{
                dp[i][j]=dp[i-1][k-1]+j*dp[i-1][k];
            }
        }
    }
    // for(int i=0;i<dp.size();i++){
    //     for(int j=0;j<dp[0].size();j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[n][k];
}
int main() 
{ 
   cout << countP(5, 2); 
   return 0; 
} 
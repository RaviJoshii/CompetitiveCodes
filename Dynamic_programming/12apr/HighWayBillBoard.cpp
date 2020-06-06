// https://www.geeksforgeeks.org/highway-billboard-problem/
// Highway Billboard Problem
#include<bits/stdc++.h>
using namespace std;
int main(){
    int miles=14;
    vector<int> distance={6, 9, 12, 14};
    vector<int> revenue={5, 6, 3, 7};
    vector<int> dp(miles+1,0);
    int nextI=0;
    int t=2;
    int prevB=-t;
    dp[0]=0;
    for(int i=1;i<=miles;i++){
        if(i==distance[nextI]){
            if(i-prevB>=t){
                dp[i]=max(dp[i-1],dp[i-1]+revenue[nextI]);
                nextI++;
                prevB=i;
            }
            else{
                dp[i]=dp[i-1];
            }
        }
        else{
            dp[i]=dp[i-1];
        }
    }
    // for(int i=0;i<=miles;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    cout<<dp[miles]<<endl;
    return 0;
}
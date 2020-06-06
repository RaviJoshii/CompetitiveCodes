// https://www.geeksforgeeks.org/count-palindromic-subsequence-given-string/
// Count All Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        vector<vector<int>> dp(str.size(),vector<int>(str.size()));
        for(int g=0;g<dp.size();g++){
            for(int i=0;i<dp.size()-g;i++){
                int j=i+g;
                if(g==0){
                    dp[i][j]=1;
                }
                else if(g==1){
                    if(str[i]==str[j]){
                        dp[i][j]=3;
                    }
                    else{
                        dp[i][j]=2;
                    }
                }
                else{
                    if(str[i]==str[j]){
                        dp[i][j]=1+dp[i][j-1]+dp[i+1][j];
                    }
                    else{
                        dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
                    }
                }
            }
        }
        cout<<dp[0][dp.size()-1]<<endl;
    }
    return 0;
}
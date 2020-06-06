// https://leetcode.com/problems/wildcard-matching/
// Wildcard Matching
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int sl=s.length();
        int pl=p.length();
        vector<vector<bool>> dp(pl+1,vector<bool>(sl+1));
        dp[0][0]=true;
        for(int j=1;j<=sl;j++){
            dp[0][j]=false;
        }
        for(int i=1;i<=pl;i++){
            if(p[i-1]=='*'){
                dp[i][0]=dp[i-1][0];
            }
            else{
                dp[i][0]=false;
            }
        }
        for(int i=1;i<=pl;i++){
            for(int j=1;j<=sl;j++){
                
                if(p[i-1]==s[j-1]){
                    //character matches;
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i-1]=='*'){
                    bool inc=dp[i][j-1];
                    bool exc=dp[i-1][j];

                    dp[i][j]=inc||exc;
                }
                else if(p[i-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[i-1]!=s[j-1]){
                    //character doesnt match
                    dp[i][j]=false;
                }
            }
        }
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[pl][sl];
    }
};
int main(){
    Solution s;
    cout<<s.isMatch("cb","?a");
}
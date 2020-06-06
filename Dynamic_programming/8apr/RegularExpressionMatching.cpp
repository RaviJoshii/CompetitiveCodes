// https://leetcode.com/problems/regular-expression-matching/
//  Regular Expression Matching

/*Solution:
1, If p.charAt(j) == s.charAt(i) :  dp[i][j] = dp[i-1][j-1];
2, If p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1];
3, If p.charAt(j) == '*': 
   here are two sub conditions:
               1   if p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2]  //in this case, a* only counts as empty
               2   if p.charAt(i-1) == s.charAt(i) or p.charAt(i-1) == '.':
                              dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a 
                           or dp[i][j] = dp[i][j-1]   // in this case, a* counts as single a
                           or dp[i][j] = dp[i][j-2]   // in this case, a* counts as empty

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int sl=s.length();
        int pl=p.length();
        if(pl==0||sl==0){
            return false;
        }
        vector<vector<bool>> dp(pl+1,vector<bool>(sl+1,false));
        dp[0][0]=true;
        for(int i=1;i<=pl;i++){
            if (p[i-1] == '*' && dp[i-2][0]) {
                dp[i][0] = true;
            }
        }
        for(int i=1;i<=pl;i++){
            for(int j=1;j<=sl;j++){
                if((p[i-1]=='.')||(p[i-1]==s[j-1])){
                        dp[i][j]=dp[i-1][j-1];
                    }
                if(p[i-1]=='*'){
                    if (p[i-2] != s[j-1] && p[i-2] != '.') {
                        dp[i][j] = dp[i][j-2];
                    } else {
                        dp[i][j] = (dp[i][j-1] || dp[i-1][j] || dp[i][j-2]);
                    }
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
    cout<<s.isMatch("mississippi","mis*is*ip*.");
    return 0;
}

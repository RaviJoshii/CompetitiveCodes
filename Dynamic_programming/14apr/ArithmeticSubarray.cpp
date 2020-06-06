// https://leetcode.com/problems/arithmetic-slices/
// Arithmetic Slices
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3){
            return 0;
        }
        vector<int> dp(A.size());
        dp[0]=0;
        dp[1]=0;
        int prev1,prev2;
        prev1=A[1]-A[0];
        int ans=0;
        for(int i=2;i<A.size();i++){
            prev2=prev1;
            prev1=A[i]-A[i-1];
            if(prev1==prev2){
                dp[i]=dp[i-1]+1;
                ans+=dp[i];
            }
            else{
                dp[i]=0;
            }

        }
        return ans;
    }
    
};
int main(){
    Solution s;
    vector<int> arr={1,3,5,7,9,15,20,25,27,29};
    cout<<s.numberOfArithmeticSlices(arr);
}
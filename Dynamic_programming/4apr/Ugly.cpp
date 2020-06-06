// https://www.geeksforgeeks.org/ugly-numbers/
// Ugly Numbers
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int tes;
    cin>>tes;
    for(int t=0;t<tes;t++){
        int n;
        cin>>n;
        int v2p=0;
        int v3p=0;
        int v5p=0;
        vector<int> dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=min(dp[v2p]*2,min(dp[v3p]*3,dp[v5p]*5));
            if(dp[i]==dp[v2p]*2) v2p++;
            if(dp[i]==dp[v3p]*3)v3p++;
            if(dp[i]==dp[v5p]*5)v5p++;
        }
        cout<<dp[n-1]<<endl;
    }
	//code
	return 0;
}
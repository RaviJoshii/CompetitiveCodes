// https://leetcode.com/problems/domino-and-tromino-tiling/
//  Domino and Tromino Tiling
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numTilings(int N) {
        vector<long> f(N+1);
        int mod=1e9+7;
        if(N<1){
            return 0;
        }
        if(N==1){
            return 1;
        }
        else if(N==2){
            return 2;
        }
        f[0]=1;
        f[1]=1;
        f[2]=2;
        for(int i=3;i<=N;i++){
            f[i]=(f[i-1]%mod+f[i-1]%mod+f[i-3]%mod)%mod;
        }
        return f[N]%mod;
    }
};
int main(){
    Solution s;
    int n;
    cin>>n;
    cout<<s.numTilings(n)<<endl;
    return 0;
}
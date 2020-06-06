// https://practice.geeksforgeeks.org/problems/friends-pairing-problem/0
// Friends Pairing Problem
#include <iostream>
typedef long long ll;
using namespace std;
ll countFriendsPairings(int n) 
{   int mod=1000000007;
    if(n<=2){
        return n;
    }
    ll prev2=1;//f(n-2);
    ll prev1=2;//f(n-1);
    ll curr=0;
    for(ll i=3;i<=n;i++){
        curr=((prev1)+((i-1)*prev2)%mod)%mod;
        prev2=prev1;
        prev1=curr;
    }
    return curr;
} 
int main() {
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<countFriendsPairings(n)<<endl;
    }
	return 0;
}
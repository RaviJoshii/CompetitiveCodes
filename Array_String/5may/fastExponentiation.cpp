// https://www.geeksforgeeks.org/write-an-iterative-olog-y-function-for-powx-y/
// Write an iterative O(Log y) function for pow(x, y)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll powers(ll x,ll n){
    ll ans=1;
    while(n>0){
        if(n%2!=0){
            ans=ans*x;
        }
        x=x*x;
        n=n/2;
    }
    return ans;
}
int main(){
    ll x,n;
    cin>>x>>n;
    cout<<powers(x,n);
}
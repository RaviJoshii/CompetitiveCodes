// https://www.spoj.com/problems/DCEPC11B/
// DCEPC11B - Boring Factorials
// http://spoj-solutions.blogspot.com/2014/05/dcepc11b-boring-factorials.html

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fastExponentiation(ll x, ll n,ll p){
    ll ans=1;
    while(n>0){
        if(n%2!=0){
            n--;
            ans=((ans)*(x))%p;
        }
        x=((x)*(x))%p;
        n=n/2;
    }
    return ans%p;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,p;
        cin>>n>>p;
        ll ans=1;
        if(n>=p){
            ans=0;
        }else{
            ans=p-1;
            for(ll i=n+1;i<p;i++){
                int temp=fastExponentiation(i,p-2,p);
                // cout<<temp<<" -"<<i<<","<<p-2<<endl;
                ans=((ans)*temp)%p;
                
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
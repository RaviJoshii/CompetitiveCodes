// https://practice.geeksforgeeks.org/problems/max-sum-in-sub-arrays/0
// Max sum in sub-arrays
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> vec(n);
        for(ll i=0;i<n;i++){
           cin>>vec[i];
        }
        ll ans=0;
        for(ll i=0;i<n-1;i++){
            ll sum=vec[i]+vec[i+1];
            if(sum>ans){
                ans=sum;
            }
        }
        cout<<ans<<endl;
    }
    


    
    return 0;

}
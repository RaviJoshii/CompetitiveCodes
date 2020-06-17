// https://www.codechef.com/SNCKPE19/problems/BUDDYNIM
// Buddy NIM 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> alice(n,0);
        vector<ll> bob(m,0);
        ll sum1=0;
        ll sum2=0;
        for(ll i=0;i<n;i++){
            cin>>alice[i];
            sum1+=alice[i];
        }

        for(ll i=0;i<m;i++){
            cin>>bob[i];
            sum2+=bob[i];
        }
        if(sum1!=sum2){
            cout<<"Alice"<<endl;
        }
        else{   
                    //check for structure same;
                    sort(alice.begin(),alice.end(),greater<ll>());
                    sort(bob.begin(),bob.end(),greater<ll>());
                    bool flag=false;
                    for(ll i=0;i<n;i++){
                        if(alice[i]!=bob[i]){
                            flag=true;
                            break;
                        }
                    }
                    if(flag==true){
                        cout<<"Alice"<<endl;
                    }else{
                        cout<<"Bob"<<endl;
                    }
                   

            }

        
    }
    return 0;
}
// https://www.codechef.com/JULY18A/problems/NMNMX
// No Minimum No Maximum
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int fastExponentiation(ll x,ll n,int m){
    int ans=1;
    while(n>0){
        if(n&1){
            ans=(ans*x)%m;
            n--;
        }
        n=n>>1;
        x=(x*x)%m;
    }
    return ans;
}
void preprocessing(vector<vector<ll> > &ncr,ll m){
    int k=ncr[0].size();
    for(int i=0;i<ncr.size();i++){
        for(int j=0;j<=min(i,k);j++){
            if(i==j || j==0){
                ncr[i][j]=1;
            }else{
                ncr[i][j]=(ncr[i-1][j-1]+ ncr[i-1][j])%m;
            }
         }
    }
}
int main(){
    int m=1e9+7;
    int t;
    cin>>t;
     vector<vector<ll>> ncr(5001,vector<ll>(5001,0));
    preprocessing(ncr,m-1);
    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int> vec(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>vec[i];
        }
        long long ans=1;
        sort(vec.begin()+1,vec.end());
        
        for(int i=1;i<vec.size();i++){
            ll temp= ncr[n-1][k-1] -ncr[n-i][k-1] - ncr[i-1][k-1];
            temp= temp + 2*(m-1); // we have done 2*(m-1) to avoid negative number 
            // as negative number can be possible  upto -2*m due to this=> (-ncr[n-i][k-1] - ncr[i-1][k-1];) in upper statement
            temp=temp%(m-1);
            ans=(ans*fastExponentiation(vec[i],temp,m))%m;     
        }
        cout<<ans<<endl;
    }
    return 0;
    }
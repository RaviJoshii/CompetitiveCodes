// https://www.spoj.com/problems/ETF/
// ETF - Euler Totient Function

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);



int main() {
    int t;
    fast_io();
    cin>>t;
    vector<int> arr(1000005,0);
    arr[0]=-1;
    arr[1]=-1;
    for(int i=2;i<arr.size();i++){
        arr[i]=i;
    }

    for(int i=2;i<=sqrt(arr.size());i++){
        if(arr[i]==i){
            for(int j=i*i;j<arr.size();j=j+i){
                if(arr[j]==j){
                    arr[j]=i;
                }
            }
        }
    }
    while(t--){
        int n;
        cin>>n;
        //calculating number of primes
        
        vector<int> vis(n+1,0);
        int ans =n;
        while(n>=0 && arr[n]!=-1){

            int num=arr[n];//prime factor

            if(vis[num]==0){
                //avoid duplicate prime factors
                //cout<<num<<" - "<<ans<<"--- "<<ans-(ans/num)<<endl;
              ans=(ans-(ans/num));  
              vis[num]=1;
            }
            
            n=n/arr[n];
            // cout<<num<<" - "<<1-(1/num)<<endl;
            
            
        }
        cout<<ans<<endl;
    }

	return 0;
}
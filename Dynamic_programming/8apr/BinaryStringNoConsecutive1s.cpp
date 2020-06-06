// https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/
// Count number of binary strings without consecutive 1’s
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
    fast_io();
    int t;
    cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    ll c0=1,c1=1;
	    int temp=1;
	    for(int i=1;i<n;i++){
	        temp=c0;
	        c0=(c0+c1)%MOD;
	        c1=temp%MOD;
	    }
        cout<<(c0+c1)%MOD<<endl;
	    
	}
	return 0;
}
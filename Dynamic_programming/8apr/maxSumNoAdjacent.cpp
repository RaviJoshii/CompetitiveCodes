// https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
// Maximum sum such that no two elements are adjacent
#include <bits/stdc++.h>
using namespace std;
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
    fast_io();
    int t;
    cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    if(n<1){
	        cout<<"0";
            continue;
	    }
	    vector<int> a(n);
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    int inc=a[0];
	    int exc=0;
	    int temp;
	    for(int i=1;i<n;i++){
	        temp=inc;
	        inc=a[i]+exc;
	        exc=max(exc,temp);
	    }
	    cout<<max(inc,exc)<<endl;
	    
	}
	return 0;
}
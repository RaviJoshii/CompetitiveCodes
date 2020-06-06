// https://www.codechef.com/JAN18/problems/KCON
// K-Concatenation
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll kadanes(vector<ll> &nums){
    if(nums.size()==0){
            return 0;
        }
        ll cmax=nums[0];
        ll omax=nums[0];
        for(ll i=1;i<nums.size();i++){
            cmax=max(nums[i],nums[i]+cmax);
            omax=max(omax,cmax);
        }
        return omax;
}
int main() {
	ll t;
	cin>>t;
	while(t--){
	    ll n,k;
	    cin>>n>>k;
	    vector<ll> arr;
	    ll sum=0;
		int x;
	    for(ll i=0;i<n;i++){
			cin>>x;
	        arr.push_back(x);
	        sum+=x;
	    }

	    

		if(k>1){
			for(ll i=0;i<n;i++){
				arr.push_back(arr[i]);
			}

			ll ans=0;
			ll kadV=kadanes(arr);
			// cout<<kadV<<" - "<<sum<<endl;
			if (sum>=0){
				ans=kadV+sum*(k-2);
			}else{
				ans=kadV;
			}
			cout<<ans<<endl;
		}
		else{
			cout<<kadanes(arr)<<endl;
		}
	    
	}
	return 0;
}

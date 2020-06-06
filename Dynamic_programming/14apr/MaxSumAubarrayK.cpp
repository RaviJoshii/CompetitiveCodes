// https://www.geeksforgeeks.org/largest-sum-subarray-least-k-numbers/
// Largest sum subarray with at-least k numbers
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cin>>k;
	    vector<int> kad(n);
	    kad[0]=arr[0];
	    for(int i=1;i<n;i++){
	        kad[i]=max(arr[i],arr[i]+kad[i-1]);
	    }
        //calculating the first sliding window;
        for(int i=arr.size()-1;i>arr.size()-k;i--){
			
        }

	    
	    
	}
	return 0;
}
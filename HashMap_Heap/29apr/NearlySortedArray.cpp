// https://www.geeksforgeeks.org/nearly-sorted-algorithm/
// Sort a nearly sorted (or K sorted) array
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    vector<int> vec(n);
	    for(int i=0;i<n;i++){
	        cin>>vec[i];
	    }
	    priority_queue<int,vector<int> ,greater<int>> pq;
	    int idx=-1;
	    for(int i=0;i<k;i++){
	        pq.push(vec[i]);
	        idx++;
	    }
	    if(k>n){
	        pq.push(vec[k]);
	        idx++;
	    }
	    while(pq.size()>0){
	        cout<<pq.top()<<" ";
	        pq.pop();
	        
	        idx++;
	        if(idx<n){
	            pq.push(vec[idx]);
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
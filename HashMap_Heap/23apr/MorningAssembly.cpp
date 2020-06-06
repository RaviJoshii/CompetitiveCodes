// https://practice.geeksforgeeks.org/problems/morning-assembly/0
// Morning Assembly
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> vec(n);
	    unordered_map<int,int> umap;
	    for(int i=0;i<n;i++){
	        cin>>vec[i];
	    }
	    int len=INT_MIN;
	    for(int i=0;i<n;i++){
	        int check=vec[i]-1;
	        if(umap.find(check)!=umap.end()){
	            umap[vec[i]]=umap[check]+1;
	        }
	        else{
	            umap[vec[i]]=1;
	        }
	        len=max(len,umap[vec[i]]);
	    }
	    cout<<n-len<<endl;
	}
	return 0;
}
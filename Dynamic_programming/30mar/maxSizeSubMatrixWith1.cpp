// https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
// Maximum size square sub-matrix with all 1s
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int>> vec(n,vector<int>(m));
	    for(int j=0;j<n;j++){
	        for(int k=0;k<m;k++){
	            cin>>vec[j][k];
	        }
	    } 
        int ans=1;
	    for(int j=n-2;j>=0;j--){
	        for(int k=m-2;k>=0;k--){
	            if(vec[j][k]!=0){
	                vec[j][k]=min(min(vec[j][k+1],vec[j+1][k+1]),
	                                                    vec[j+1][k])+1;
                    ans=max(ans,vec[j][k]);
	            }
	        }
	    }
        
	    cout<<ans<<endl;
	    
	}
	return 0;
}
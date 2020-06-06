// https://www.codechef.com/problems/MAXREMOV
// Max Range Queries 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
	int t;
	cin>>t;
	vector<int> arr(100005);
	
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int l,r;
	    vector<int> L(n);
	    vector<int> R(n);

		arr[0]=0;//dummy value - 1-based indexing //index-0 will never used
		for(int i=0;i<arr.size();i++){
			arr[i]=0;
		}
	    for(int i=0;i<n;i++){
	        cin>>L[i]>>R[i];
			
	        arr[L[i]]+=1;
	        arr[R[i]+1]-=1;
	    }
	    // printV(L);
        // printV(R);
		vector<int> CK(arr.size(),0);
	    vector<int> CK1(arr.size(),0);
		int OverallK=0;

	    for(int i=1;i<=arr.size();i++){
			//calculating prefix count of arr;
	        arr[i]+=arr[i-1];
			if(arr[i]==k){
				OverallK++;
			}


			//calculating prefix count of ck,ck+1
			CK[i]=CK[i-1];
			CK1[i]=CK1[i-1];
	        if(arr[i]==k){
	            CK[i]++;
	        }
	        else if(arr[i]==k+1){
	            CK1[i]++;
	        }

	    }
		
        // printV(arr);
        // printV(CK);
        // printV(CK1);
	    int ans=INT_MIN;
	    for(int i=0;i<n;i++){
            int gain=CK1[R[i]]-CK1[L[i]-1];
            int loss=CK[R[i]]-CK[L[i]-1];
	        int co=OverallK+gain-loss;
	        ans=max(ans,co);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}

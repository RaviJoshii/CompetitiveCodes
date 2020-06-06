// https://www.geeksforgeeks.org/count-subarrays-equal-number-1s-0s/
// Count subarrays with equal number of 1’s and 0’s
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> count0(n);
        vector<int> count1(n);
        if(arr[0]==1){
            count0[0]=0;
            count1[0]=1;
        }
        else{
            count0[0]=1;
            count1[0]=0;
        }
        for(int i=1;i<n;i++){
            if(arr[i]==0){
                count0[i]=count0[i-1]+1;
                count1[i]=count1[i-1];
            }
            else{
                count1[i]=count1[i-1]+1;
                count0[i]=count0[i-1];
            }
        }
        unordered_map<int,int> umap;
        umap[0]=1;
        int diff;
        int ans=0;
        for(int i=0;i<n;i++){
            diff=count0[i]-count1[i];
            if(umap.find(diff)!=umap.end()){
                ans+=umap[diff];
                umap[diff]++;
            }
            else{
                umap[diff]=1;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
// https://www.geeksforgeeks.org/count-pairs-in-array-whose-sum-is-divisible-by-k/
// Count pairs in array whose sum is divisible by K
#include <bits/stdc++.h>
using namespace std;
int countK(int k,vector<int> &vec){
    unordered_map<int,int> umap;
    int ans=0;
    for(int i=0;i<vec.size();i++){
        if(vec[i]<0){
            vec[i]+=k;
        }
        int check=(k-vec[i])%k;
        if(umap.find(check)!=umap.end()){
            ans+=umap[check];
        }
        umap[vec[i]]++;
        // cout<<vec[i]<<endl;
        // for(auto it:umap){
        //     cout<<it.first<<" - "<<it.second<<endl;
        // }
        // cout<<"******  "<<ans<<"  ***********"<<endl;

    }
    
    return ans;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k=4;
        int x;
        vector<int> vec(n);
        for(int i=0;i<n;i++){
            cin>>x;
            vec[i]=x%k;
        }
        
        cout<<countK(4,vec)<<endl;

    }
	return 0;
}
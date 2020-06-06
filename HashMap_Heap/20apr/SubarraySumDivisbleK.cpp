// https://leetcode.com/problems/subarray-sums-divisible-by-k/
// Subarray Sums Divisible by K

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        int n=A.size();
        if(n<1){
            return 0;
        }
        int ans=0;
        vector<int> vec(n);
        unordered_map<int,int> umap;
        umap[0]=1;
        // vec[0]=(A[0]%k+k)%k;
        int prev=0;
        for(int i=0;i<n;i++){
            int prefixSum=A[i]+prev;
            vec[i]=(prefixSum%k+k)%k;
            prev=prefixSum;
        }
        for(int i=0;i<vec.size();i++){
            int remj=vec[i];
            if(umap.find(remj)!=umap.end()){
                ans+=umap[remj];
                umap[remj]++;
            }
            else{
                umap[remj]=1;
            }
        }
        // for(auto P:umap){
        //     cout<<P.first<<" - "<<P.second;
        //     cout<<endl;
        // }
        // cout<<endl;
        return ans;
    }
    
};
int main(){
    vector<int> vec={2,3,1,7,4,-18,6,3,4,-14,2,9};
    Solution s;
    int k=5;
    cout<<s.subarraysDivByK(vec,k);
    return 0;
}
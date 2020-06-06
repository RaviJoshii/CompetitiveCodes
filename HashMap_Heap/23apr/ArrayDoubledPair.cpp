// https://leetcode.com/problems/array-of-doubled-pairs/
// Array of Doubled Pairs

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int,int> umap;
        for(int i=0;i<A.size();i++){
            if(umap.find(A[i])!=umap.end()){
                umap[A[i]]++;
            } else{
                umap[A[i]]=1;
            }
        }
        sort(A.begin(),A.end());
        for(int i=0;i<A.size();i++){
            if(umap[A[i]]>0){
                double check;
                if(A[i]<0){
                    check=A[i]/2;
                } else{
                    check=A[i]*2;
                }
                if(umap.find(check)==umap.end() || umap[check]<1){
                    return false;
                }
                umap[A[i]]--;
                umap[check]--;
            }
        }
        return true;
    }
};
int main(){
    // vector<int> vec={3,1,3,6};
    // vector<int> vec={2,1,2,6};
    vector<int> vec={4,-2,2,-4};
    Solution s;
    cout<<s.canReorderDoubled(vec);
    return 0;
}
// https://leetcode.com/problems/pizza-with-3n-slices/
// Pizza With 3n Slices
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int KMaxSum(vector<int> arr,int k){
        vector<vector<int> > Inc(k+1,vector<int>(arr.size()));
        vector<vector<int> > Exc(k+1,vector<int>(arr.size()));
        for(int i=0;i<arr.size();i++){
            Inc[0][i]=0;
            Exc[0][i]=0;
        }
        for(int i=0;i<=k;i++){
            Inc[i][0]=arr[0];
            Exc[i][0]=0;
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<arr.size();j++){
                Inc[i][j]=arr[j]+Exc[i-1][j-1];
                Exc[i][j]=max(Exc[i][j-1],Inc[i][j-1]);
            }
        }

        return max(Inc[k][arr.size()-1],Exc[k][arr.size()-1]);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size()/3;
        vector<int> a(slices.begin(),slices.end()-1);
        vector<int> b(slices.begin()+1,slices.end());
        return max(KMaxSum(a,k),KMaxSum(b,k));
        
    }
};
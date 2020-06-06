// https://leetcode.com/problems/k-th-smallest-prime-fraction/
// K-th Smallest Prime Fraction

#include<bits/stdc++.h>
using namespace std;
class pairs{
    public:
    double val;//        val = num/deno
    int numI;//numeratorIndex
    int denoI;//denomentorIndex
    pairs(double val,int i,int j){
        this->val=val;
        this->numI=i;
        this->denoI=j;
    }
    bool operator>(const pairs &p2)const{
        return this->val>p2.val;
    }
};
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int n=A.size();
        priority_queue<pairs,vector<pairs>,greater<pairs>> pq;
        for(int i=0;i<n-1;i++){
            pq.push(pairs((A[i]*(1.0))/A[n-1],i,n-1));
        }
        // while(pq.size()>0){
        //     cout<<A[pq.top().numI]<<" "<<A[pq.top().denoI]<<endl;
        //     pq.pop();
        // }
        
        while(--K>0){
            pairs temp=pq.top();
            // cout<<A[pq.top().numI]<<" "<<A[pq.top().denoI]<<endl;
            pq.pop();
            // double val=temp1.val;
            int numI=temp.numI;
            int denoI=temp.denoI;
            denoI--;
            if(denoI>numI){
                pq.push(pairs((A[numI]*(1.0))/A[denoI],numI,denoI));
            }
        }
        return {A[pq.top().numI],A[pq.top().denoI]};
        
    }
};
int main(){
    vector<int> A={1, 2, 3, 5};
    int k=3;
    Solution s;
    vector<int> ans=s.kthSmallestPrimeFraction(A,k);
    for(int p: ans){
        cout<<p<<" ";
    }
    return 0;
}
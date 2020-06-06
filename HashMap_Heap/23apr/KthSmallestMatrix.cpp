// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Kth Smallest Element in a Sorted Matrix
#include<bits/stdc++.h>
using namespace std;
class pairs{
    public:
    int val;
    int i;
    int j;
    pairs(int val,int i,int j){
        this->val=val;
        this->i=i;
        this->j=j;
    }
    bool operator>(const pairs &p2)const{
        return this->val>p2.val;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<pairs,vector<pairs>,greater<pairs>> pq;
        for(int i=0;i<n;i++){
            pq.push(pairs(matrix[i][0],i,0));
        }
        int count=0;
        int ans=-1;
        while(pq.size()>0){
            pairs temp1=pq.top();
            pq.pop();
            int val=temp1.val;
            int x=temp1.i;
            int y=temp1.j;
            count++;
            if(count==k){
                ans=val;
                break;
            }
            if(y+1<n){
                pq.push(pairs(matrix[x][y+1],x,y+1));
            }
            
        }
        return ans;
        
    }
};
int main(){
    vector<vector<int>> matrix={
   { 1,  5,  9},
   {10, 11, 13},
   {12, 13, 15}
   };
    int k=8;
    Solution s;
    cout<<s.kthSmallest(matrix,k);
    return 0;
}
// https://leetcode.com/problems/partition-array-into-disjoint-intervals/
// Partition Array into Disjoint Intervals
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        if(A.size()==0){
            return 0;
        }
        int nextMax=A[0];
        int cmax=A[0];
        int clen=1;
        for(int i=1;i<A.size();i++){
            if(A[i]<cmax){
                cmax=nextMax;
                clen=i+1;
                
            }else{
                // A[i]>cmax;
                nextMax=max(nextMax,A[i]);
            }
            
        }
        
        return clen;
    }
};
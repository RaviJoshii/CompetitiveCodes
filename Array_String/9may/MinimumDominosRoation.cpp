// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/submissions/
// Minimum Domino Rotations For Equal Row
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if(A.size()==0 || B.size()==0){
            return 0;
        }
        int val1=A[0];
        int val2=B[0];
        int Aval1=0; int Aval2=0; int Bval1=0; int Bval2=0;
        for(int i=0;i<A.size();i++){
            
            if(Aval1!=INT_MAX){
                if(A[i]==val1){
                    //do nothing
                }else if(B[i]==val1){
                    Aval1++;
                }else {
                    Aval1=INT_MAX;
                }
                
            }
            if(Aval2<INT_MAX){
                if(A[i]==val2){
                    //do nothing
                }else if(B[i]==val2){
                    Aval2++;
                }else {
                    Aval2=INT_MAX;
                }
                
            }
            if(Bval1<INT_MAX){
                if(B[i]==val1){
                    //do nothing
                }else if(A[i]==val1){
                    Bval1++;
                }else {
                    Bval1=INT_MAX;
                }
                
            }
            if(Bval2<INT_MAX){
                if(B[i]==val2){
                    //do nothing
                }else if(A[i]==val2){
                    Bval2++;
                }else {
                    Bval2=INT_MAX;
                }
                
            }
            
            
        }
        int ans =min(min(Aval1,Aval2),min(Bval1,Bval2));
        if(ans==INT_MAX){
            ans=-1;
        }
        return ans;
    }
};
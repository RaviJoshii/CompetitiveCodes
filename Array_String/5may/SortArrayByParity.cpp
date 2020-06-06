// https://leetcode.com/problems/sort-array-by-parity/
// Sort Array By Parity
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i=0;
        int j=0;
        int temp;
        while(j<A.size()){
            if(A[j]%2==0){
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
                i++;
            }
            j++;
        }
        return A;
    }
};
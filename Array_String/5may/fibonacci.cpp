// https://leetcode.com/problems/fibonacci-number/
// Fibonacci Number
// O(log n)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> multiply(vector<vector<int>> A,vector<vector<int>> B){
        vector<vector<int>> ans(2,vector<int>(2,0));
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 2; ++j){
                for(int k = 0; k < 2; ++k)
                {
                    ans[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return ans;

    }
    int fib(int N) {
        if(N==0){
            return 0;
        }
        vector<vector<int>> ans(2,vector<int>(2,0));
        int flag=true;
        vector<vector<int>> mat={{1,1},{1,0}};
        while(N>0){
            if(N%2!=0){
                if(flag){
                    //first time
                    ans=mat;
                    flag=false;
                }else{
                    ans=multiply(ans,mat);
                }
                N--;//N become even
            }
            mat=multiply(mat,mat);
            N=N/2;

        }
        return ans[0][1];
    }

};
int main(){
    Solution s;
    int n;
    cin>>n;
    cout<<s.fib(n);
    return 0;
}
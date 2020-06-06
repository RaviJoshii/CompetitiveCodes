// https://leetcode.com/problems/knight-probability-in-chessboard/
// https://www.geeksforgeeks.org/probability-knight-remain-chessboard/
// Probability of Knight to remain in the chessboard
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dx={-2,-1,1,2,2,1,-1,-2};
    vector<int> dy={1,2,2,1,-1,-2,-2,-1};
    bool isSafe(int x,int y,int N){
        if(x<0||y<0||x>=N||y>=N){
            return false;
        }
        return true;
    }
    void fillWith0(vector<vector<double>> &arr){
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                arr[i][j]=0;
            }
        }
    }
    void fillWithData(double data,int r,int c,int N,vector<vector<double>> &dp){
        for(int i=0;i<dx.size();i++){
            if(isSafe(r+dx[i],c+dy[i],N)){
                dp[r+dx[i]][c+dy[i]]+=data;
            }
        }
    }
    void printVector(vector<vector<double>> &arr){
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp1(N,vector<double>(N,0));
        vector<vector<double>> dp2(N,vector<double>(N,0));
        vector<vector<double>> temp;
        dp1[r][c]=1;//for K=0
        for(int k=1;k<=K;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(dp1[i][j]>0){
                        double data=dp1[i][j]/8;
                        fillWithData(data,i,j,N,dp2);
                    }
                }
            }
            
            // printVector(dp1);
            // cout<<endl;
            // printVector(dp2);
            // cout<<"******************"<<endl;
            dp1=dp2;
            fillWith0(dp2);//clear dp2 to 0 value;
        }
        // cout<<"******************1"<<endl;
        // printVector(dp1);
        double ans=0;
        for(int t1=0;t1<N;t1++){
            for(int t2=0;t2<N;t2++){
                ans=ans+dp1[t1][t2];
            }
        }
        // cout<<ans<<endl;
        return ans;
    }
};

int main(){
    Solution s;

    cout<<s.knightProbability(3, 2, 0, 0);
    return 0;
}
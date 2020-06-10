// https://leetcode.com/problems/number-of-enclaves/
//  Number of Enclaves
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
        vector<int> dx={0,1,0,-1};
        vector<int> dy={1,0,-1,0};
    
    void DFS(vector<vector<int>>& A,int x,int y){
        
        if(A[x][y]!=1){
            return ;
        }
        A[x][y]=0;



        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || ny<0 || nx>=A.size() || ny>=A[0].size() ){
                continue;
            }
            
            if(A[nx][ny]==1){
                DFS(A,nx,ny);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& A) {

        for(int i=0;i<A.size();i++){
            if(A[i][0]==1){
                DFS(A,i,0);
            }
            if(A[i][A[0].size()-1]==1){
                DFS(A,i,A[0].size()-1);
            }
        }
        for(int j=0;j<A[0].size();j++){
                if(A[0][j]==1){
                    DFS(A,0,j);
                }
                if(A[A.size()-1][j]==1){
                    DFS(A,A.size()-1,j);
                }
        }


        int ans=0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                if(A[i][j]==1){
                    
                    ans++;
                }
            }
        }

        return ans;
    }
    
};

int main(){
    Solution s;
    vector<vector<int>> vec={{0,0,0,0},
                             {1,0,1,0},
                             {0,1,1,0},
                             {0,0,0,0}};
    cout<<s.numEnclaves(vec);
}
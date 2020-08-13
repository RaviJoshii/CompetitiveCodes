// https://leetcode.com/problems/shortest-bridge/
// Shortest Bridge
#include<bits/stdc++.h>
using namespace std;
class item{
    public:
    int x,y;
    int dis;
    item(int x,int y,int dis){
        this->dis=dis;
        this->x=x;
        this->y=y;
    }
};
class Solution {
public:
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};

    void dfs(int i,int j,vector<vector<int>>& A){
        
        A[i][j]=4;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0 && nx<A.size() && ny<A[0].size() && ny>=0){
                if(A[nx][ny]==1){
                    dfs(nx,ny,A);
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
        for(int i=0;i<A.size();i++){
            bool flag=false;
            for(int j=0;j<A[0].size();j++){

                if(A[i][j]==1){
                    //change the value of island
                    dfs(i,j,A);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }

        // for(int i=0;i<A.size();i++){
        //     for(int j=0;j<A[0].size();j++){
        //         cout<<A[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        queue<item> que;

        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){

                if(A[i][j]==4){
                    que.push(item(i,j,0));
                }
            }
        }



        while(que.size()>0){
            item rem=que.front();
            que.pop();
            int x=rem.x;
            int y=rem.y;
            int dis=rem.dis;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                int newDis=dis+1;
                if(nx>=0 && nx<A.size() && ny<A[0].size() && ny>=0){
                    if(A[nx][ny]==1){
                        return newDis-1;
                    }
                    else if(A[nx][ny]==0){
                        A[nx][ny]=4;
                        que.push(item(nx,ny,newDis));
                    }
                }
            }
        }
        return 1;
    }
};
int main(){
    // vector<vector<int> > vec={{1,1,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
    vector<vector<int> > vec={{0,1},{1,0}};
    Solution s;
    cout<< s.shortestBridge(vec);
    return 0;
}
// https://leetcode.com/problems/01-matrix/
//  01 Matrix

#include<bits/stdc++.h>
using namespace std;
class Item{
    public:
    int x,y,dis;
    Item(int x,int y,int dis){
        this->x=x;
        this->y=y;
        this->dis=dis;
    }
};
class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<int> dx={0,1,0,-1};   
        vector<int> dy={1,0,-1,0};
        vector<vector<int> > ans(matrix.size(),vector<int>(matrix[0].size(),-1));
        queue<Item> que;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    que.push(Item(i,j,0));
                }   
            }
        }

        while(que.size()>0){
            Item rem=que.front();
            que.pop();
            int x=rem.x;
            int y=rem.y;
            int dis=rem.dis;
            matrix[x][y]=0;
            if(ans[x][y]==-1){
               ans[x][y]=dis; 
            }
            
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || ny<0 || nx>=matrix.size() || ny>=matrix[0].size() ){
                    continue;
                }
                if(matrix[nx][ny]==1){
                    que.push(Item(nx,ny,dis+1));
                }
            }

        }
        return ans;
        
    }
};

int main(){
    Solution s;
    vector<vector<int>> vec={{0,1,0},
                             {0,1,0},
                             {0,1,0},
                             {0,1,0}};
    vector<vector<int>> ans=s.updateMatrix(vec);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
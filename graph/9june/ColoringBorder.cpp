// https://leetcode.com/problems/coloring-a-border/
//  Coloring A Border
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dx={0,1,0,-1};
    vector<int> dy={1,0,-1,0};
    
    void DFS(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& ans,int color,int prevColor){
        int c=0;


        //checking its adjacent 4 squares 
        for(int k=0;k<4;k++){

            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx<0 || ny<0 || nx>=grid.size() || ny>=grid[0].size()){
                continue;
            }
            if(grid[nx][ny]==prevColor ){
                c++;
            }

        }

        if(c<4){
            ans[i][j]=color;
        }else{
            ans[i][j]=prevColor;
        }


        //////////////////////////////////////////
        for(int k=0;k<4;k++){

            int nx=i+dx[k];
            int ny=j+dy[k];

            if(nx<0 || ny<0 || nx>=grid.size() || ny>=grid[0].size()){
                continue;
            }

            if(ans[nx][ny]==0 && grid[nx][ny]==prevColor){
                DFS(nx,ny,grid,ans,color,prevColor);
            }
            
                
        }

    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size(),0));
        int prevColor=grid[r0][c0];
        DFS(r0,c0,grid,ans,color,prevColor);

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(ans[i][j]==0){
                    ans[i][j]=grid[i][j];
                }
            }
        }
        return ans;

    }
};
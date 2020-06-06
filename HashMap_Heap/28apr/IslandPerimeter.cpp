// https://leetcode.com/problems/island-perimeter/
// Island Perimeter

#include <bits/stdc++.h>
using namespace std;class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int x=0;
                    
                    for(int k=0;k<dir.size();k++){
                        int nx=i+dir[k][0];
                        int ny=j+dir[k][1];
                        if(nx>=0 && ny>=0 && nx<n && ny<m){
                            if(grid[nx][ny]==1){
                                x++;
                            }
                        }
                        
                    }
                    ans+=(4-x);
                    
                    
                }
            }
        }
        return ans;
    }
};
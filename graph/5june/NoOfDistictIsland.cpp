// https://leetcode.com/problems/number-of-distinct-islands/
// https://www.lintcode.com/problem/number-of-distinct-islands/description
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string dfs(int x,int y , vector<vector<int>> &grid){
        string str="";
        if(x>=0 && y+1>=0 && x<grid.size() && y+1<grid[0].size() && grid[x][y+1]==1){
            //moving right;
            grid[x][y+1]=0;
            str=str+"R" + dfs(x,y+1,grid);
            

        }
        if(x+1>=0 && y>=0 && x+1<grid.size() && y<grid[0].size() && grid[x+1][y]==1){
            //moving down;
            grid[x+1][y]=0;
            str=str+"D" + dfs(x+1,y,grid);
        }
        if(x>=0 && y-1>=0 && x<grid.size() && y-1<grid[0].size() && grid[x][y-1]==1){
            //moving left;
            grid[x][y-1]=0;
            str=str+"L" + dfs(x,y-1,grid);
        }
        if(x-1>=0 && y>=0 && x-1<grid.size() && y<grid[0].size() && grid[x-1][y]==1){
            //moving top;
            grid[x-1][y]=0;
            str=str+"T" + dfs(x-1,y,grid);
        }
        
        return str+"B";
    }

    int numberofDistinctIslands(vector<vector<int>> &grid) {
        unordered_set<string >  mov;
        
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    string recans=dfs(i,j,grid);

                    if(mov.find(recans)==mov.end()){
                        ans++;
                        mov.insert(recans);
                    }
                }
            }
        }

        return ans;
    }
};

int main(){
    vector<vector<int>> vec={{1,1,0,1,1},
                             {1,0,1,1,0},
                             {0,0,1,0,0},
                             {1,1,0,1,1},
                             {1,0,0,1,0}};
    Solution s;
    cout<<s.numberofDistinctIslands(vec);


    return 0;
}
// https://leetcode.com/problems/rotting-oranges/
// Rotting Oranges

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> que;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                   que.push(make_pair(i,j)); 
                    grid[i][j]=0;
                }
                
            }
        }

        vector<int> dx={0,1,0,-1};
        vector<int> dy={1,0,-1,0};
        int times=0;
        while(que.size()>0){
            int sizes=que.size();
            for(int i=0;i<sizes;i++){

                pair<int,int>  rem=que.front();
                que.pop();

                int x=rem.first;
                int y=rem.second;

                for(int k=0;k<4;k++){

                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx<0 || ny<0 || nx>=grid.size() || ny>=grid[0].size()){
                        continue;
                    }
                    if(grid[nx][ny]==1){
                        que.push(make_pair(nx,ny));
                        grid[nx][ny]=0;
                    }
                }
            }

            times++; 
        }

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        if(times==0){
            return 0;
        }

        return times-1;
    }






};



int main(){
    vector<vector<int>> grid={{2,1,1},{1,1,0},{0,1,1}};
    Solution s;
    cout<<s.orangesRotting(grid);
    return 0;
}
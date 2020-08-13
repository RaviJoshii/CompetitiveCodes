// https://leetcode.com/problems/as-far-from-land-as-possible/
// As Far from Land as Possible
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
    int maxDistance(vector<vector<int>>& grid) {
        queue<item> que;
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    que.push(item(i,j,0));
                }
            }
        }

        int ans=-1;
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
                if(nx>=0 && nx<grid.size() && ny<grid[0].size() && ny>=0){
                    if(grid[nx][ny]==0){
                        grid[nx][ny]=1;
                        que.push(item(nx,ny,newDis));
                        ans=max(ans,newDis);
                    }
                }
            }

        }
        return ans;
    }
};
int main(){
    vector<vector<int>> vec={{1,0,0},{0,0,0},{0,0,0}};
    Solution s;
    cout<<s.maxDistance(vec);
    return 0;
}
// https://leetcode.com/problems/walls-and-gates/
// Walls and Gates
#include<bits/stdc++.h>
using namespace std;
#define inf 2147483647;
class Item{
    public:
    int x;int y;
    int distance;
    Item(int x,int y,int d){
        this->x=x;
        this->y=y;
        this->distance=d;
    }

};
class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        // write your code here

        queue<Item> que;
        vector<vector<int>> visited(rooms.size(),vector<int>(rooms[0].size(),0));
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                if(rooms[i][j]==0){
                    que.push(Item(i,j,0));
                    visited[i][j]=1;
                }
            }
        }
        
        vector<int> dx={0,1,0,-1};
        vector<int> dy={1,0,-1,0};


        while(que.size()>0){

            Item rem=que.front();
            que.pop();
            int x=rem.x;
            int y=rem.y;
            int dis=rem.distance;
            rooms[x][y]=dis;           

            for(int k=0;k<4;k++){

                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx<0 || ny<0 || nx>=rooms.size() || ny>=rooms[0].size()){
                        continue;
                    }

                    if(rooms[nx][ny]!=-1 &&visited[nx][ny]==0){
                        que.push(Item(nx,ny,dis+1));
                        visited[nx][ny]=1;
                    }
                
            }
        }

        


    }
};

int main(){
    return 0;
}
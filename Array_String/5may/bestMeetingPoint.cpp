// https://leetcode.com/problems/best-meeting-point/
// https://www.lintcode.com/problem/best-meeting-point/
// Best Meeting Point
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: the minimize travel distance
     */
    int minTotalDistance(vector<vector<int>> &grid) {
        vector<int> row;
        vector<int> col;
        int mains;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
            
        }
        int x,y;
        sort(row.begin(),row.end());
        sort(col.begin(),col.end());
        if(row.size()%2==0){

            x=row[row.size()/2];
            y=col[col.size()/2];
            int ans=0;
            int ans2=0;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]==1){
                       ans+=abs(i-x)+abs(j-y);
                    }
                }
            
             }
            x=row[row.size()/2-1];
            y=col[col.size()/2-1];
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]==1){
                       ans2+=abs(i-x)+abs(j-y);
                    }
                }
            
             }

            mains=min(ans,ans2);
        }else{
            x=row[row.size()/2];
            y=col[col.size()/2];
            int ans=0;
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]==1){
                       ans+=abs(i-x)+abs(j-y);
                    }
                }
            
             }
             mains=ans;

        }
        return mains;
    }
};
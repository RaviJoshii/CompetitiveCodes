// https://www.lintcode.com/en/old/problem/number-of-islands-ii/#
// Number of Islands II

#include<bits/stdc++.h>
using namespace std;


//   Definition for a point.
  struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    void makeset(vector<int> &parent,vector<int> &rank){
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
        for(int i=0;i<rank.size();i++){
            rank[i]=1;
        }
    }
    int find(int v,vector<int> &parent){
        if(parent[v]==v){
            return v;
        }
        int pv=find(parent[v],parent);
        parent[v]=pv;
        return pv;
    }

    void Union(int x,int y,vector<int> &parent, vector<int> &rank){
        int lx=find(x,parent);// leader of x= lx
        int ly=find(y,parent);

        if(lx==ly){
            return;
        }

        if(rank[lx]>rank[ly]){
            parent[ly]=lx;
        }else if(rank[lx]<rank[ly]){
            parent[lx]=ly;
        }else{
            parent[lx]=ly;
            rank[ly]++;
        }
    }
    int getIndex(int x,int y,int n,int m){
        int idx=x*m+y;
        return idx;
    }
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        vector<vector<int >> matrix(n,vector<int>(m,0));
        vector<int> parent(n*m);
        vector<int> rank(n*m);
        makeset(parent,rank);
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        int island=0;
        vector<int> ans;
        
        for(int i=0;i<operators.size();i++){
            int x=operators[i].x;
            int y=operators[i].y;
            if(matrix[x][y]==1){
                ans.push_back(island);
                continue;
                //already an island
            }
            int idx=getIndex(x,y,n,m);
            matrix[x][y]=1;
            island++;
            for(int i=0;i<4;i++){
                int r=x+dx[i];
                int c=y+dy[i];
                if(r<0 || c<0 || r>=n || c>=m){
                        continue;
                }
                if(matrix[r][c]==1){
                    int tempIndx=getIndex(r,c,n,m);
                    int templeader=find(tempIndx,parent);
                    int mainLeader=find(idx,parent);
                    if(templeader!=mainLeader){
                        island--;
                        Union(idx,tempIndx,parent,rank);
                    }

                }
            }
            ans.push_back(island);

        }
        return ans;
    }
};
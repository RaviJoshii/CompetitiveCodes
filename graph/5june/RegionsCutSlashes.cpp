// https://leetcode.com/problems/regions-cut-by-slashes/
// Regions Cut By Slashes
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
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

    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<int> parent((n+1)*(n+1));
        vector<int> rank((n+1)*(n+1));
        makeset(parent,rank);
        for(int i=0;i<=grid.size();i++){
            int idx=getIndex(0,i,n,n);
            Union(idx,0,parent,rank);
            idx=getIndex(grid.size(),i,n,n);
            Union(idx,0,parent,rank);

            idx=getIndex(i,0,n,n);
            Union(idx,0,parent,rank);
            idx=getIndex(i,grid.size(),n,n);
            Union(idx,0,parent,rank);
        }
        int ans=1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].length();j++){
                if(grid[i][j]==' '){
                    continue;
                }
                if(grid[i][j]=='/'){
                    int idx1=getIndex(i+1,j,n,n);
                    int idx2=getIndex(i,j+1,n,n);
                    int l1=find(idx1,parent);
                    int l2=find(idx2,parent);
                    if(l1==l2){
                        ans++;
                    }else{
                        Union(l1,l2,parent,rank);
                    }

                }else if(grid[i][j]=='\\'){
                    int idx1=getIndex(i,j,n,n);
                    int idx2=getIndex(i+1,j+1,n,n);
                    int l1=find(idx1,parent);
                    int l2=find(idx2,parent);
                    if(l1==l2){
                        ans++;
                    }else{
                        Union(l1,l2,parent,rank);
                    }

                }
            }
        }
        return ans;
        
    }
};
int main(){
    vector<string> grid={" /","/ "};
    Solution s;
    cout<<s.regionsBySlashes(grid)<<endl;
    return 0;

}
// https://leetcode.com/problems/redundant-connection/
// Redundant Connection
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int> parent;
    vector<int> rank;
    int sets=0;
    void makeset(int totalV){
        parent.resize(totalV);
        rank.resize(totalV);

        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
        for(int i=0;i<rank.size();i++){
            rank[i]=1;
        }
        sets=totalV;
    }
    int find(int v){
        if(parent[v]==v){
            return v;
        }
        int pv=find(parent[v]);
        parent[v]=pv;
        return pv;
    }

    void Union(int x,int y){
        int lx=find(x);// leader of x= lx
        int ly=find(y);

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
        sets--;
    }

    int CountSets(){
        return sets;
    }

};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds;
        int n=edges.size()+1;
        ds.makeset(n+1);
        vector<int> ans(2);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int lu=ds.find(u);
            int lv=ds.find(v);
            if(lu==lv){
                ans[0]=u;
                ans[1]=v;
            }else{
               ds.Union(u,v); 
            }

        }
        // cout<<ans[0]<<" - "<<ans[1]<<endl;
        return ans;
    }

};
int main(){
    vector<vector<int>> vec={{1,2}, {2,3}, {3,4}, {1,4}, {1,5}};
    Solution s;
    s.findRedundantConnection(vec);
    return 0;

}
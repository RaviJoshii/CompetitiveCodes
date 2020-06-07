// https://practice.geeksforgeeks.org/problems/topological-sort/1
// Topological sort
#include<bits/stdc++.h>
using namespace std;
void Dfs(vector<int> adj[],vector<int> &vis,list<int>  &lis,int src){
    vis[src]=1;
    for(auto e: adj[src]){
        if(vis[e]==0){
            Dfs(adj,vis,lis,e);
        }
    }
    lis.push_front(src);
    
}

int* topoSort(int V, vector<int> adj[]) {
    vector<int> vis(V,0);
    list<int> lis;
    for(int i=0;i<vis.size();i++){
        if(vis[i]==0){
            Dfs(adj,vis,lis,i);
        }
    }
    int *ans=new int[V];

    int i=0;

    for(auto num:lis){
        ans[i++]=num;
    }
    return ans;
    
}
int main(){
    int n,e;
    cin>>n>>e;
    int u,v;
    vector<int> adj[n];
    for(int i=0;i<e;i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int *res=topoSort(n,adj);

    return 0;

}
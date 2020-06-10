// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
// Strongly Connected Components (Kosaraju's Algo)
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],vector<int> &vis,stack<int> &stk,int src){
    vis[src]=1;
    for(auto num: adj[src]){
        if(vis[num]==0){
            dfs(adj,vis,stk,num);
        }
    }

    stk.push(src);
}
void dfs2(vector<vector<int>>  &graph,vector<int> &vis,int src){
    vis[src]=1;
    for(auto num: graph[src]){
        if(vis[num]==0){
            dfs2(graph,vis,num);
        }
    }

    
}
int kosaraju(int V, vector<int> adj[])
{
    stack<int> stk;
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
        if(vis[i]==0){
            dfs(adj,vis,stk,i);
        }
    }
    //reversing the edge;
    vector<vector<int>> graph(V);
    for(int i=0;i<V;i++){
        for(auto num: adj[i]){
            graph[num].push_back(i);
        }
    }
    
    //applying dfs
    for(int i=0;i<vis.size();i++){
        vis[i]=0;
    }
    int ans=0;
    while(stk.size()>0){
        int rem=stk.top();
        stk.pop();
        if(vis[rem]==0){
            dfs2(graph,vis,rem);
            ans++;
        }
        
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
    cout<<kosaraju(n,adj);
    return 0;

}
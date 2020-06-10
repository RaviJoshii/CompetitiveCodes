// https://practice.geeksforgeeks.org/problems/mother-vertex/1
// Mother Vertex
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> g[], int src,vector<int> &vis,stack<int> &stk){
    vis[src]=1;
    for(auto num: g[src]){
        if(vis[num]==0){
            dfs(g,num,vis,stk);
        }
    }
    stk.push(src);
}

void dfsCheck(vector<int> g[], int src,vector<int> &vis){
    vis[src]=1;
    for(auto num: g[src]){
        if(vis[num]==0){
            dfsCheck(g,num,vis);
        }
    }
}

int findMother(int V, vector<int> g[]) 
{   
    vector<int> vis(V,0);
    stack<int> stk;
    for(int i=0;i<vis.size();i++){
        if(vis[i]==0){
            dfs(g,i,vis,stk);
        }
    }

    if(stk.size()==0){
        return -1;
    }
    int mv=stk.top();
    for(int i=0;i<vis.size();i++){
        vis[i]=0;
    }


    //checking that it is mother vertex or not    
    dfsCheck(g,mv,vis);
    for(int i=0;i<vis.size();i++){
        if(vis[i]==0){
            return -1;
        }
    }
    return mv;

    	
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
    cout<<findMother(n,adj);
    return 0;

}
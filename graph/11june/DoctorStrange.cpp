// https://practice.geeksforgeeks.org/problems/doctor-strange/0
// Doctor Strange
#include<bits/stdc++.h>
using namespace std;
void dfs(int &actualSource,int &children , int &timev,int u,vector<int> &dis,vector<int> &low,
        vector<bool> &visited, vector<vector<int>> &graph,vector<int> &ap,int parent){
    
    
    visited[u]=true;

    // cout<<u<<endl;
    for(auto v:graph[u]){
        if(v==parent){
            continue;
        }
        if(visited[v]==true){
            
            low[u]=min(low[u],dis[v]);
        }else{

            if(u==actualSource){
                children++;
            }
            low[v]=dis[v]=timev++;

            dfs(actualSource,children,timev,v,dis,low,visited,graph,ap,u);
            low[u]=min(low[u],low[v]);
            if(dis[u]<=low[v] && u!=actualSource){
                // ap++;
                ap[u]=1;
            }
        }
    }
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> graph(n+1);
        int p,q;
        for(int i=0;i<m;i++){
            cin>>p>>q;
            graph[p].push_back(q);
            graph[q].push_back(p);

        }
        vector<int> dis(graph.size());
        vector<int> low(graph.size());
        for(int i=0;i<low.size();i++){
            low[i]=i;
        }
        vector<bool> visited(graph.size(),false);

        //use of helper function if the graph is diconnected
        vector<int> ap(visited.size(),0);

        for(int i=1;i<visited.size();i++){
            int children =0;
            int timev=0;
            
            int actualSource=i;
            if(visited[i]==false){
                dis[i]=low[i]=timev++;
                dfs(actualSource,children,timev,i,dis,low,visited,graph,ap,-1);
            }
            if(children >=2){
                ap[actualSource]=1;
            }
        }
        
        int ans=0;

        ///articulation point is 
        for(int i=0;i<ap.size();i++){
            if(ap[i]==1){
                ans++;
            }
        }
        // cout<<ap<<endl;
        cout<<ans<<endl;
    }
    return 0;
}


//corner case
/*
1
7 6
1 2
2 3
2 4
2 5
3 6
3 7
*/
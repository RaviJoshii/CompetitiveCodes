// https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
// Kahn’s algorithm for Topological Sorting

#include<bits/stdc++.h>
using namespace std;
int* topoSort(int V, vector<int> adj[]) {
    vector<int> vis(V,0);
    vector<int> indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto e:adj[i]){
            indegree[e]++;
        }
    }
    int *ans=new int[V];
    int idx=0;

    queue<int> que;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            que.push(i);
        }
    }  

    while(que.size()>0){
        int rem=que.front();
        que.pop();
        if(vis[rem]==0){
            ans[idx++]=rem;
        }
        vis[rem]=1;

        //pushing its child if their indegree is 0;
        for(auto e:adj[rem]){
            if(vis[e]==0){
                indegree[e]--;
                if(indegree[e]==0){
                    que.push(e);
                }
            }
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
    int *res=topoSort(n,adj);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }

    return 0;

}
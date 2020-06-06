// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// BFS of graph
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_comp_bipartile(vector<vector<int>>& graph,int src,vector<int> &vis){
        if(graph.size()==0){
            return true;
        }
        // vector<int> vis(graph.size(),-1);
        queue<pair<int,int>> que;
        que.push(make_pair(src,0)); //first= data, second= level
        while(que.size()>0){
            pair<int,int> rem=que.front();
            que.pop();
            if(vis[rem.first]!=-1){
                int ol=vis[rem.first];
                int nl=rem.second;
                if(ol!=nl){
                    return false;
                }
                continue;
            }
                
            
            vis[rem.first]=rem.second;
            for(int i=0;i<graph[rem.first].size();i++){
                if(vis[graph[rem.first][i]]==-1){
                    pair<int,int> temp;
                    temp.first=graph[rem.first][i];
                    temp.second=(vis[rem.first]+1)%2;
                    que.push(temp);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size()==0){
            return true;
        }
        vector<int> vis(graph.size(),-1);
        for(int i=0;i<vis.size();i++){
            if(vis[i]==-1){
            bool res=   is_comp_bipartile(graph,i,vis);
                if(res==false){
                    return false;
                }
            }
        }
        return true;
    }
};
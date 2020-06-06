// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// DFS of Graph
#include<bits/stdc++.h>
using namespace std;
void process(int src,vector<int> graph[],vector<int> &vis,vector<int> &ans){
    vis[src] = 1;
    ans.push_back(src);
    for (int e : graph[src])
        {
            if (vis[e]==-1)
            {
                process(e, graph,vis,ans);
            }
        }
}

vector <int> dfs(vector<int> g[], int N)
{   vector<int> vis(N,-1);
    // vis.resize(N,-1);
    vector<int> ans;
    process(0,g,vis,ans);
    return ans;

}
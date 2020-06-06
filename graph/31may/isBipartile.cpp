// https://leetcode.com/problems/is-graph-bipartite/
//  Is Graph Bipartite?
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size()==0){
            return true;
        }
        vector<int> vis(graph.size(),-1);
        queue<pair<int,int>> que;
        que.push(make_pair(0,0)); //first= data, second= level
        while(que.size()>0){
            pair<int,int> rem=que.front();
            que.pop();
            if(vis[rem.first]==1){
                int ol=vis[rem.first];
                int nl=rem.second;
                if(ol%2!=nl%2){
                    return false;
                }
            }
            vis[rem.first]=rem.second;
            for(int i=0;i<graph[rem.first].size();i++){
                pair<int,int> temp;
                temp.first=graph[rem.first][i];
                temp.second=vis[rem.first]+1;
                que.push(temp);
            }
        }
        return true;
        
    }
};
// https://leetcode.com/problems/is-graph-bipartite/
// Is Graph Bipartite

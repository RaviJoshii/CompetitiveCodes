// https://github.com/azl397985856/leetcode/blob/master/problems/1168.optimize-water-distribution-in-a-village-en.md
// https://discuss.codechef.com/t/how-to-solve-this-google-interview-graph-question/35981
// https://leetcode.com/problems/optimize-water-distribution-in-a-village/
// Optimize Water Distribution in a Village


#include<bits/stdc++.h>
using namespace std;

/* Question
There are n houses in a village. We want to supply water for all the houses by
building wells and laying pipes.

For each house i, we can either build a well inside it directly with cost wells[i],
or pipe in water from another well to it. The costs to lay pipes between houses are 
given by the array pipes, where each pipes[i] = [house1, house2, cost] represents the 
cost to connect house1 and house2 together using a pipe. Connections are bidirectional.

Find the minimum total cost to supply water to all houses.

Example 1:

Input: n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]
Output: 3
Explanation: 
The image shows the costs of connecting houses using pipes.
The best strategy is to build a well in the first house with cost 1 and connect the other
houses to it with cost 2 so the total cost is 3.

Constraints:
1 <= n <= 10000
wells.length == n
0 <= wells[i] <= 10^5
1 <= pipes.length <= 10000
1 <= pipes[i][0], pipes[i][1] <= n
0 <= pipes[i][2] <= 10^5
pipes[i][0] != pipes[i][1]


Solution : Hint
The graph we need is as follows: take all edges already provided by the problem.
Then create a new vertex, say “-1” and connect it to each home with the cost of building 
a well in that home.
Then calculate the minimum spanning tree, the cost of that will be the answer.
*/

class items{
    public:
    int node ;
    int cost;
    items(int n,int c){
        this->node=n;
        this->cost=c;
    }
    bool operator>(const items &i1)const{
        return this->cost > i1.cost;
    }
};

class Solution{
    public:
    int minCostToSupplyWater(int n,vector<int> &wells,vector<vector<int>> &pipes){
        priority_queue< items, vector<items> , greater<items>> pq;

        //adding all edges of virtual edges;
        for(int i=0;i<wells.size();i++){
            pq.push(items(i+1,wells[i]));
        }
        // cout<<pq.size();

        //implement graph
        vector<vector<pair<int,int>> > graph(n+1);
        // int src=-1;
        for(int i=0;i<pipes.size();i++){
            int u=pipes[i][0];
            int v=pipes[i][1];
            int wt=pipes[i][2];
            graph[u].push_back(make_pair(v,wt));
            graph[v].push_back(make_pair(u,wt));            
        }
        vector<bool> vis(n+1,false);
        int ans=0;
        
        while(pq.size()>0){
            
            items rem=pq.top();
            pq.pop();
            if(vis[rem.node]==true){
                continue;
            }
            vis[rem.node]=true;
            ans+=rem.cost;
            for(auto e:graph[rem.node]){
                if(vis[e.first]==false){
                    pq.push(items(e.first,e.second));
                }

            }

        }
        return ans;        
    }
};

int main(){
    int n = 5;
    vector<int> wells={1,2,2,3,2};
    vector<vector<int>> pipes={{1,2,1},{2,3,1},{4,5,7}};
    Solution s;
    cout<<s.minCostToSupplyWater(n,wells,pipes);
    return 0;
}


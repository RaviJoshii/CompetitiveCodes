// https://www.interviewbit.com/problems/minimum-cost-to-connect-cities/
// https://www.geeksforgeeks.org/minimum-cost-connect-cities/
// Minimum cost to connect cities

#include<bits/stdc++.h>
using namespace std;
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

int solve(int A, vector<vector<int> > &B) {
    vector<vector<pair<int,int>> > graph(A+1);
    int src=-1;
    for(int i=0;i<B.size();i++){
        int u=B[i][0];
        int v=B[i][1];
        int wt=B[i][2];
        graph[u].push_back(make_pair(v,wt));
        graph[v].push_back(make_pair(u,wt));
        if(src==-1){
            src=u;
        }
    }
    int ans=0;
    priority_queue< items, vector<items> , greater<items>> pq;
    pq.push(items(src,0));
    vector<bool> vis(A+1,false);
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
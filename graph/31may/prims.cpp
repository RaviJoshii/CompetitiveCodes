// https://www.spoj.com/problems/MST/
// MST - Minimum Spanning Tree
#include<bits/stdc++.h>
using namespace std;

class items{
    public:
    int node;
    int cost;
    items(int n,int c){
        this->node=n;
        this->cost=c;
    }
    bool operator>(const items &i1)const{
        return this->cost > i1.cost;
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    int src=-1;
    vector<vector<pair<int,int>> > graph(n+1);
    
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(src==-1){
            src=u;
        }
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }

    int ans=0;
    priority_queue< items, vector<items> , greater<items>> pq;
    pq.push(items(src,0));
    vector<bool> vis(n+1,false);
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
    cout<<ans<<endl;

    return 0;
}
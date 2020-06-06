// https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0
// Shortest path from 1 to n

// https://www.spoj.com/problems/MST/
// MST - Minimum Spanning Tree
#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int nbr;
    int wt;
    Edge(int nbr,int wt){
        this->nbr=nbr;
        this->wt=wt;
    }
    Edge(){

    }
};
class items{
    public:
    int cost;
    int currNode;
    int parentNode;
    items(int currn, int cost,int pare){
        this->currNode=currn;
        this->cost=cost;
        this->parentNode=pare;
    }
    bool operator>(const items &i1) const{
        return this->cost>i1.cost;
    }

};
void addEdge(vector<vector<Edge>> &graph,int u,int v,int wt){
    graph[u].push_back(Edge(v,wt));
}
void display(vector<vector<Edge>> &graph)
{
    for(int v = 0; v < graph.size(); v++)
    {
        cout << v << " -> ";
        for(int n = 0; n < graph[v].size(); n++)
        {
            Edge ne = graph[v][n];
            cout << "[" << ne.nbr << "-" << ne.wt << "], ";
        }
        cout << "." << endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int src=1;
        vector<vector<Edge>> graph(n+1);
        // for(int i=2;i<=n;i++){
        //      addEdge(graph,i-1,i,1);// weight =1;
        // }
        // for(int i=3;i<=n;i=i*3){
        //     addEdge(graph,i/3,i,1);
        // }
        for(int i=1;i<=n;i++){
            int j=i+1;
            if(j<=n){
                addEdge(graph,i,j,1);// weight =1;
            }
            j=3*i;
            if(j<=n){
                addEdge(graph,i,j,1);// weight =1;
            }            
        }
        // display(graph);
        // continue;
        priority_queue<items,vector<items>, greater<items>> pq;
        vector<int> ans(n+1,-1);
        pq.push(items(src,0,-1));

        while(pq.size()>0){
            items rem= pq.top();
            pq.pop();
            if(ans[rem.currNode]!=-1){
                continue;
            }
            if(rem.parentNode!=-1){
                ans[rem.currNode]=rem.cost;
            }else{
                //source node
                ans[rem.currNode]=0;
            }
            

            for(Edge e:graph[rem.currNode]){
                if(ans[e.nbr]==-1){
                    pq.push(items(e.nbr,e.wt+rem.cost,rem.currNode));
                }
            }

        }
     cout<<ans[n]<<endl;  
    }

}
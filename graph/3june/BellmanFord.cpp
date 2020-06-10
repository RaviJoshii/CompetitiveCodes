// https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/
// Bellman–Ford Algorithm | DP-23
#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int nbr,wt;
    Edge(int n,int w){
        this->nbr=n;
        this->wt=w;
    }

};
bool bellmanford(vector<vector< Edge> >  &graph,int V){
    vector<int> arr(V,INT_MAX);
    int src=0;
    arr[src]=0;
    for(int i=1;i<=V-1;i++){

        for(int j=0;j<V;j++){
            for(auto e:graph[j]){
                int u=j;
                int v=e.nbr;
                int wt=e.wt;

                ////relaxation
                if(arr[u]+wt<arr[v]){
                    arr[v]=arr[u]+wt;
                }

            }
        }


    }

    for(int j=0;j<V;j++){
            for(auto e:graph[j]){
                int u=j;
                int v=e.nbr;
                int wt=e.wt;

                ////relaxation
                if(arr[u]+wt<arr[v]){
                    arr[v]=arr[u]+wt;
                    return true;
                }

            }
        }

    return false;


}

int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        vector<vector< Edge> >  graph(v);
        int x,y,z;
        for(int i=0;i<e;i++){
            cin>>x>>y>>z;
            graph[x].push_back(Edge(y,z));
        }
        bool res= bellmanford(graph,v);
        cout<<res<<endl;




    }
}
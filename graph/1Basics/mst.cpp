#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Edge{
    public:
    int nbr,wt;
    Edge(int nbr,int wt){
        this->nbr=nbr;
        this->wt=wt;
    } 
};
void addEdge(int u, int v,int wt,vector<vector<Edge>> &graph){
Edge e(v,wt);
graph[u].push_back(e);
Edge e1(u,wt);
graph[v].push_back(e1);

}
void display(vector<vector<Edge>> g){
    for(int i=0;i<g.size();i++){
        cout<<i<<"-- ";
        for(int j=0;j<g[i].size();j++){
            cout<<" ["<<g[i][j].nbr<<"/"<<g[i][j].wt<<"], ";
        }
        cout<<endl;
    }
}

void constructgraph(vector<vector<Edge>> &graph){
    
    int vertex=7;
    for(int i=0;i<vertex;i++){
        graph.push_back(vector<Edge>());
    }
    addEdge(0,1,10,graph);
    addEdge(1,2,10,graph);
    addEdge(0,3,40,graph);
    addEdge(2,3,10,graph);
    addEdge(3,4,2,graph);
    addEdge(4,5,3,graph);
    addEdge(5,6,3,graph);
    addEdge(4,6,8,graph);

}
class Ppair{
public:
    int v;
    int av;
    int cost;
    Ppair(int v,int av,int cost){
        this->v=v;
        this->av=av;
        this->cost=cost;

    }
};
class mycomparator{
    public:
    int operator()(const Ppair &p1,const Ppair &p2){
            return p1.cost>p2.cost;
    }
};
void prims(int src,vector<vector<Edge>> &graph){
    
    vector<vector<Edge>> mst(graph.size(),vector<Edge>());

    vector<bool> visited(graph.size(),false); 
    priority_queue<Ppair,vector<Ppair>,mycomparator> pq;

    pq.push(Ppair(src,-1,0));
    while(pq.size()>0){
        Ppair p=pq.top();
        pq.pop();
        if(visited[p.v]==true){
            continue;
        }
        visited[p.v]=true;
        if(p.av!=-1){
            addEdge(p.v,p.av,p.cost,mst);
        }
        
        int sizes=graph[p.v].size();

        for(int k=0;k<sizes;k++){
            Edge ne=graph[p.v][k];
            if(visited[ne.nbr]==false){
                pq.push(Ppair(ne.nbr,p.v,ne.wt));
            }
        }
    }
    
    display(mst);

} 
class Kpair{
    public:
    int u;
    int v;
    int wt;
    Kpair(int u,int v,int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
    bool operator>(const Kpair &other) const{
        return (this->wt)>(other.wt);
    }
};

int finds(vector<int> &pa,int v){
    while(pa[v]!=v){
        v=pa[v];
    }
    return v;
}
void merge(vector<int> &pa,vector<int> &ra,int vsl,int usl){
    if(ra[vsl]<ra[usl]){
        pa[vsl]=usl;
    }
    else if(ra[vsl]>ra[usl]){
        pa[usl]=vsl;
    }
    else{
        pa[usl]=vsl;
        ra[vsl]++;
    }

}
void kruskal(vector< vector<Edge>> &graph){
    vector<bool> visited(graph.size(),false);
    vector<int> pa(graph.size());
    vector<int> ra(graph.size(),1);
    
    vector<vector<Edge>> mst(graph.size(),vector<Edge>());

    for(int i = 0; i < pa.size(); i++){
        pa[i] = i;
    }
    priority_queue<Kpair,vector<Kpair>,greater<Kpair>> pq;
    for(int v=0;v<graph.size();v++){
        for(int x=0;x<graph[v].size();x++){
            Edge ne=graph[v][x];
            if(v<ne.nbr){
                pq.push(Kpair(v,ne.nbr,ne.wt));
            }
        }
    }
    while(pq.size()>0){
        Kpair ke=pq.top(); pq.pop();
        int v=ke.v;
        int u=ke.u;
        int vsl=finds(pa,v);
        int usl=finds(pa,u);
        if(vsl!=usl){
            addEdge(v,u,ke.wt,mst);
            merge(pa,ra,vsl,usl);
        }
    }

    display(mst);

}

int main(){
    vector<vector<Edge>> graph;
    constructgraph(graph);
    //prims(0,graph);
    kruskal(graph);
    //display(graph);

    return 0;
}
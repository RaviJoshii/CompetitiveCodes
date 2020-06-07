#include<bits/stdc++.h>
using namespace std;


///////////  B  F  S  ///////////////////////////
//In this we  have find the no. of cycle and levels in graph according to bfs
void bfs(int src,vector<vector<int>> &graph)
{
    queue<int> que;
    vector<bool> vis(graph.size(), false);

    que.push(src);
    que.push(-1);
    int cycle = 0, level = 0;
    int dest = 6;
    bool isDest = false;

    while (que.size() != 1)
    {
        int rvtx = que.front();
        que.pop();

        if (rvtx == -1)
        {
            level++;
            que.push(-1);
            continue;
        }

        if (vis[rvtx])
        {
            cout << "cycle: " << ++cycle << " @ " << rvtx << endl;
            continue;
        }

        vis[rvtx] = true;
        for (auto e : graph[rvtx])
            if (!vis[e])
                que.push(e);
    }
}


///////////  D  F  S  ///////////////////////////


bool dfs(int vertex, set<int>&visited, int parent,vector<vector<int>> &graph) {
   visited.insert(vertex);
   for(int vert: graph[vertex]) {
      if(vert) {
         if(vert == parent)    //if v is the parent not move that direction
            continue;
         if(visited.find(vert) != visited.end())    //if v is already visited
            return true;
         if(dfs(vert, visited, vertex,graph))
            return true;
      }
   }
   return false;
}

bool DfshasCycle(vector<vector<int>> &graph) {
   set<int> visited;       //visited set  /can used boolean vector
   for(int v = 0; v<graph.size(); v++) {
      if(visited.find(v) != visited.end())    //when visited holds v, jump to next iteration
         continue;
      if(dfs(v, visited, -1,graph)) {    //-1 as no parent of starting vertex
         return true;
      }
   }
   return false;
}
void BfsDfsSolve(){

    vector<vector<int>> graph={{1,3},{0,2},{1,3},{0,2}};
    cout<<DfshasCycle(graph);
    int src=0;
    bfs(src,graph);

}

///////////// DISJOINT SET //////////////////////////
class DisjointSet{
    public:
    vector<int> parent;
    vector<int> rank;
    void makeset(int totalV){
        parent.resize(totalV);
        rank.resize(totalV);

        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
        for(int i=0;i<rank.size();i++){
            rank[i]=1;
        }
    }
    int find(int v){
        if(parent[v]==v){
            return v;
        }
        int pv=find(parent[v]);
        parent[v]=pv;
        return pv;
    }

    void Union(int x,int y){
        int lx=find(x);// leader of x= lx
        int ly=find(y);

        if(lx==ly){
            return;
        }

        if(rank[lx]>rank[ly]){
            parent[ly]=lx;
        }else if(rank[lx]<rank[ly]){
            parent[lx]=ly;
        }else{
            parent[lx]=ly;
            rank[ly]++;
        }
    }

};

bool findCycle(vector<vector<int>>  &graph, int n)
{
	DisjointSet ds;
	ds.makeset(n);

	for (int x = 0; x < n; x++)
	{
		for (int y : graph[x])
		{
			int leader1 = ds.find(x);
			int leader2 = ds.find(y);
            // cout<<x<<","<<y<<"    - "<<leader1<<"-"<<leader2<<endl;
			if (leader1 == leader2)
            {   
				return true;
            }
			else{
                ds.Union(leader1, leader2);
            }
            
		}
	}
	return false;
}
void DSUsolve(){

    vector<vector<int>> graph={{1},{},{0,1}};
    cout<<findCycle(graph,3);

}



















///////////////////////////////////////     Undirected   //////////////////////////////


bool iscyclicUtilDFS(vector<vector<int>> &graph,int src,vector<int> &vis){
    vis[src]=-1;
    for(auto e:graph[src]){
        if(vis[e]==-1){
            return true;
        }
        if(vis[e]==0){
            bool res=iscyclicUtilDFS(graph,e,vis);
            if(res==true){
                return true;
            }
        }
        
    }
    vis[src]=1;
    return false;
}

bool dsfIsCyclic(vector<vector<int>> &graph){
    int v=graph.size();
    vector<int> vis(v,0);
    for(int i=0;i<vis.size();i++){
        if(vis[i]==0){
            bool res=iscyclicUtilDFS(graph,i,vis);
            if(res==true){
                return true;
            }
        }
    }
    return false;

}


/////////////////toplogical sort/////////

bool topoSort(int V, vector<int> adj[])
{ int visited=0;
 int indegree[V] = {0};
 for(int i =0;i<V;i++)
 {
     for(int j =0;j<adj[i].size();j++)
     {
         indegree[adj[i][j]]++;
     }
 }

 queue<int> q;
 for(int i =0;i<V;i++)
 {
     if(indegree[i]==0)
     q.push(i);
 }
 while(!q.empty())
 {
     int u =q.front();
     q.pop();
     
     visited++;
     for(int j =0; j <adj[u].size();j++)
     {
         indegree[adj[u][j]]--;
         if(indegree[adj[u][j]]==0)
         q.push(adj[u][j]);
     }
 }
if(visited<V)
return true;
else
return false;
}

bool isCyclictopo(int V, vector<int> adj[])
{
    return topoSort(V,adj);
}







int main(){

    //undirected
    // BfsDfsSolve();
    // DSUsolve();


    // directed

    // cout<<isCyclictopo();
    // cout<<dsfIsCyclic(graph)
    

    return 0;
}


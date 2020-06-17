// https://practice.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1
// Euler Circuit in a Directed Graph
#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,e;
        cin>>n>>e;
        vector<vector<int>> graph(n,vector<int>(n));
        vector<int> Indegree(n,0);
        vector<int> Outdegree(n,0);
        int x,y;
        for(int i=0;i<e;i++){
            cin>>x>>y;
            graph[x].push_back(y);
            
        }

        //implement degree array
        
        
        int countsOdd=0;
        for(int u=0;u<graph.size();u++){
            for(int v:graph[u]){
                Indegree[v]++;
                Outdegree[u]++;
                
            }
        }
        int c=0;
        for(int i=0;i<Indegree.size();i++){
            if(Indegree[i]!=Outdegree[i]){
                c++;
                break;
            }
        }
        if(c>0){
            cout<<0<<endl;
        }else{
            cout<<1<<endl;
        }


    }
    return 0;
}


////////////////////////////////////////////
// gfg  solution function


// bool isEulerianCycle()
// {
//     vector<int> Indegree(V,0);
//     vector<int> Outdegree(V,0);
//     for(int i=0;i<V;i++){
//         for(auto num: adj[i]){
//             Indegree[num]++;
//             Outdegree[i]++;
//         }
//     }
//     int c=0;
//     for(int i=0;i<Indegree.size();i++){
//         if(Indegree[i]!=Outdegree[i]){
//             return false;
//         }
//     }
//     return true;
// }
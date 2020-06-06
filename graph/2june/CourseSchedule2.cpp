// https://leetcode.com/problems/course-schedule-ii/
// Course Schedule II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    void DfsTs(vector<vector<int>> &graph,vector<bool> &vis,list<int> &ans,int src){
        vis[src]=true;
        for(int num: graph[src]){
            if(vis[num]==false){
                DfsTs(graph,vis,ans,num);
            }
        }
        ans.push_front(src);        
    }
    void display(vector<vector<int>> &graph)
    {
        for(int v = 0; v < graph.size(); v++)
        {
            cout << v << " -> ";
            for(int n = 0; n < graph[v].size(); n++)
            {
                cout << "[" << graph[v][n]<< "], ";
            }
            cout << "." << endl;
        }
    }
    bool isCyclic(vector<vector<int>> &graph,vector<bool> &vis,int src){
        queue<int> que;
        que.push(src);
        while(que.size()>0){
            int rem=que.front();
            que.pop();
            if(vis[rem]==1){
               return true;
            }else{
                vis[rem]=true;
            }

            for(int e:graph[rem]){
                if(vis[e]==-1){
                    vis[e]
                    que.push(e);
                }
            }
        }
        return false;
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool> vis(numCourses,false);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // display(graph);
        list<int> ans;
        vector<int> ts;

        //finding cycle
        for(int i=0;i<vis.size();i++){
            if(vis[i]==false){
                if(isCyclic(graph,vis,i)==true){
                    // cout<<endl<<"c"<<endl;
                    return ts;
                }
                
            }
        }
        
        
        for(int i=0;i<vis.size();i++){
            vis[i]=false;
        }

        /////////////

        for(int i=0;i<numCourses;i++){
            if(vis[i]==false){
                DfsTs(graph,vis,ans,i);
                // ans.push_front(i);
            }
        }
         //finding cycle
         // if(flag){
         //     return ts;
         // }
        /////////////
        
        
        for(int num:ans){
            cout<<num<<" ";
            ts.push_back(num);
        }
        return ts;
        
    }

};
int main(){
    int n=2;
    vector<vector<int>> vec={{0,1}};
    Solution s;
    s.findOrder(n,vec);
    return 0;
}
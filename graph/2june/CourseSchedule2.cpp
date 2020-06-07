// https://leetcode.com/problems/course-schedule-ii/
// Course Schedule II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool flag=false;
    void DfsTs(vector<vector<int>> &graph,vector<int> &vis,list<int> &ans,int src){


        vis[src]=-1;
        for(int num: graph[src]){
            if(vis[num]==-1){
                //cycle detect;
                flag=true;
                return;
            }
            if(vis[num]==0){
                DfsTs(graph,vis,ans,num);
            }
        }

        ans.push_front(src); 
        vis[src]=1;      
    }
   
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> vis(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // display(graph);
        list<int> ans;
        vector<int> ts;

        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                DfsTs(graph,vis,ans,i);
                if(flag){
                    return ts;
                }
                // ans.push_front(i);
            }
        }
        
        for(int num:ans){
            ts.push_back(num);
        }
        return ts;
        
    }

};
int main(){
    int n=2;
    vector<vector<int>> vec={{1,0},{0,1}};
    Solution s;
    s.findOrder(n,vec);
    return 0;
}
// https://leetcode.com/problems/evaluate-division/
// Evaluate Division
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> umap;
        for(int i=0;i<26;i++){
            char c=i+'a';
            string str=c+"";
            umap[str]=i;
        }
        //implementing graph
        vector<vector<pair<int, double> >> graph;
        for(int i=0;i<equations.size();i++){
            graph[umap[equations[i][0]]].push_back(make_pair(umap[equations[i][1]],values[i]));
            graph[umap[equations[i][1]]].push_back(make_pair(umap[equations[i][0]],values[i]));
        }
        for(int i=0;i<queries.size();i++){
            double ans=-1.0;
            string num=queries[i][0];
            string deno=queries[i][1];
            vector<bool> vis(26,false);
            queue<pair<int,double>> que;
            que.push(make_pair(umap[num],1));
            while(que.size()>0){
                auto rem=que.front();
                if(rem.first==umap[deno]){
                    cout<<rem.second<<endl;
                    continue;
                }
                vis[rem.first]=true;
                for(auto e: graph[rem.first]){
                    if(vis[e.first]==false){
                        que.push(make_pair(e.first,rem.second*e.second));
                    }
                }

            }
            cout<<"-1.0"<<endl;

        }
        

        
    }
};
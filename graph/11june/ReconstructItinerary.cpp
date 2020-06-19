// https://leetcode.com/problems/reconstruct-itinerary/
// Reconstruct Itinerary
#include<bits/stdc++.h>
using namespace std;
class mycomp{
    public:
    int operator()(const string &s1, const string &s2){
        return s1>s2;
    }
};
class Solution {
public:
    void dfs(unordered_map<string,vector<string>> &graph,list<string> &ans,string src){
        // cout<<2<<endl;
        vector<string> data=graph[src];
        while(graph[src].size()>0){
            string temp=graph[src].back();
            graph[src].pop_back();
            dfs(graph,ans,temp);
            ans.push_front(temp);//adding in postorder
        }

    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> graph;
        for(int i=0;i<tickets.size();i++){
            graph[tickets[i][0]].push_back(tickets[i][1]);
        }
        for(auto it=graph.begin();it!=graph.end();it++){
            sort(it->second.begin(),it->second.end(),mycomp());
        }
        
        
        
        
        list<string> ans;
        string src="JFK";
        dfs(graph,ans,src);
        ans.push_front(src);
        int i=0;int j=ans.size()-1;

        vector<string> ret;
        for(auto s:ans){
            ret.push_back(s);
        }
        return ret;

    }
};

int main(){
    vector<vector<string>> vec={{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    Solution s;
    s.findItinerary(vec);
    return 0;
}
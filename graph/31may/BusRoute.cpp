// https://leetcode.com/problems/bus-routes/
//  Bus Routes

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if(S==T){
            return 0;
        }
        int counts=0;
        vector<bool> visBusNo(routes.size(),false);
        unordered_map<int,bool> visBusStop;


        unordered_map<int,vector<int>> BusStopToBusNum;


        for(int i=0;i<routes.size();i++){
            for(int j=0;j<routes[i].size();j++){
                BusStopToBusNum[routes[i][j]].push_back(i);
                visBusStop[routes[i][j]]=false;
            }
        }


        
        queue<pair<int,int>> que;//busStop - count        
        que.push(make_pair(S,counts));
        visBusStop[S]==true;

        while(que.size()>0){
            pair<int,int> rem=que.front();
            que.pop();
            if(rem.first==T){
                return rem.second;
            }
            visBusStop[rem.first]=true;
            vector<int> busNO=BusStopToBusNum[rem.first];

            for(int bn:busNO){
                if(visBusNo[bn]==false){
                    visBusNo[bn]=true;

                    for(int i=0;i<routes[bn].size();i++){
                        if(visBusStop[routes[bn][i]]==false){
                            
                            que.push(make_pair(routes[bn][i],rem.second+1));
                        }
                    }  
                   
                }
            }
        }

        return -1;
        
    }
};
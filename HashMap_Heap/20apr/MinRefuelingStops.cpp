// https://leetcode.com/problems/minimum-number-of-refueling-stops/
// Minimum Number of Refueling Stops

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int startF=startFuel;
        int ans=0;
        for(int i=0;i<stations.size();i++){
            
            while(startF<stations[i][0] && pq.size()>0){
                startF+=pq.top();
                ans++;
                pq.pop();
            }
            if(startF<stations[i][0]&&pq.size()==0){
                return -1;
            }
            pq.push(stations[i][1]);
        }
        while(startF<target && pq.size()>0){
                startF+=pq.top();
                pq.pop();
                ans++;
        }
        if(startF<target&&pq.size()==0){
                return -1;
        }
        return ans;
    }
};
int main(){
    int target = 100;
    int startFuel = 10;
    vector<vector<int>> stations = {{10,60},{20,30},{30,30},{60,40}};
    Solution s;
    cout<<s.minRefuelStops(target,startFuel,stations);
}
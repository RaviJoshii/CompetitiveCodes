// https://leetcode.com/problems/grid-illumination/
// Grid Illumination
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,int> rows,cols,d1,d2;
        set<pair<int,int>> lampi;
        for(int i=0;i<lamps.size();i++){
            int r=lamps[i][0];
            int c=lamps[i][1];
            rows[r]++;
            cols[c]++;
            d1[r-c]++;
            d2[r+c]++;
            lampi.insert({r,c});
        }
        vector<int> ans;
        vector<int> dx={-1,-1,0,1,1,1,0,-1};
        vector<int> dy={0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<queries.size();i++){
            int x=queries[i][0];
            int y=queries[i][1];
            
            if(rows[x]>0||rows[y]>0||d1[x-y]>0||d2[x+y]>0){
                ans.push_back(1);
                
                for(int dx=-1;dx<=1;dx++){
                    for(int dy=-1;dy<=1;dy++){
                    int cr=dx+x;
                    int cy=dy+y;
                    if(lampi.find(make_pair(cr,cy))!=lampi.end()){
                        lampi.erase({cr,cy});
                        rows[cr]--;
                        cols[cy]--;
                        d1[cr-cy]--;
                        d2[cr+cy]--;
                    }
                }
            }
        }else{
                ans.push_back(0);
            }
            
        }
        return ans;

    }
};
int main(){

}
// https://leetcode.com/problems/brick-wall/
// Brick Wall
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> umap;
        int lengthWall=wall.size();
        if(lengthWall<1){
        return 0;}
        
        int prefixSum=0;
        for(int i=0;i<lengthWall;i++){
            prefixSum=0;
            for(int j=0;j<wall[i].size()-1;j++){
                prefixSum+=wall[i][j];
                umap[prefixSum]++;
            }
            
        }
        // for(auto it:umap){
        //     cout<<it.first<<" - "<<it.second<<endl;
        // }
        int maxi=0;
        for(auto it:umap){
            if(it.first==0) continue;
            maxi=max(maxi,it.second);
        }
        return lengthWall-maxi;
    }
};
int main(){
    vector<vector<int>> wall={{1,2,2,1},{3,1,2},{1,3,2},{2,4},{3,1,2},{1,3,1,1}};
    Solution s;
    cout<<s.leastBricks(wall);
    return 0;
}
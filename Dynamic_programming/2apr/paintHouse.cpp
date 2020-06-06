// https://www.lintcode.com/problem/paint-house/description
// https://leetcode.com/problems/paint-house/
// Paint House
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        if(costs.size()<1){
            return 0;
        }
        int n=costs.size();
        int r=costs[0][0];int g=costs[0][1];int b=costs[0][2];
        for(int i=1;i<n;i++){
            int rC=costs[i][0]+min(g,b);
            int gC=costs[i][1]+min(r,b);
            int bC=costs[i][2]+min(r,g);
            r=rC;g=gC;b=bC;
        }
        return min(min(r,g),b);
    }
};

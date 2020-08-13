// https://leetcode.com/problems/gas-station/
//  Gas Station
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int gasSum=0;
        int CostSum=0;
        vector<int> diff;
        for(int i=0;i<gas.size();i++){
            gasSum+=gas[i];
            CostSum+=cost[i];
            diff.push_back(gas[i]-cost[i]);
        }
        if(gasSum<CostSum){
            return -1;
        }
        for(int i=0;i<gas.size();i++){
            diff.push_back(gas[i]-cost[i]);
        }
        int startIndex=0;
        int prefixSum=0;
        for(int i=0;i<diff.size();i++){
            prefixSum+=diff[i];
            if(prefixSum<0){
                prefixSum=0;
                startIndex=i+1;
            }
        }
        if(startIndex>=gas.size()){
            return -1;
        }
        return startIndex;

        
    
    }
};
int main(){

}
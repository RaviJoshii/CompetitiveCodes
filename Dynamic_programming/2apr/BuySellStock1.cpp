// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Best Time to Buy and Sell Stock
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        if(prices.size()<1) return 0;
        int leftMinima=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]-leftMinima){
                profit=max(profit,prices[i]-leftMinima);
            }
            leftMinima=min(leftMinima,prices[i]);
        }
        return profit;
    }
};

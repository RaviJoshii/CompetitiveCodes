// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Best Time to Buy and Sell Stock with Transaction Fee
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size()<1){
            return 0;
        }
        int buy=-prices[0];
        int sell=0;
        for(int i=1;i<prices.size();i++){
            int temp=buy;
            buy=max(buy,sell-prices[i]);
            sell=max(sell,temp+prices[i]-fee);
        }
        return sell;
    }
};
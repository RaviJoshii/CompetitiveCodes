// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Best Time to Buy and Sell Stock with Cooldown
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1){
            return 0;
        }
        int sell[2];
        int buy=-prices[0];
        sell[0]=0;
        sell[1]=max(sell[0],prices[1]+buy);
        buy =max(buy,-prices[1]);
        for(int i=2;i<n;i++){
            int temp=buy;
            buy=max(buy,sell[0]-prices[i]);
            sell[0]=sell[1];
            sell[1]=max(sell[1],temp+prices[i]);
        }
        return sell[1];
    }
};

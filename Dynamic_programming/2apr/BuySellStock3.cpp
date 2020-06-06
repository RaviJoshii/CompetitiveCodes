// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Best Time to Buy and Sell Stock III

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<1){
            return 0;
        }
        int profit=0;
        vector<int> arr(prices.size());
        
        //computing left to right;
        int minSoFar=prices[0];
        arr[0]=0;
        for(int i=1;i<prices.size();i++){
            arr[i]=arr[i-1];
            if(prices[i]>minSoFar){
                arr[i]=max(arr[i],prices[i]-minSoFar);
            }
            minSoFar=min(prices[i],minSoFar);   
        }
        //computing right to left;
        int prev=0;
        int maxSoFar=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            if(prices[i]<maxSoFar){
                int inc=maxSoFar-prices[i];
                arr[i]+=max(prev,inc);
                prev=max(prev,inc);
            }
            else{
                arr[i]+=prev;
            }
            maxSoFar=max(prices[i],maxSoFar);
            profit=max(profit,arr[i]);
        }
        return profit;
    }
};
int main(){
    vector<int> vec={10,15,12,20,5,12,8,21,7};
    Solution s;
    cout<<s.maxProfit(vec)<<endl;
    return 0;
}
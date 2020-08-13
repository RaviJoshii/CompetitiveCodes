// https://leetcode.com/problems/koko-eating-bananas/
// . Koko Eating Bananas
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findHours(vector<int>& piles,int k){
        int h=0;
        for(auto num : piles){
            h+=ceil((num*(1.0))/k);
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo=1;
        int hi=-1;
        for(int i=0;i<piles.size();i++){
            if(piles[i]>hi){
                hi = piles[i];
            }
        }
        int ans=0;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int hour=findHours(piles,mid);
            if(hour>H){
                lo=mid+1;
            }else if(hour<=H){
                ans=mid;
                hi=mid-1;

            }
        }
        return ans;

    }
};

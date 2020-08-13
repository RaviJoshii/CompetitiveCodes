// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Capacity To Ship Packages Within D Days
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDays(vector<int>& weight,int capacity){
        int temp=0;
        int requiredDays=1;
        for(int i=0;i<weight.size();i++){
            if(temp+weight[i]>capacity){
                temp=0;
                requiredDays++;
            } 
            temp+=weight[i];
        }
        return requiredDays;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        if(weights.size()==0){
            return 0;
        }
        int mini=weights[0];
        int maxi=weights[0];
        for(int i=1;i<weights.size();i++){
            if(weights[i]>mini){
                mini=weights[i];
            }
            maxi+=weights[i];
        }
        int ans=0;
        while(mini<=maxi){
            int mid=(mini+maxi)/2;
            int days=findDays(weights,mid);
            if(days>D){
                mini=mid+1;
            }else if(days<=D){
                maxi=mid-1;
                ans=mid;
            }
        }
        return ans;
        
    }
};
int main(){
    Solution s;
    vector<int> vec={1,2,3,1,1};
    int d=4;
    cout<<s.shipWithinDays(vec,d);
}
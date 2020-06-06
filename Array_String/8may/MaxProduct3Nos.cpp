// https://leetcode.com/problems/maximum-product-of-three-numbers/
// Maximum Product of Three Numbers

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& arr) {
        
        long long first=INT_MIN;
        long long second=INT_MIN;
        long long third=INT_MIN;
        
        long long lfirst=INT_MAX;
        long long lsecond=INT_MAX;
        for(int i=0;i<arr.size();i++){
            
            //finding to maximum 3 elements;
            if(arr[i]>first){
                third=second;
                second=first;
                first=arr[i];
                
            }else if(arr[i]>second){
                third=second;
                second=arr[i];
            }else if(arr[i]>third){
                third=arr[i];
            }
            
            //finding least 2 numbers;
            if(arr[i]<lfirst){
                lsecond=lfirst;
                lfirst=arr[i];
                
            }else if(arr[i]<lsecond){
                lsecond=arr[i];
            }
        }
        
        return max(first*second*third, first*lfirst*lsecond);
    }
};
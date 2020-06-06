// https://www.geeksforgeeks.org/minimum-number-of-increasing-subsequences/
// Minimum number of increasing subsequences (LDS)
//another way of implementing LDS in O(nlogn)
#include<bits/stdc++.h>
using namespace std;
int MinimumNumIncreasingSubsequences(vector<int> arr){
    multiset<int> dp;
    for(int i=0;i<arr.size();i++){
        auto it=dp.lower_bound(arr[i]);
        if(it==dp.begin()){
            dp.insert(arr[i]);
        }
        else{
            dp.erase(it);
            dp.insert(arr[i]);
        }
    }
    return dp.size();
}
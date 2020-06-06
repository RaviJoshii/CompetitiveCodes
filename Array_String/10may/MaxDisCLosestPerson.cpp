// https://leetcode.com/problems/maximize-distance-to-closest-person/
// Maximize Distance to Closest Person
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        if(n==0){
            return 0;
        }
        int ans=0;

        //case : 1 =  checking for first 1; 
        int i=0;
        while(seats[i]==0){
            i++;
        }
        int prev=i;
        ans=max(ans,i);


        //case :2 =   checking for last 1;
        int j=seats.size()-1;
        while(seats[j]==0){
            j--;
        }
        ans=max(ans,n-j-1);
        

        //case : 3 :   finding maximum consecutive 0s;
        int maxD=INT_MIN;
        for(int k=i;k<=j;k++){
            if(seats[k]==1){
                maxD=max(maxD,k-prev);
                prev=k;
            }
        }

        ans=max(ans,maxD/2);
        return ans;
        
    }
    
};
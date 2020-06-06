// https://leetcode.com/problems/boats-to-save-people/
// Boats to Save People
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0;
        int j=people.size()-1;
        int boats=0;
        sort(people.begin(),people.end());
        while(i<=j){
            if((people[i]+people[j])<=limit){
                i++;
                j--;
                
                //pairs considered;
                boats++;
            }
            else{
                j--;
                boats++;
            }
        }
        return boats;
    }
};
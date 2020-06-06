// https://leetcode.com/problems/container-with-most-water/
// Container With Most Water
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()==0){
            return 0;
        }
        int i=0;
        int j=height.size()-1;
        int ans=0;
        while(i<j){
            ans=max(ans,(j-i)*min(height[i],height[j]));
            if(height[i]<height[j]){
                i++;
            }
            else {
                j--;
            }
        }
        return ans;
    }
};
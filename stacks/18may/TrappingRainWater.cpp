// https://leetcode.com/problems/trapping-rain-water/
//  Trapping Rain Wate
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int leftmax=0;
        int rightmax=0;
        int ans=0;
        while(i<j){
            if(height[i]<height[j]){
                if(height[i]<leftmax){
                    ans+=(leftmax-height[i]);
                }else{
                    leftmax=height[i];
                }
                i++;
            }else{
                if(height[j]<rightmax){
                    ans+=(rightmax-height[j]);
                }else{
                    rightmax=height[j];
                }
                j--;
            }

        }
        return ans;
        
    }
};
int main(){
    Solution s;
    vector<int> vec={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(vec);
    return 0;
}
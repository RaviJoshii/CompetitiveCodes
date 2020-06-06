// https://leetcode.com/problems/pascals-triangle-ii/submissions/
// Pascal's Triangle II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        for(int i=1;i<=rowIndex;i++){
            for(int j=ans.size()-1;j>0;j--){
                ans[j]=ans[j]+ans[j-1];
            }
            ans.push_back(1);
        }
        return ans;
        
    }
};
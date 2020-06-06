// https://leetcode.com/problems/range-addition/
// https://www.lintcode.com/problem/range-addition/description

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * @param length: the length of the array
     * @param updates: update operations
     * @return: the modified array after all k operations were executed
     */
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        vector<int> res1(length,0);
        for(int i=0;i<updates.size();i++){
            int si=updates[i][0];
            int ei=updates[i][1];
            int inc=updates[i][2];
            if(si>=0 && si<length){
                res1[si]+=inc;
            }
            if(ei+1>=0 && ei+1<length){
                res1[ei+1]=res1[ei+1]-inc;
            }
            

        }
        for(int i=1;i<length;i++){
            res1[i]=res1[i-1]+res1[i];
        }
        return res1;
    }
};
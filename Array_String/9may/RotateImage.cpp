// https://leetcode.com/problems/rotate-image/
// Rotate Image
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       for(int i=0;i<matrix.size();i++){
           for(int j=0;j<matrix[0].size();j++){
               if(j>i){
                   swap(matrix[i][j],matrix[j][i]);
               }
           }
           
       }
        //reverse
        for(int i=0;i<matrix.size();i++){
            int x=0;
            int y=matrix[i].size()-1;
            while(x<y){
                swap(matrix[i][x],matrix[i][y]);
                x++;
                y--;
            }
        }
        
    }
};
// https://leetcode.com/problems/long-pressed-name/
// Long Pressed Name
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(typed.size()<name.size()){
            return false;
        }
        int i=0;
        int j=0;
        while(j<typed.size()){
            if(name[i]==typed[j]){
                i++;
                j++;
            }
            else{
                if(j==0){
                    return false;
                }
                if(typed[j]==typed[j-1]){
                    j++;
                }
                else{
                    return false;
                }
            }
        }
        if(i<(name.size())){
            return false;
        }
        return true;
    }
};
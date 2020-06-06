// https://leetcode.com/problems/valid-palindrome-ii/
// Valid Palindrome II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPalidrome(string s,int x,int y){
        while(x<y){
            if(s[x]!=s[y]){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                if(checkPalidrome(s,i,j-1)){
                    return true;
                }else{
                    return checkPalidrome(s,i+1,j);
                }
            }
            i++;
            j--;
        }
        return true;
        
    }
};
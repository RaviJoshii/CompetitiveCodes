// https://leetcode.com/problems/reverse-vowels-of-a-string/
// Reverse Vowels of a String
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isvowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
            c=='A' || c=='E'|| c=='I' || c=='O' || c=='U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i=0;int j=s.size()-1;
        while(i<j){
            while(i<s.size() && isvowel(s[i])==false && i<j){
                i++;
            }
            while(j>=0 && isvowel(s[j])==false && i<j){
                j--;
            }
            if(i<j && j>=0 && i<s.size()){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            
        }
        return s;
        
    }
};
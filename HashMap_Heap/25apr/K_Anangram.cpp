// https://practice.geeksforgeeks.org/problems/check-if-two-strings-are-k-anagrams-or-not/1
// Check if two strings are k-anagrams or not
#include<bits/stdc++.h>
using namespace std;
bool areKAnagrams(string str1, string str2, int k)
  {
      if(str1.size()!=str2.size()){
          return false;
      }
    unordered_map<int,int> umap1;
    unordered_map<int,int> umap2;
    for(int i=0;i<str1.size();i++){
        umap1[str1[i]]++;
        umap2[str2[i]]++;
    }
    int count=0;
    for(auto it:umap1){
        char chars=it.first;
        int cs1=it.second;
        int cs2=0;
        if(umap2.find(chars)!=umap2.end()){
            cs2=umap2[chars];
        }
        if(cs1>cs2){
            count+=(cs1-cs2);
        }
    }
    if(count>k){
        return false;
    }
    else{
        return true;
    }
}
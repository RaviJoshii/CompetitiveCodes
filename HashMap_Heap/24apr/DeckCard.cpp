// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
// X of a Kind in a Deck of Cards
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int gcd(int a ,int b){
        if(b==0){
            return a;
        }
       return gcd(b,a%b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        
        unordered_map<int,int> umap;
            for(int i=0;i<deck.size();i++){
                if(umap.find(deck[i])!=umap.end()){
                    umap[deck[i]]++;
                }
                else{
                    umap[deck[i]]=1;
                }
            }
        int gcd1=0;
        for(auto it:umap){
            if(gcd1==0){
                gcd1=it.second;
            }
            else{
                gcd1=gcd(it.second,gcd1);
            }
        }
        if(gcd1==1){
            return false;
        }
        else{
            return true;
        }
    }
};

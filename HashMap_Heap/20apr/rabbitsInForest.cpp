// https://leetcode.com/problems/rabbits-in-forest/
// Rabbits in Forest
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> umap;
        int ans=0;
            for(int i=0;i<answers.size();i++){
                if(umap.find(answers[i])!=umap.end()){
                    umap[answers[i]]++;
                }
                else{
                    umap[answers[i]]=1;
                }
            }
        
        for(auto it:umap){
            int size=(it.first+1);
            int groups=0;
            if((it.second)%size==0){
                groups=it.second/size;
            }
            else{
                groups=it.second/size;
                groups++;
            }
            ans+=(size*groups);
        }
        return ans;
    }
};
// https://leetcode.com/problems/frog-jump/
// Frog Jump
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones.size()<1){
            return true;
        }
        unordered_map<int,set<int>> umap;
        
        set<int> temp;
        temp.insert(1);
        umap[0]=temp;
        
        for(int i=1;i<stones.size();i++){
            set<int> temp2;
            umap[stones[i]]=temp2;
        }
        for(int i=0;i<stones.size();i++){
            
            for(int s:umap[stones[i]]){
                int reach=stones[i]+s;
                if(reach==stones[stones.size()-1]){
                    return true;
                }
                if(umap.find(reach)!=umap.end()){
                    
                    if(s-1>0){
                        umap[reach].insert(s-1);
                    }
                    umap[reach].insert(s);
                    umap[reach].insert(s+1);
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> vec={0,1,3,5,6,8,12,17};
    cout<<s.canCross(vec);
    return 0;
}
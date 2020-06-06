// https://leetcode.com/problems/insert-delete-getrandom-o1/
//  Insert Delete GetRandom O(1)
#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> umap;
    vector<int> vec;
    
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(umap.find(val)!=umap.end()){
            return false;
        }
        vec.push_back(val);
        umap[val]=vec.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(umap.find(val)==umap.end()){
            return false;
        }
        int idx=umap[val];
        int last=vec[vec.size()-1];
        vec[idx]=last;
        umap[last]=idx;
        umap.erase(val);
        vec.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand()%vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
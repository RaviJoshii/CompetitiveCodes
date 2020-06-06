// https://leetcode.com/problems/find-anagram-mappings/
// https://www.lintcode.com/problem/find-anagram-mappings/description
// Find Anagram Mappings
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * @param A: lists A
     * @param B: lists B
     * @return: the index mapping
     */
    vector<int> anagramMappings(vector<int> &A, vector<int> &B) {
        vector<int> ans;
        unordered_map<int,int> umap;
        for(int i=0;i<B.size();i++){
            umap[B[i]]=i;
        }
        for(int i=0;i<A.size();i++){
            ans.push_back(umap[A[i]]);
        }
        return ans;
    }
};
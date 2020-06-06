// https://leetcode.com/problems/distribute-coins-in-binary-tree/
#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
   
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(NULL), right(NULL) {}
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int ans=0;
    int process(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = process(root->left);
        int right = process(root->right);
        int tempans=left+right+root->val-1;
        ans+=abs(tempans);
        return tempans;
    }
    int distributeCoins(TreeNode* root) {
        process(root);
        return ans;
        
    }
};

    // https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
    // Binary Search Tree to Greater Sum Tree
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    int sum=0;
    void ReverseInorderTraversal(TreeNode* root){
        if(root==NULL){
            return;
        }
        ReverseInorderTraversal(root->right);
        
        sum+=root->val;
        root->val=sum;
        
        ReverseInorderTraversal(root->left);
        
    }
    TreeNode* bstToGst(TreeNode* root) {
        
        if(root==nullptr){
            return root;
        }
        ReverseInorderTraversal(root);
        return root;
        
        
    }
};
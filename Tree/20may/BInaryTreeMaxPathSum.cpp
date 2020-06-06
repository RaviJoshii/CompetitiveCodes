// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Binary Tree Maximum Path Sum
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
    int ans=INT_MIN;//global variale
    int nodeToNodeMaxSum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftsum=nodeToNodeMaxSum(root->left);
        int rightSum=nodeToNodeMaxSum(root->right);
        
        int maxBranch=max(leftsum,rightSum);

        //updating ans;
        ans=max(max(ans,root->val),
                    max(leftsum+rightSum+root->val,maxBranch+root->val));
        

        //return impact
        return max(maxBranch+root->val,root->val);

    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        nodeToNodeMaxSum(root);
        return ans;
        
        
    }
};
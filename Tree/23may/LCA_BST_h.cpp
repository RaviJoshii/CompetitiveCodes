// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Lowest Common Ancestor of a Binary Search Tree
#include<bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {   
        if(root==NULL){
            return NULL;
        }  
        if(p->val < root->val && q->val <root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(p->val > root->val && q->val >root->val){
            return lowestCommonAncestor(root->right,p,q);
        }else 
        {  
            // if((p->val < root->val && q->val >root->val) && (p->val > root->val && q->val < root->val))
            return root;
        }
    }
};
int main(){
    return 0;

}
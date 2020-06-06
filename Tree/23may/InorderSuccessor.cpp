// https://www.lintcode.com/problem/inorder-successor-in-bst/description
// Inorder Successor in BST

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
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode* ans=NULL;
    void process(TreeNode *node,TreeNode *p){
        if(node==NULL){
            return;
        }
       if(node->val==p->val){
           if(node->right==NULL){
               return;
           }else {
               //have right child
                ans=node->right;
                //finding leftmost
                while (ans->left!=NULL)
                {
                    ans=ans->left;
                }
                return;
           }
       }
       if(node->val>p->val){
           ans=node;//updating the last left turn node
           process(node->left,p);
       }else{
           process(node->right,p);
       }
    }
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        if(root==NULL){
            return root;
        }
        process(root,p);
        return ans;
    }
};
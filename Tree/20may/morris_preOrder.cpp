// https://leetcode.com/problems/binary-tree-preorder-traversal/
//  Binary Tree Preorder Traversal
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
   
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr=root;
        while(curr!=NULL){
           
            if(curr->left==NULL){
                 ans.push_back(curr->val);
                curr=curr->right;                
            }else{
                //finding predecessor
                TreeNode* currp1=curr->left;
                while(currp1->right!=NULL && currp1->right!=curr){
                    currp1=currp1->right;
                }
                if(currp1->right==NULL){
                     ans.push_back(curr->val);
                    currp1->right=curr;
                    curr=curr->left;
                }else{
                    //resetting the path
                    currp1->right=NULL;
                    curr=curr->right;//---important line
                }
                
            }
        }
        return ans;
        
    }
};

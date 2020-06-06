// https://leetcode.com/problems/delete-node-in-a-bst/
// Delete Node in a BST

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val==key){
            if(root->left==NULL && root->right==NULL){
                delete(root);
                return NULL;
            }else if(root->left==NULL && root->right!=NULL){
                return root->right;
            }else if(root->left!=NULL && root->right==NULL){
                return root->left;
            }else{
                //2 child
                //finding leftmost element in right subtree;
                TreeNode *temp=root->right;
                TreeNode *temp2=root->right;
                while(temp->left!=NULL){
                    temp=temp->left;
                }
                //accomadate/shift the left subtree of root;
                temp->left=root->left;
                delete(root);
                return temp2;
            }
        }
        root->left=deleteNode(root->left,key);
        root->right=deleteNode(root->right,key);
        return root;
    }
};
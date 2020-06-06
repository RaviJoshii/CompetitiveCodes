// https://leetcode.com/problems/boundary-of-binary-tree/
// https://www.lintcode.com/problem/boundary-of-binary-tree/note/183903
// https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
// Boundary Traversal of binary tree
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
    /**
     * @param root: a TreeNode
     * @return: a list of integer
     */
    vector<int> ans;
    void printBoundaryLeft(TreeNode* root) 
    { 
        if (root == NULL) 
        {   
            return;
        } 
        if(root->left==NULL && root->right==NULL){
            return;
        }

        ans.push_back(root->val);

        if (root->left) { 
    
            printBoundaryLeft(root->left); 
        } 
        else if(root->right){ 
            printBoundaryLeft(root->right); 
        } 
    }
    void printBoundaryRight(TreeNode* root) 
    { 
        if (root == NULL) 
            return; 
        
        if(root->left==NULL && root->right==NULL){
            return;
        }
        
    
        if (root->right) { 
            printBoundaryRight(root->right); 
        } 
        else if (root->left) { 
            printBoundaryRight(root->left); 
        } 
        ans.push_back(root->val);
    } 
  
    void printLeaves(TreeNode* root) 
    { 
        if (root == NULL) 
            return; 
    
        printLeaves(root->left); 
    
        // Print it if it is a leaf node 
        if (root->left==NULL && root->right==NULL) 
        { ans.push_back(root->val);
        }
    
        printLeaves(root->right); 
    } 
    vector<int> boundaryOfBinaryTree(TreeNode * root) {
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->val);
        
        // Print the left boundary in top-down manner. -- in preorder form
        printBoundaryLeft(root->left); 
    
        // Print all leaf nodes 
        printLeaves(root->left); 
        printLeaves(root->right); 
    
        // Print the right boundary in bottom-up manner  - in post order form
        printBoundaryRight(root->right);
        return ans;
        
    }
};

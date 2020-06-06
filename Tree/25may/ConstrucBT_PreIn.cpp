// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Construct Binary Tree from Preorder and Inorder Traversal
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
    unordered_map<int,int> umap;
    TreeNode* process(vector<int>& preorder, vector<int>& inorder,int psi,int pei,int isi,int iei){
        if(psi>pei || isi>iei){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[psi]);
        int idx=umap[preorder[psi]];
        int counts=idx-isi;
        root->left=process(preorder,inorder,psi+1,psi+counts,isi,idx-1);
        root->right=process(preorder,inorder,psi+counts+1,pei,idx+1,iei);
        return root;

        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //preparing map;
        for(int i=0;i<inorder.size();i++){
            umap[inorder[i]]=i;
        }
        return process(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);

        
    }
};
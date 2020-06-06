// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* process(vector<int>& postorder, vector<int>& inorder,int psi,int pei,int isi,int iei){
        if(psi>pei || isi>iei){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[pei]);
        int idx=umap[postorder[pei]];
        int counts=iei-idx;
        root->left=process(postorder,inorder,psi,pei-counts-1,isi,idx-1);
        root->right=process(postorder,inorder,pei-counts,pei-1,idx+1,iei);
        return root;

        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //preparing map;
        for(int i=0;i<inorder.size();i++){
            umap[inorder[i]]=i;
        }
        return process(postorder,inorder,0,postorder.size()-1,0,inorder.size()-1);
        
    }
};
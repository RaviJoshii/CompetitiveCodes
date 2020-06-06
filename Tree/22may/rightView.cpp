// https://leetcode.com/problems/binary-tree-right-side-view/
// Binary Tree Right Side View


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
    vector<int> rightSideView(TreeNode* root) {
        list<TreeNode*> que;
        vector<int> ans;
        if(root==nullptr){
            return ans;
        }
        que.push_back(root);
        while(que.size()!=0){
            int sizes=que.size();
            bool flag=true;
            int tempans;
            while(sizes-- >0){
                TreeNode* rem=que.front();
                que.pop_front();
                tempans=rem->val;
                
                
                if(rem->left!=nullptr){
                    que.push_back(rem->left);
                }
                if(rem->right!=nullptr){
                    que.push_back(rem->right);
                }
                
            }
            ans.push_back(tempans);
            
        }
        return ans;
        
    }
};